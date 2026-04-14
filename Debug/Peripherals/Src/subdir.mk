################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Peripherals/Src/flash.c \
../Peripherals/Src/rcc.c 

OBJS += \
./Peripherals/Src/flash.o \
./Peripherals/Src/rcc.o 

C_DEPS += \
./Peripherals/Src/flash.d \
./Peripherals/Src/rcc.d 


# Each subdirectory must supply rules for building sources it contributes
Peripherals/Src/%.o Peripherals/Src/%.su Peripherals/Src/%.cyclo: ../Peripherals/Src/%.c Peripherals/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -c -I"C:/Dev/stm32_rtos_project/workspace/RTOS-407/CMSIS" -I"C:/Dev/stm32_rtos_project/workspace/RTOS-407/Peripherals/Inc" -I"C:/Dev/stm32_rtos_project/workspace/RTOS-407/Middleware/ThirdParty/FreeRTOS/Source/include" -I"C:/Dev/stm32_rtos_project/workspace/RTOS-407/Middleware/ThirdParty/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"C:/Dev/stm32_rtos_project/workspace/RTOS-407/Core/Inc" -I"C:/Dev/stm32_rtos_project/workspace/RTOS-407/Config" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Peripherals-2f-Src

clean-Peripherals-2f-Src:
	-$(RM) ./Peripherals/Src/flash.cyclo ./Peripherals/Src/flash.d ./Peripherals/Src/flash.o ./Peripherals/Src/flash.su ./Peripherals/Src/rcc.cyclo ./Peripherals/Src/rcc.d ./Peripherals/Src/rcc.o ./Peripherals/Src/rcc.su

.PHONY: clean-Peripherals-2f-Src

