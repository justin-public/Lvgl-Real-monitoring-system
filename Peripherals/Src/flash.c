/*
 * flash.c
 *
 *  MCU의 내부 플래시 메모리를 구성하기 위한 함수 정의를 포함
 */

#include "flash.h"

void flash_config_wait_states(uint8_t hclk)
{
  // Flash Access control register 초기화 bit clear
  FLASH->ACR &= ~(FLASH_ACR_LATENCY | FLASH_ACR_PRFTEN | FLASH_ACR_ICEN |
              FLASH_ACR_DCEN | FLASH_ACR_ICRST | FLASH_ACR_DCRST);
  FLASH->ACR |= (FLASH_ACR_DCEN | FLASH_ACR_ICEN | FLASH_ACR_PRFTEN);

  // Calcurate the latency based on the hclk value
  uint32_t latency = (hclk -1) / 30;   // Round up to the nearest multiple integer of 30

  // Set the FLASH_ACR_LATENCY based on the latency calculated
  FLASH->ACR |= (latency << FLASH_ACR_LATENCY_Pos);
}



