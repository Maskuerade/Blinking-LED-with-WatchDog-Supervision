################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c 

OBJS += \
./src/main.o 

C_DEPS += \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\ayaey\Desktop\y\Blinking-LED-with-WatchDog-Supervision\LED" -I"C:\Users\ayaey\Desktop\y\Blinking-LED-with-WatchDog-Supervision\WDGDRV" -I"C:\Users\ayaey\Desktop\y\Blinking-LED-with-WatchDog-Supervision\GPIO" -I"C:\Users\ayaey\Desktop\y\Blinking-LED-with-WatchDog-Supervision\WDGM" -I"C:\Users\ayaey\Desktop\y\Blinking-LED-with-WatchDog-Supervision\src" -I"C:\Users\ayaey\Desktop\y\Blinking-LED-with-WatchDog-Supervision\Timer" -Wall -g2 -gstabs -O1 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


