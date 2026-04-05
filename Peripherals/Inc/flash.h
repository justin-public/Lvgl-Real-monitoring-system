/*
 * flash.h
 *
 *  MCU의 내부 플래시 메모리를 구성하기 위한 기능 프로토타입을 제공 합니다.
 */

#ifndef INC_FLASH_H_
#define INC_FLASH_H_

#include "mcu.h"

void flash_config_wait_states(uint8_t hclk);

#endif /* INC_FLASH_H_ */
