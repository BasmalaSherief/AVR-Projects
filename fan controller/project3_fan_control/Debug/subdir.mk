################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_driver.c \
../DC-motor_driver.c \
../LCD_Driver.c \
../LM35_driver.c \
../PWM_driver.c \
../gpio_driver.c \
../project3_fan_control.c 

OBJS += \
./ADC_driver.o \
./DC-motor_driver.o \
./LCD_Driver.o \
./LM35_driver.o \
./PWM_driver.o \
./gpio_driver.o \
./project3_fan_control.o 

C_DEPS += \
./ADC_driver.d \
./DC-motor_driver.d \
./LCD_Driver.d \
./LM35_driver.d \
./PWM_driver.d \
./gpio_driver.d \
./project3_fan_control.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


