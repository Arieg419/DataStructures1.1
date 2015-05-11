################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Objects/Fruit.cpp \
../Objects/Orchard.cpp \
../Objects/Plant.cpp 

OBJS += \
./Objects/Fruit.o \
./Objects/Orchard.o \
./Objects/Plant.o 

CPP_DEPS += \
./Objects/Fruit.d \
./Objects/Orchard.d \
./Objects/Plant.d 


# Each subdirectory must supply rules for building sources it contributes
Objects/%.o: ../Objects/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


