################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LED/LED.c 

OBJS += \
./LED/LED.o 

C_DEPS += \
./LED/LED.d 


# Each subdirectory must supply rules for building sources it contributes
LED/%.o: ../LED/%.c LED/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\Eng Habeba\Music\final_project\LED" -I"C:\Users\Eng Habeba\Music\final_project\WDGDRV" -I"C:\Users\Eng Habeba\Music\final_project\GPIO" -I"C:\Users\Eng Habeba\Music\final_project\WDGM" -I"C:\Users\Eng Habeba\Music\final_project\src" -I"C:\Users\Eng Habeba\Music\final_project\Timer" -Wall -g2 -gstabs -O1 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


