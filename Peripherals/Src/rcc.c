/*
 * rcc.c
 *
 * RCC 초기화 및 검증에 필요한 함수 정의 포함
 */
#include "rcc.h"
#include "flash.h"

/*
 * 대상 시스템 클럭 주파수를 기반으로 최적의 PLLP 값을 계산하고 반환
 * @param mcu_freq_mhz 타켓 시스템 클록 주파수 MHz
 * @return pllp 분할 계수 반환
 */

static uint8_t rcc_get_pllp(uint8_t mcu_freq_mhz)
{
  if((mcu_freq_mhz * 8) <= RCC_MAX_VCO_FREQ)     // 최대 VCO 주파수를 초과 하지 않으면 pllp로 8을 반환
  {
      return 8;
  }
  else if((mcu_freq_mhz * 6) <= RCC_MAX_VCO_FREQ)
  {
      return 6;
  }
  else if((mcu_freq_mhz * 4) <= RCC_MAX_VCO_FREQ)
  {
      return 4;
  }
  else
  {
     return 2;
  }
}

/*
 * PLL의 PLLM, PLLN, PLLP 값을 설정합니다. PLLM은 미리 정의된 HSE를 기반으로 설정됩니다.
 * PLLN과 PLLP는 PLL 입력 주파수를 기반으로 원하는 시스템 클럭 주파수를 달성하기 위해 계산 됩니다.
 * @param sysclk_freq_mhz : MHz 단위의 원하는 클럭 주파수
 */

static void rcc_pll_config(uint8_t sysclk_freq_mhz)
{
  uint8_t PLLP = 0;            // 8비트
  uint16_t PLLN = 0;           // PLLN은 현재 336 까지 설정 가능 , 16비트 설정

  if(sysclk_freq_mhz > RCC_MAX_SYSCLK_MHZ)      // 최대 시스템 클록 주파수(168MHz) 범위 초과를 제한 하기 위한 처리
  {
    sysclk_freq_mhz = RCC_MAX_SYSCLK_MHZ;
  }

  PLLP = rcc_get_pllp(sysclk_freq_mhz);             // 원하는 PLLP 디바이더 값을 추출
  PLLN = sysclk_freq_mhz * PLLP;

  // PLLM 설정
  // PLLM 파라미터는 RCC_HSE_MHZ 정의값을 사용
  uint8_t PLLM = RCC_HSE_MHZ;
  RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLM);
  RCC->PLLCFGR |= PLLM << RCC_PLLCFGR_PLLM_Pos;

  // PLLN 설정
  RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLN);
  RCC->PLLCFGR |= PLLN << RCC_PLLCFGR_PLLN_Pos;

  PLLP = (PLLP / 2) - 1;
  RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLP);
  RCC->PLLCFGR |= PLLP << RCC_PLLCFGR_PLLP_Pos;
}

void rcc_init(void)
{
  // RCC 초기화
  // 시스템 클록 주파수를 설정하고, 웨이트 스테이트를 구성하고,
  // HSE를 활성화 하고, PLL을 시스템 클록 소스로 구성하고,
  // HSI를 비활성화하기 전에 PLL 클럭이 안정화될 때까지 대기하고, 클록 프리스케일러를 설정 합니다.
  uint8_t sysclk_freq_mhz = RCC_MAX_SYSCLK_MHZ;

  // 1. 플래시 웨이트 스테이트를 구성합니다. (sysclk_freq_mhz --> AHB 분주비 1 사용)
  flash_config_wait_states(sysclk_freq_mhz);

  rcc_hse_enable();

  rcc_pll_source(RCC_PLL_SRC_HSE);

  // PLL 파라미터를 계산하여 원하는 시스템 클록 주파수를 설정
  rcc_pll_config(sysclk_freq_mhz);

  rcc_pll_enable();

  rcc_ahb_set_prescaler(RCC_SYSCLK_DIV_1);

  rcc_sysclk_set_source(RCC_SYSCLK_SRC_PLLP);

  while(RCC_CFGR_SWS_PLL != rcc_sysclk_get_source());

  rcc_hsi_disable();

  rcc_apb1_set_prescaler(RCC_APB1_DIV_4);
  rcc_apb2_set_prescaler(RCC_APB2_DIV_2);
}

uint32_t rcc_get_sysclk_freq(void)
{
  uint32_t pllm = 0U, pllvco = 0U, pllp = 0U;
  uint32_t sysclck_freq = 0u;

  switch (RCC->CFGR & RCC_CFGR_SWS)
  {
    case RCC_CFGR_SWS_HSI:
      sysclck_freq = RCC_HSI_FREQ;    /* HSI used as system clock source */
      break;

    case RCC_CFGR_SWS_HSE:
      sysclck_freq = RCC_HSE_FREQ;    /* HSE used as system clock  source */
      break;

    case RCC_CFGR_SWS_PLL:            /* PLL used as system clock  source */
      // PLL_VCO = (HSE_VALUE or HSI_VALUE / PLLM) * PLLN
      // SYSCLK  = PLL_VCO / PLLP
      pllm = RCC->PLLCFGR & RCC_PLLCFGR_PLLM;

      if (RCC_GET_PLL_OSCSOURCE() != RCC_PLLCFGR_PLLSRC_HSI)
      {
        /* HSE used as PLL clock source */
        pllvco = (uint32_t) ((((uint64_t) RCC_HSE_FREQ * ((uint64_t) ((RCC->PLLCFGR & RCC_PLLCFGR_PLLN) >> RCC_PLLCFGR_PLLN_Pos)))) / (uint64_t) pllm);
      }
      else
      {
        /* HSI used as PLL clock source */
        pllvco = (uint32_t) ((((uint64_t) RCC_HSI_FREQ *((uint64_t) ((RCC->PLLCFGR & RCC_PLLCFGR_PLLN) >> RCC_PLLCFGR_PLLN_Pos)))) / (uint64_t) pllm);
      }
      pllp = ((((RCC->PLLCFGR & RCC_PLLCFGR_PLLP) >> RCC_PLLCFGR_PLLP_Pos) + 1U) * 2U);

      sysclck_freq = pllvco / pllp;
      break;

    default:
      sysclck_freq = RCC_HSI_FREQ;
      break;
  }

  return sysclck_freq;
}

uint32_t rcc_get_hclk_freq(void)
{
  uint32_t sysclk = rcc_get_sysclk_freq();
  uint32_t hclk_div = RCC_GET_HCLK_DIV();

  /* Interpret hclk_div as actual divisor */
  if (hclk_div >= 8)
  {
    hclk_div = 1 << (hclk_div - 7);
  }
  else
  {
      hclk_div = 1; // prescaler is 1
  }

  return sysclk / hclk_div;
}

uint32_t rcc_get_pclk1_freq(void)
{
  uint32_t hclk = rcc_get_hclk_freq();
  uint32_t pclk1_div = RCC_GET_PCLK1_DIV();

  /* Interpret pclk1_div as actual divisor */
  if (pclk1_div >= 4)
  {
    pclk1_div = 1 << (pclk1_div - 3);
  }
  else
  {
    pclk1_div = 1;
  }

  return hclk / pclk1_div;
}

uint32_t rcc_get_pclk2_freq(void)
{
  uint32_t hclk = rcc_get_hclk_freq();
  uint32_t pclk2_div = RCC_GET_PCLK2_DIV();

  /* Interpret pclk2_div as actual divisor */
  if (pclk2_div >= 4)
  {
    pclk2_div = 1 << (pclk2_div - 3);
  }
  else
  {
    pclk2_div = 1;
  }

  return hclk / pclk2_div;
}
