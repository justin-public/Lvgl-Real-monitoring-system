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

   if((mcu_freq_mhz * 8) <= RCC_MAX_VCO_INPUT_FREQ)
   {
     return 8;
   }
   else if((mcu_freq_mhz * 6) <= RCC_MAX_VCO_INPUT_FREQ)
   {
     return 6;
   }
   else if((mcu_freq_mhz * 4) <= RCC_MAX_VCO_INPUT_FREQ)
   {
     return 4;
   }
}

