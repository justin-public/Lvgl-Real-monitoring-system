
/*
 * Application 진입 지점
 */
#include "mcu.h"
#include "FreeRTOSConfig.h"
#include "FreeRTOSTasks.h"

static void startup(void);

int main(void)
{
  // Update the 'SystemCoreClock' Variable required by FreeRTOS
  SystemCoreClockUpdate();

  // Create the startup task
  startup();

  // Start the FreeRTOS scheduler
  vTaskStartScheduler();

  while(1)
  {

  }
}

static void startup_task(void *param)
{
  vTaskDelete(NULL);
}

/*
 * Create the startup task.
 */
static void startup(void)
{
  configASSERT(pdPASS == xTaskCreate(startup_task,"Startup_Task",STARTUP_TASK_STACK_SIZE, NULL, STARTUP_TASK_PRIORITY, NULL));
}
