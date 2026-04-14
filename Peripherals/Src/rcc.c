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

































