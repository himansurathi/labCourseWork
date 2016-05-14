################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Smoothing.cpp \
../applyfilter.cpp \
../convert\ to\ grayscale\ image.cpp \
../discreteFourierTransform.cpp \
../displayimage.cpp \
../histogram.cpp \
../main.cpp \
../opening\ an\ image.cpp \
../read\ image.cpp \
../thresholding\ an\ image.cpp \
../transformations.cpp 

OBJS += \
./Smoothing.o \
./applyfilter.o \
./convert\ to\ grayscale\ image.o \
./discreteFourierTransform.o \
./displayimage.o \
./histogram.o \
./main.o \
./opening\ an\ image.o \
./read\ image.o \
./thresholding\ an\ image.o \
./transformations.o 

CPP_DEPS += \
./Smoothing.d \
./applyfilter.d \
./convert\ to\ grayscale\ image.d \
./discreteFourierTransform.d \
./displayimage.d \
./histogram.d \
./main.d \
./opening\ an\ image.d \
./read\ image.d \
./thresholding\ an\ image.d \
./transformations.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/opencv -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

convert\ to\ grayscale\ image.o: ../convert\ to\ grayscale\ image.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/opencv -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"convert to grayscale image.d" -MT"convert\ to\ grayscale\ image.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

opening\ an\ image.o: ../opening\ an\ image.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/opencv -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"opening an image.d" -MT"opening\ an\ image.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

read\ image.o: ../read\ image.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/opencv -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"read image.d" -MT"read\ image.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

thresholding\ an\ image.o: ../thresholding\ an\ image.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/opencv -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"thresholding an image.d" -MT"thresholding\ an\ image.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


