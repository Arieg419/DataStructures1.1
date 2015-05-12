################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../DataStructures/PairID.cpp 

OBJS += \
./DataStructures/PairID.o 

CPP_DEPS += \
./DataStructures/PairID.d 


# Each subdirectory must supply rules for building sources it contributes
DataStructures/%.o: ../DataStructures/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


