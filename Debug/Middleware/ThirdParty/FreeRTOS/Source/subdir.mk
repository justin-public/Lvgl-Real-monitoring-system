################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middleware/ThirdParty/FreeRTOS/Source/croutine.c \
../Middleware/ThirdParty/FreeRTOS/Source/event_groups.c \
../Middleware/ThirdParty/FreeRTOS/Source/list.c \
../Middleware/ThirdParty/FreeRTOS/Source/queue.c \
../Middleware/ThirdParty/FreeRTOS/Source/stream_buffer.c \
../Middleware/ThirdParty/FreeRTOS/Source/tasks.c \
../Middleware/ThirdParty/FreeRTOS/Source/timers.c 

OBJS += \
./Middleware/ThirdParty/FreeRTOS/Source/croutine.o \
./Middleware/ThirdParty/FreeRTOS/Source/event_groups.o \
./Middleware/ThirdParty/FreeRTOS/Source/list.o \
./Middleware/ThirdParty/FreeRTOS/Source/queue.o \
./Middleware/ThirdParty/FreeRTOS/Source/stream_buffer.o \
./Middleware/ThirdParty/FreeRTOS/Source/tasks.o \
./Middleware/ThirdParty/FreeRTOS/Source/timers.o 

C_DEPS += \
./Middleware/ThirdParty/FreeRTOS/Source/croutine.d \
./Middleware/ThirdParty/FreeRTOS/Source/event_groups.d \
./Middleware/ThirdParty/FreeRTOS/Source/list.d \
./Middleware/ThirdParty/FreeRTOS/Source/queue.d \
./Middleware/ThirdParty/FreeRTOS/Source/stream_buffer.d \
./Middleware/ThirdParty/FreeRTOS/Source/tasks.d \
./Middleware/ThirdParty/FreeRTOS/Source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
Middleware/ThirdParty/FreeRTOS/Source/%.o Middleware/ThirdParty/FreeRTOS/Source/%.su Middleware/ThirdParty/FreeRTOS/Source/%.cyclo: ../Middleware/ThirdParty/FreeRTOS/Source/%.c Middleware/ThirdParty/FreeRTOS/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -c -I"C:/Dev/stm32_rtos_project/workspace/RTOS-407/CMSIS" -I"C:/Dev/stm32_rtos_project/workspace/RTOS-407/Peripherals/Inc" -I"C:/Dev/stm32_rtos_project/workspace/RTOS-407/Middleware/ThirdParty/FreeRTOS/Source/include" -I"C:/Dev/stm32_rtos_project/workspace/RTOS-407/Middleware/ThirdParty/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"C:/Dev/stm32_rtos_project/workspace/RTOS-407/Core/Inc" -I"C:/Dev/stm32_rtos_project/workspace/RTOS-407/Config" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middleware-2f-ThirdParty-2f-FreeRTOS-2f-Source

clean-Middleware-2f-ThirdParty-2f-FreeRTOS-2f-Source:
	-$(RM) ./Middleware/ThirdParty/FreeRTOS/Source/croutine.cyclo ./Middleware/ThirdParty/FreeRTOS/Source/croutine.d ./Middleware/ThirdParty/FreeRTOS/Source/croutine.o ./Middleware/ThirdParty/FreeRTOS/Source/croutine.su ./Middleware/ThirdParty/FreeRTOS/Source/event_groups.cyclo ./Middleware/ThirdParty/FreeRTOS/Source/event_groups.d ./Middleware/ThirdParty/FreeRTOS/Source/event_groups.o ./Middleware/ThirdParty/FreeRTOS/Source/event_groups.su ./Middleware/ThirdParty/FreeRTOS/Source/list.cyclo ./Middleware/ThirdParty/FreeRTOS/Source/list.d ./Middleware/ThirdParty/FreeRTOS/Source/list.o ./Middleware/ThirdParty/FreeRTOS/Source/list.su ./Middleware/ThirdParty/FreeRTOS/Source/queue.cyclo ./Middleware/ThirdParty/FreeRTOS/Source/queue.d ./Middleware/ThirdParty/FreeRTOS/Source/queue.o ./Middleware/ThirdParty/FreeRTOS/Source/queue.su ./Middleware/ThirdParty/FreeRTOS/Source/stream_buffer.cyclo ./Middleware/ThirdParty/FreeRTOS/Source/stream_buffer.d ./Middleware/ThirdParty/FreeRTOS/Source/stream_buffer.o ./Middleware/ThirdParty/FreeRTOS/Source/stream_buffer.su ./Middleware/ThirdParty/FreeRTOS/Source/tasks.cyclo ./Middleware/ThirdParty/FreeRTOS/Source/tasks.d ./Middleware/ThirdParty/FreeRTOS/Source/tasks.o ./Middleware/ThirdParty/FreeRTOS/Source/tasks.su ./Middleware/ThirdParty/FreeRTOS/Source/timers.cyclo ./Middleware/ThirdParty/FreeRTOS/Source/timers.d ./Middleware/ThirdParty/FreeRTOS/Source/timers.o ./Middleware/ThirdParty/FreeRTOS/Source/timers.su

.PHONY: clean-Middleware-2f-ThirdParty-2f-FreeRTOS-2f-Source

