################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../app/src/Display_Menu.c \
../app/src/Leer_Encoder.c \
../app/src/app.c 

OBJS += \
./app/src/Display_Menu.o \
./app/src/Leer_Encoder.o \
./app/src/app.o 

C_DEPS += \
./app/src/Display_Menu.d \
./app/src/Leer_Encoder.d \
./app/src/app.d 


# Each subdirectory must supply rules for building sources it contributes
app/src/%.o app/src/%.su app/src/%.cyclo: ../app/src/%.c app/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../app/inc -I../app/display -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-app-2f-src

clean-app-2f-src:
	-$(RM) ./app/src/Display_Menu.cyclo ./app/src/Display_Menu.d ./app/src/Display_Menu.o ./app/src/Display_Menu.su ./app/src/Leer_Encoder.cyclo ./app/src/Leer_Encoder.d ./app/src/Leer_Encoder.o ./app/src/Leer_Encoder.su ./app/src/app.cyclo ./app/src/app.d ./app/src/app.o ./app/src/app.su

.PHONY: clean-app-2f-src

