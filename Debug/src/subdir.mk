################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/mbsp_gdbserver.c 

C_DEPS += \
./src/mbsp_gdbserver.d 

OBJS += \
./src/mbsp_gdbserver.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/lars/eclipse/workspace_embeddedC/mbsp_gdbserver/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/mbsp_gdbserver.d ./src/mbsp_gdbserver.o

.PHONY: clean-src

