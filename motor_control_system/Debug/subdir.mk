################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CLCD_program.c \
../DCMOTOR_program.c \
../DIO_program.c \
../KEYPAD_program.c \
../PORT_program.c \
../STEPPER_program.c \
../main.c 

OBJS += \
./CLCD_program.o \
./DCMOTOR_program.o \
./DIO_program.o \
./KEYPAD_program.o \
./PORT_program.o \
./STEPPER_program.o \
./main.o 

C_DEPS += \
./CLCD_program.d \
./DCMOTOR_program.d \
./DIO_program.d \
./KEYPAD_program.d \
./PORT_program.d \
./STEPPER_program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


