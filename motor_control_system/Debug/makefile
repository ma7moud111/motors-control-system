################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
motor_control_system.lss \

FLASH_IMAGE += \
motor_control_system.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: motor_control_system.elf secondary-outputs

# Tool invocations
motor_control_system.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,motor_control_system.map -mmcu=atmega32 -o "motor_control_system.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

motor_control_system.lss: motor_control_system.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S motor_control_system.elf  >"motor_control_system.lss"
	@echo 'Finished building: $@'
	@echo ' '

motor_control_system.hex: motor_control_system.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex motor_control_system.elf  "motor_control_system.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: motor_control_system.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 motor_control_system.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) motor_control_system.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
