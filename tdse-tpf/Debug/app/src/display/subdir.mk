################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../app/src/display/ssd1306.c \
../app/src/display/ssd1306_fonts.c \
../app/src/display/ssd1306_tests.c 

OBJS += \
./app/src/display/ssd1306.o \
./app/src/display/ssd1306_fonts.o \
./app/src/display/ssd1306_tests.o 

C_DEPS += \
./app/src/display/ssd1306.d \
./app/src/display/ssd1306_fonts.d \
./app/src/display/ssd1306_tests.d 


# Each subdirectory must supply rules for building sources it contributes
app/src/display/%.o app/src/display/%.su app/src/display/%.cyclo: ../app/src/display/%.c app/src/display/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../app/inc -I../app/display -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-app-2f-src-2f-display

clean-app-2f-src-2f-display:
	-$(RM) ./app/src/display/ssd1306.cyclo ./app/src/display/ssd1306.d ./app/src/display/ssd1306.o ./app/src/display/ssd1306.su ./app/src/display/ssd1306_fonts.cyclo ./app/src/display/ssd1306_fonts.d ./app/src/display/ssd1306_fonts.o ./app/src/display/ssd1306_fonts.su ./app/src/display/ssd1306_tests.cyclo ./app/src/display/ssd1306_tests.d ./app/src/display/ssd1306_tests.o ./app/src/display/ssd1306_tests.su

.PHONY: clean-app-2f-src-2f-display

