################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
LD_SRCS += \
../src/lscript.ld 

C_SRCS += \
../src/anyNonFinite.c \
../src/cosd.c \
../src/diag.c \
../src/eig.c \
../src/exp.c \
../src/fft.c \
../src/fliplr.c \
../src/located.c \
../src/located_emxAPI.c \
../src/located_emxutil.c \
../src/located_initialize.c \
../src/located_rtwutil.c \
../src/located_terminate.c \
../src/main.c \
../src/mean.c \
../src/mod.c \
../src/platform.c \
../src/recip.c \
../src/relop.c \
../src/rtGetInf.c \
../src/rtGetNaN.c \
../src/rt_nonfinite.c \
../src/schur.c \
../src/sind.c \
../src/sort1.c \
../src/sqrt.c \
../src/xdlapy3.c \
../src/xgehrd.c \
../src/xgerc.c \
../src/xhseqr.c \
../src/xnrm2.c \
../src/xscal.c \
../src/xungorghr.c \
../src/xzggbal.c \
../src/xzggev.c \
../src/xzhgeqz.c \
../src/xzhseqr.c \
../src/xzlarfg.c \
../src/xzlartg.c \
../src/xztgevc.c 

OBJS += \
./src/anyNonFinite.o \
./src/cosd.o \
./src/diag.o \
./src/eig.o \
./src/exp.o \
./src/fft.o \
./src/fliplr.o \
./src/located.o \
./src/located_emxAPI.o \
./src/located_emxutil.o \
./src/located_initialize.o \
./src/located_rtwutil.o \
./src/located_terminate.o \
./src/main.o \
./src/mean.o \
./src/mod.o \
./src/platform.o \
./src/recip.o \
./src/relop.o \
./src/rtGetInf.o \
./src/rtGetNaN.o \
./src/rt_nonfinite.o \
./src/schur.o \
./src/sind.o \
./src/sort1.o \
./src/sqrt.o \
./src/xdlapy3.o \
./src/xgehrd.o \
./src/xgerc.o \
./src/xhseqr.o \
./src/xnrm2.o \
./src/xscal.o \
./src/xungorghr.o \
./src/xzggbal.o \
./src/xzggev.o \
./src/xzhgeqz.o \
./src/xzhseqr.o \
./src/xzlarfg.o \
./src/xzlartg.o \
./src/xztgevc.o 

C_DEPS += \
./src/anyNonFinite.d \
./src/cosd.d \
./src/diag.d \
./src/eig.d \
./src/exp.d \
./src/fft.d \
./src/fliplr.d \
./src/located.d \
./src/located_emxAPI.d \
./src/located_emxutil.d \
./src/located_initialize.d \
./src/located_rtwutil.d \
./src/located_terminate.d \
./src/main.d \
./src/mean.d \
./src/mod.d \
./src/platform.d \
./src/recip.d \
./src/relop.d \
./src/rtGetInf.d \
./src/rtGetNaN.d \
./src/rt_nonfinite.d \
./src/schur.d \
./src/sind.d \
./src/sort1.d \
./src/sqrt.d \
./src/xdlapy3.d \
./src/xgehrd.d \
./src/xgerc.d \
./src/xhseqr.d \
./src/xnrm2.d \
./src/xscal.d \
./src/xungorghr.d \
./src/xzggbal.d \
./src/xzggev.d \
./src/xzhgeqz.d \
./src/xzhseqr.d \
./src/xzlarfg.d \
./src/xzlartg.d \
./src/xztgevc.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 gcc compiler'
	arm-none-eabi-gcc -Wall -O0 -g3 -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -I../../final_001_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


