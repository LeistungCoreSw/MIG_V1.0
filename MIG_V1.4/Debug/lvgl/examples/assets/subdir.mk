################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/examples/assets/Picture12.c \
../lvgl/examples/assets/animimg001.c \
../lvgl/examples/assets/animimg002.c \
../lvgl/examples/assets/animimg003.c \
../lvgl/examples/assets/beacker_1.c \
../lvgl/examples/assets/ethernet.c \
../lvgl/examples/assets/img_caret_down.c \
../lvgl/examples/assets/img_cogwheel_alpha16.c \
../lvgl/examples/assets/img_cogwheel_argb.c \
../lvgl/examples/assets/img_cogwheel_chroma_keyed.c \
../lvgl/examples/assets/img_cogwheel_indexed16.c \
../lvgl/examples/assets/img_cogwheel_rgb.c \
../lvgl/examples/assets/img_hand.c \
../lvgl/examples/assets/img_skew_strip.c \
../lvgl/examples/assets/img_star.c \
../lvgl/examples/assets/imgbtn_left.c \
../lvgl/examples/assets/imgbtn_mid.c \
../lvgl/examples/assets/imgbtn_right.c \
../lvgl/examples/assets/lc.c \
../lvgl/examples/assets/lc_logo.c \
../lvgl/examples/assets/leakage_warning_1.c \
../lvgl/examples/assets/return1.c \
../lvgl/examples/assets/return_12.c 

OBJS += \
./lvgl/examples/assets/Picture12.o \
./lvgl/examples/assets/animimg001.o \
./lvgl/examples/assets/animimg002.o \
./lvgl/examples/assets/animimg003.o \
./lvgl/examples/assets/beacker_1.o \
./lvgl/examples/assets/ethernet.o \
./lvgl/examples/assets/img_caret_down.o \
./lvgl/examples/assets/img_cogwheel_alpha16.o \
./lvgl/examples/assets/img_cogwheel_argb.o \
./lvgl/examples/assets/img_cogwheel_chroma_keyed.o \
./lvgl/examples/assets/img_cogwheel_indexed16.o \
./lvgl/examples/assets/img_cogwheel_rgb.o \
./lvgl/examples/assets/img_hand.o \
./lvgl/examples/assets/img_skew_strip.o \
./lvgl/examples/assets/img_star.o \
./lvgl/examples/assets/imgbtn_left.o \
./lvgl/examples/assets/imgbtn_mid.o \
./lvgl/examples/assets/imgbtn_right.o \
./lvgl/examples/assets/lc.o \
./lvgl/examples/assets/lc_logo.o \
./lvgl/examples/assets/leakage_warning_1.o \
./lvgl/examples/assets/return1.o \
./lvgl/examples/assets/return_12.o 

C_DEPS += \
./lvgl/examples/assets/Picture12.d \
./lvgl/examples/assets/animimg001.d \
./lvgl/examples/assets/animimg002.d \
./lvgl/examples/assets/animimg003.d \
./lvgl/examples/assets/beacker_1.d \
./lvgl/examples/assets/ethernet.d \
./lvgl/examples/assets/img_caret_down.d \
./lvgl/examples/assets/img_cogwheel_alpha16.d \
./lvgl/examples/assets/img_cogwheel_argb.d \
./lvgl/examples/assets/img_cogwheel_chroma_keyed.d \
./lvgl/examples/assets/img_cogwheel_indexed16.d \
./lvgl/examples/assets/img_cogwheel_rgb.d \
./lvgl/examples/assets/img_hand.d \
./lvgl/examples/assets/img_skew_strip.d \
./lvgl/examples/assets/img_star.d \
./lvgl/examples/assets/imgbtn_left.d \
./lvgl/examples/assets/imgbtn_mid.d \
./lvgl/examples/assets/imgbtn_right.d \
./lvgl/examples/assets/lc.d \
./lvgl/examples/assets/lc_logo.d \
./lvgl/examples/assets/leakage_warning_1.d \
./lvgl/examples/assets/return1.d \
./lvgl/examples/assets/return_12.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/examples/assets/%.o lvgl/examples/assets/%.su lvgl/examples/assets/%.cyclo: ../lvgl/examples/assets/%.c lvgl/examples/assets/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I"D:/MIG_PROJECTS/MIG_CODE/MIG_V1.4" -I../lvgl/src/font/lv_font_montserrat_18.c -I../lvgl/src/font/lv_font_montserrat_24.c -I../lvgl/src/font/lv_font_montserrat_26.c -I../lvgl/src/font/lv_font_montserrat_20.c -I../lvgl/src/font/lv_font_montserrat_22.c -I../lvgl/src/font/lv_font_montserrat_28.c -I"D:/MIG_PROJECTS/MIG_CODE/MIG_V1.4/hal_stm_lvgl/STM32746G-Discovery" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I../Middlewares/Third_Party/LwIP/src/apps/httpd -I../Middlewares/Third_Party/LwIP/src/include/lwip/apps -I../LWIP/App -I../LWIP/Target -I../Middlewares/Third_Party/LwIP/src/include -I../Middlewares/Third_Party/LwIP/system -I../Drivers/BSP/Components/lan8742 -I../Middlewares/Third_Party/LwIP/src/include/netif/ppp -I../Middlewares/Third_Party/LwIP/src/apps/http -I../Middlewares/Third_Party/LwIP/src/include/lwip -I../Middlewares/Third_Party/LwIP/src/include/lwip/priv -I../Middlewares/Third_Party/LwIP/src/include/lwip/prot -I../Middlewares/Third_Party/LwIP/src/include/netif -I../Middlewares/Third_Party/LwIP/src/include/compat/posix -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/arpa -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/net -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/sys -I../Middlewares/Third_Party/LwIP/src/include/compat/stdc -I../Middlewares/Third_Party/LwIP/system/arch -I../lvgl/src/font/lv_font_montserrat_32.c -I../lvgl/src/font/lv_font_montserrat_32.c -I../lvgl/src/font -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-examples-2f-assets

clean-lvgl-2f-examples-2f-assets:
	-$(RM) ./lvgl/examples/assets/Picture12.cyclo ./lvgl/examples/assets/Picture12.d ./lvgl/examples/assets/Picture12.o ./lvgl/examples/assets/Picture12.su ./lvgl/examples/assets/animimg001.cyclo ./lvgl/examples/assets/animimg001.d ./lvgl/examples/assets/animimg001.o ./lvgl/examples/assets/animimg001.su ./lvgl/examples/assets/animimg002.cyclo ./lvgl/examples/assets/animimg002.d ./lvgl/examples/assets/animimg002.o ./lvgl/examples/assets/animimg002.su ./lvgl/examples/assets/animimg003.cyclo ./lvgl/examples/assets/animimg003.d ./lvgl/examples/assets/animimg003.o ./lvgl/examples/assets/animimg003.su ./lvgl/examples/assets/beacker_1.cyclo ./lvgl/examples/assets/beacker_1.d ./lvgl/examples/assets/beacker_1.o ./lvgl/examples/assets/beacker_1.su ./lvgl/examples/assets/ethernet.cyclo ./lvgl/examples/assets/ethernet.d ./lvgl/examples/assets/ethernet.o ./lvgl/examples/assets/ethernet.su ./lvgl/examples/assets/img_caret_down.cyclo ./lvgl/examples/assets/img_caret_down.d ./lvgl/examples/assets/img_caret_down.o ./lvgl/examples/assets/img_caret_down.su ./lvgl/examples/assets/img_cogwheel_alpha16.cyclo ./lvgl/examples/assets/img_cogwheel_alpha16.d ./lvgl/examples/assets/img_cogwheel_alpha16.o ./lvgl/examples/assets/img_cogwheel_alpha16.su ./lvgl/examples/assets/img_cogwheel_argb.cyclo ./lvgl/examples/assets/img_cogwheel_argb.d ./lvgl/examples/assets/img_cogwheel_argb.o ./lvgl/examples/assets/img_cogwheel_argb.su ./lvgl/examples/assets/img_cogwheel_chroma_keyed.cyclo ./lvgl/examples/assets/img_cogwheel_chroma_keyed.d ./lvgl/examples/assets/img_cogwheel_chroma_keyed.o ./lvgl/examples/assets/img_cogwheel_chroma_keyed.su ./lvgl/examples/assets/img_cogwheel_indexed16.cyclo ./lvgl/examples/assets/img_cogwheel_indexed16.d ./lvgl/examples/assets/img_cogwheel_indexed16.o ./lvgl/examples/assets/img_cogwheel_indexed16.su ./lvgl/examples/assets/img_cogwheel_rgb.cyclo ./lvgl/examples/assets/img_cogwheel_rgb.d ./lvgl/examples/assets/img_cogwheel_rgb.o ./lvgl/examples/assets/img_cogwheel_rgb.su ./lvgl/examples/assets/img_hand.cyclo ./lvgl/examples/assets/img_hand.d ./lvgl/examples/assets/img_hand.o ./lvgl/examples/assets/img_hand.su ./lvgl/examples/assets/img_skew_strip.cyclo ./lvgl/examples/assets/img_skew_strip.d ./lvgl/examples/assets/img_skew_strip.o ./lvgl/examples/assets/img_skew_strip.su ./lvgl/examples/assets/img_star.cyclo ./lvgl/examples/assets/img_star.d ./lvgl/examples/assets/img_star.o ./lvgl/examples/assets/img_star.su ./lvgl/examples/assets/imgbtn_left.cyclo ./lvgl/examples/assets/imgbtn_left.d ./lvgl/examples/assets/imgbtn_left.o ./lvgl/examples/assets/imgbtn_left.su ./lvgl/examples/assets/imgbtn_mid.cyclo ./lvgl/examples/assets/imgbtn_mid.d ./lvgl/examples/assets/imgbtn_mid.o ./lvgl/examples/assets/imgbtn_mid.su ./lvgl/examples/assets/imgbtn_right.cyclo ./lvgl/examples/assets/imgbtn_right.d ./lvgl/examples/assets/imgbtn_right.o ./lvgl/examples/assets/imgbtn_right.su ./lvgl/examples/assets/lc.cyclo ./lvgl/examples/assets/lc.d ./lvgl/examples/assets/lc.o ./lvgl/examples/assets/lc.su ./lvgl/examples/assets/lc_logo.cyclo ./lvgl/examples/assets/lc_logo.d ./lvgl/examples/assets/lc_logo.o ./lvgl/examples/assets/lc_logo.su ./lvgl/examples/assets/leakage_warning_1.cyclo ./lvgl/examples/assets/leakage_warning_1.d ./lvgl/examples/assets/leakage_warning_1.o ./lvgl/examples/assets/leakage_warning_1.su ./lvgl/examples/assets/return1.cyclo ./lvgl/examples/assets/return1.d ./lvgl/examples/assets/return1.o ./lvgl/examples/assets/return1.su ./lvgl/examples/assets/return_12.cyclo ./lvgl/examples/assets/return_12.d ./lvgl/examples/assets/return_12.o ./lvgl/examples/assets/return_12.su

.PHONY: clean-lvgl-2f-examples-2f-assets

