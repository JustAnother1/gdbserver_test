################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/gdbserver/commands.c \
../src/gdbserver/gdbserver.c \
../src/gdbserver/util.c 

C_DEPS += \
./src/gdbserver/commands.d \
./src/gdbserver/gdbserver.d \
./src/gdbserver/util.d 

OBJS += \
./src/gdbserver/commands.o \
./src/gdbserver/gdbserver.o \
./src/gdbserver/util.o 


# Each subdirectory must supply rules for building sources it contributes
src/gdbserver/%.o: ../src/gdbserver/%.c src/gdbserver/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/lars/eclipse/workspace_embeddedC/mbsp_gdbserver/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-gdbserver

clean-src-2f-gdbserver:
	-$(RM) ./src/gdbserver/commands.d ./src/gdbserver/commands.o ./src/gdbserver/gdbserver.d ./src/gdbserver/gdbserver.o ./src/gdbserver/util.d ./src/gdbserver/util.o

.PHONY: clean-src-2f-gdbserver

