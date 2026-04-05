################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middleware/ThirdParty/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.c 

OBJS += \
./Middleware/ThirdParty/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.o 

C_DEPS += \
./Middleware/ThirdParty/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.d 


# Each subdirectory must supply rules for building sources it contributes
Middleware/ThirdParty/FreeRTOS/Source/portable/GCC/ARM_CM4F/%.o Middleware/ThirdParty/FreeRTOS/Source/portable/GCC/ARM_CM4F/%.su Middleware/ThirdParty/FreeRTOS/Source/portable/GCC/ARM_CM4F/%.cyclo: ../Middleware/ThirdParty/FreeRTOS/Source/portable/GCC/ARM_CM4F/%.c Middleware/ThirdParty/FreeRTOS/Source/portable/GCC/ARM_CM4F/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -c -I"C:/Dev/stm32_rtos_project/workspace/RTOS-407/CMSIS" -I"C:/Dev/stm32_rtos_project/workspace/RTOS-407/Peripherals/Inc" -I"C:/Dev/stm32_rtos_project/workspace/RTOS-407/Middleware/ThirdParty/FreeRTOS/Source/include" -I"C:/Dev/stm32_rtos_project/workspace/RTOS-407/Middleware/ThirdParty/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"C:/Dev/stm32_rtos_project/workspace/RTOS-407/Core/Inc" -I"C:/Dev/stm32_rtos_project/workspace/RTOS-407/Config" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middleware-2f-ThirdParty-2f-FreeRTOS-2f-Source-2f-portable-2f-GCC-2f-ARM_CM4F

clean-Middleware-2f-ThirdParty-2f-FreeRTOS-2f-Source-2f-portable-2f-GCC-2f-ARM_CM4F:
	-$(RM) ./Middleware/ThirdParty/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.cyclo ./Middleware/ThirdParty/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.d ./Middleware/ThirdParty/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.o ./Middleware/ThirdParty/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.su

.PHONY: clean-Middleware-2f-ThirdParty-2f-FreeRTOS-2f-Source-2f-portable-2f-GCC-2f-ARM_CM4F

