################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/draw/sw/lv_draw_sw.c \
../lvgl/src/draw/sw/lv_draw_sw_arc.c \
../lvgl/src/draw/sw/lv_draw_sw_blend.c \
../lvgl/src/draw/sw/lv_draw_sw_dither.c \
../lvgl/src/draw/sw/lv_draw_sw_gradient.c \
../lvgl/src/draw/sw/lv_draw_sw_img.c \
../lvgl/src/draw/sw/lv_draw_sw_layer.c \
../lvgl/src/draw/sw/lv_draw_sw_letter.c \
../lvgl/src/draw/sw/lv_draw_sw_line.c \
../lvgl/src/draw/sw/lv_draw_sw_polygon.c \
../lvgl/src/draw/sw/lv_draw_sw_rect.c \
../lvgl/src/draw/sw/lv_draw_sw_transform.c 

OBJS += \
./lvgl/src/draw/sw/lv_draw_sw.o \
./lvgl/src/draw/sw/lv_draw_sw_arc.o \
./lvgl/src/draw/sw/lv_draw_sw_blend.o \
./lvgl/src/draw/sw/lv_draw_sw_dither.o \
./lvgl/src/draw/sw/lv_draw_sw_gradient.o \
./lvgl/src/draw/sw/lv_draw_sw_img.o \
./lvgl/src/draw/sw/lv_draw_sw_layer.o \
./lvgl/src/draw/sw/lv_draw_sw_letter.o \
./lvgl/src/draw/sw/lv_draw_sw_line.o \
./lvgl/src/draw/sw/lv_draw_sw_polygon.o \
./lvgl/src/draw/sw/lv_draw_sw_rect.o \
./lvgl/src/draw/sw/lv_draw_sw_transform.o 

C_DEPS += \
./lvgl/src/draw/sw/lv_draw_sw.d \
./lvgl/src/draw/sw/lv_draw_sw_arc.d \
./lvgl/src/draw/sw/lv_draw_sw_blend.d \
./lvgl/src/draw/sw/lv_draw_sw_dither.d \
./lvgl/src/draw/sw/lv_draw_sw_gradient.d \
./lvgl/src/draw/sw/lv_draw_sw_img.d \
./lvgl/src/draw/sw/lv_draw_sw_layer.d \
./lvgl/src/draw/sw/lv_draw_sw_letter.d \
./lvgl/src/draw/sw/lv_draw_sw_line.d \
./lvgl/src/draw/sw/lv_draw_sw_polygon.d \
./lvgl/src/draw/sw/lv_draw_sw_rect.d \
./lvgl/src/draw/sw/lv_draw_sw_transform.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/draw/sw/%.o lvgl/src/draw/sw/%.su lvgl/src/draw/sw/%.cyclo: ../lvgl/src/draw/sw/%.c lvgl/src/draw/sw/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I"D:/MIG_PROJECTS/MIG_CODE/MIG_V1.4" -I../lvgl/src/font/lv_font_montserrat_18.c -I../lvgl/src/font/lv_font_montserrat_24.c -I../lvgl/src/font/lv_font_montserrat_26.c -I../lvgl/src/font/lv_font_montserrat_20.c -I../lvgl/src/font/lv_font_montserrat_22.c -I../lvgl/src/font/lv_font_montserrat_28.c -I"D:/MIG_PROJECTS/MIG_CODE/MIG_V1.4/hal_stm_lvgl/STM32746G-Discovery" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I../Middlewares/Third_Party/LwIP/src/apps/httpd -I../Middlewares/Third_Party/LwIP/src/include/lwip/apps -I../LWIP/App -I../LWIP/Target -I../Middlewares/Third_Party/LwIP/src/include -I../Middlewares/Third_Party/LwIP/system -I../Drivers/BSP/Components/lan8742 -I../Middlewares/Third_Party/LwIP/src/include/netif/ppp -I../Middlewares/Third_Party/LwIP/src/apps/http -I../Middlewares/Third_Party/LwIP/src/include/lwip -I../Middlewares/Third_Party/LwIP/src/include/lwip/priv -I../Middlewares/Third_Party/LwIP/src/include/lwip/prot -I../Middlewares/Third_Party/LwIP/src/include/netif -I../Middlewares/Third_Party/LwIP/src/include/compat/posix -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/arpa -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/net -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/sys -I../Middlewares/Third_Party/LwIP/src/include/compat/stdc -I../Middlewares/Third_Party/LwIP/system/arch -I../lvgl/src/font/lv_font_montserrat_32.c -I../lvgl/src/font/lv_font_montserrat_32.c -I../lvgl/src/font -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-draw-2f-sw

clean-lvgl-2f-src-2f-draw-2f-sw:
	-$(RM) ./lvgl/src/draw/sw/lv_draw_sw.cyclo ./lvgl/src/draw/sw/lv_draw_sw.d ./lvgl/src/draw/sw/lv_draw_sw.o ./lvgl/src/draw/sw/lv_draw_sw.su ./lvgl/src/draw/sw/lv_draw_sw_arc.cyclo ./lvgl/src/draw/sw/lv_draw_sw_arc.d ./lvgl/src/draw/sw/lv_draw_sw_arc.o ./lvgl/src/draw/sw/lv_draw_sw_arc.su ./lvgl/src/draw/sw/lv_draw_sw_blend.cyclo ./lvgl/src/draw/sw/lv_draw_sw_blend.d ./lvgl/src/draw/sw/lv_draw_sw_blend.o ./lvgl/src/draw/sw/lv_draw_sw_blend.su ./lvgl/src/draw/sw/lv_draw_sw_dither.cyclo ./lvgl/src/draw/sw/lv_draw_sw_dither.d ./lvgl/src/draw/sw/lv_draw_sw_dither.o ./lvgl/src/draw/sw/lv_draw_sw_dither.su ./lvgl/src/draw/sw/lv_draw_sw_gradient.cyclo ./lvgl/src/draw/sw/lv_draw_sw_gradient.d ./lvgl/src/draw/sw/lv_draw_sw_gradient.o ./lvgl/src/draw/sw/lv_draw_sw_gradient.su ./lvgl/src/draw/sw/lv_draw_sw_img.cyclo ./lvgl/src/draw/sw/lv_draw_sw_img.d ./lvgl/src/draw/sw/lv_draw_sw_img.o ./lvgl/src/draw/sw/lv_draw_sw_img.su ./lvgl/src/draw/sw/lv_draw_sw_layer.cyclo ./lvgl/src/draw/sw/lv_draw_sw_layer.d ./lvgl/src/draw/sw/lv_draw_sw_layer.o ./lvgl/src/draw/sw/lv_draw_sw_layer.su ./lvgl/src/draw/sw/lv_draw_sw_letter.cyclo ./lvgl/src/draw/sw/lv_draw_sw_letter.d ./lvgl/src/draw/sw/lv_draw_sw_letter.o ./lvgl/src/draw/sw/lv_draw_sw_letter.su ./lvgl/src/draw/sw/lv_draw_sw_line.cyclo ./lvgl/src/draw/sw/lv_draw_sw_line.d ./lvgl/src/draw/sw/lv_draw_sw_line.o ./lvgl/src/draw/sw/lv_draw_sw_line.su ./lvgl/src/draw/sw/lv_draw_sw_polygon.cyclo ./lvgl/src/draw/sw/lv_draw_sw_polygon.d ./lvgl/src/draw/sw/lv_draw_sw_polygon.o ./lvgl/src/draw/sw/lv_draw_sw_polygon.su ./lvgl/src/draw/sw/lv_draw_sw_rect.cyclo ./lvgl/src/draw/sw/lv_draw_sw_rect.d ./lvgl/src/draw/sw/lv_draw_sw_rect.o ./lvgl/src/draw/sw/lv_draw_sw_rect.su ./lvgl/src/draw/sw/lv_draw_sw_transform.cyclo ./lvgl/src/draw/sw/lv_draw_sw_transform.d ./lvgl/src/draw/sw/lv_draw_sw_transform.o ./lvgl/src/draw/sw/lv_draw_sw_transform.su

.PHONY: clean-lvgl-2f-src-2f-draw-2f-sw

