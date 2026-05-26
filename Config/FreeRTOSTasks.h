/*
 * FreeRTOSTasks.h
 *
 *  FreeRTOS 태스크의 정의를 포함하며, 스택 크기와 실행 우선 순위를 설정 합니다.
 *  이 파일은 전체 시스템 설계에서 관리의 편의성과 명롹성을 위해 태스크 구성을 중앙화 합니다.
 *      Author: emine
 */

#ifndef FREERTOSTASKS_H_
#define FREERTOSTASKS_H_

#include "FreeRTOS.h"
#include "task.h"

/*
 *  시작(startup) 태스크는 시스템 구성 요소를 초기화하고
 *  정상 운영 태스크로의 전환을 원할하게 하기 위해 설계되었습니다.
 *  스택 크기 512는 프로토타이핑 목적으로 설정된 값이며,
 *  실제 초기화 루틴의 요구사항에 따라 최적화되어야 합니다.
 *  신속한 시스템 초기화를 보장하기 위해 높은 우선 순위 (여기서 정의된 태스크 중 가장 높은 우선순위)
 *  가 부여됩니다.
 *  단, 이 태스크는 완료 시 스스로를 삭제합니다.
 */
#define STARTUP_TASK_STACK_SIZE       (512)
#define STARTUP_TASK_PRIORITY         (configMAX_PRIORITIES - 1)

#endif /* FREERTOSTASKS_H_ */
