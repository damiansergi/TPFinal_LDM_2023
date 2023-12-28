################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/App.c \
../source/PIT.c \
../source/Queue.c \
../source/fsm.c \
../source/fsmtable.c \
../source/gpio.c \
../source/uart.c 

OBJS += \
./source/App.o \
./source/PIT.o \
./source/Queue.o \
./source/fsm.o \
./source/fsmtable.o \
./source/gpio.o \
./source/uart.o 

C_DEPS += \
./source/App.d \
./source/PIT.d \
./source/Queue.d \
./source/fsm.d \
./source/fsmtable.d \
./source/gpio.d \
./source/uart.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_MK64FN1M0VLL12 -D__USE_CMSIS -DDEBUG -I../source -I../ -I../SDK/CMSIS -I../SDK/startup -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


