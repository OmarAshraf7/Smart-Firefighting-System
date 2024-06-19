################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App.c \
../USART.c \
../adc.c \
../buzzer.c \
../gpio.c \
../lcd.c \
../led.c \
../mq135.c \
../timer1.c \
../water_pump.c 

OBJS += \
./App.o \
./USART.o \
./adc.o \
./buzzer.o \
./gpio.o \
./lcd.o \
./led.o \
./mq135.o \
./timer1.o \
./water_pump.o 

C_DEPS += \
./App.d \
./USART.d \
./adc.d \
./buzzer.d \
./gpio.d \
./lcd.d \
./led.d \
./mq135.d \
./timer1.d \
./water_pump.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


