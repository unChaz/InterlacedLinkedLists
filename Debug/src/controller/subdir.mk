################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/controller/ApplicationController.cpp \
../src/controller/FileController.cpp \
../src/controller/main.cpp 

OBJS += \
./src/controller/ApplicationController.o \
./src/controller/FileController.o \
./src/controller/main.o 

CPP_DEPS += \
./src/controller/ApplicationController.d \
./src/controller/FileController.d \
./src/controller/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/controller/%.o: ../src/controller/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


