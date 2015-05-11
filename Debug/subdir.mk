################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Statistics.cpp \
../hw1.cpp \
../library1.cpp \
../main.cpp \
../main1.cpp 

OBJS += \
./Statistics.o \
./hw1.o \
./library1.o \
./main.o \
./main1.o 

CPP_DEPS += \
./Statistics.d \
./hw1.d \
./library1.d \
./main.d \
./main1.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


