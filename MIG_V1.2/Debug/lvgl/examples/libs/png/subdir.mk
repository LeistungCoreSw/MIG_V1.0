################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/examples/libs/png/img_wink_png.c \
../lvgl/examples/libs/png/lv_example_png_1.c 

OBJS += \
./lvgl/examples/libs/png/img_wink_png.o \
./lvgl/examples/libs/png/lv_example_png_1.o 

C_DEPS += \
./lvgl/examples/libs/png/img_wink_png.d \
./lvgl/examples/libs/png/lv_example_png_1.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/examples/libs/png/%.o lvgl/examples/libs/png/%.su lvgl/examples/libs/png/%.cyclo: ../lvgl/examples/libs/png/%.c lvgl/examples/libs/png/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I"D:/MIG_PROJECTS/MIG_0.1/MIG_V1.2" -I../lvgl/src/font/lv_font_montserrat_18.c -I../lvgl/src/font/lv_font_montserrat_24.c -I../lvgl/src/font/lv_font_montserrat_26.c -I../lvgl/src/font/lv_font_montserrat_20.c -I../lvgl/src/font/lv_font_montserrat_22.c -I../lvgl/src/font/lv_font_montserrat_28.c -I"D:/MIG_PROJECTS/MIG_0.1/MIG_V1.2/hal_stm_lvgl/STM32746G-Discovery" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I../Middlewares/Third_Party/LwIP/src/apps/httpd -I../Middlewares/Third_Party/LwIP/src/include/lwip/apps -I../LWIP/App -I../LWIP/Target -I../Middlewares/Third_Party/LwIP/src/include -I../Middlewares/Third_Party/LwIP/system -I../Drivers/BSP/Components/lan8742 -I../Middlewares/Third_Party/LwIP/src/include/netif/ppp -I../Middlewares/Third_Party/LwIP/src/apps/http -I../Middlewares/Third_Party/LwIP/src/include/lwip -I../Middlewares/Third_Party/LwIP/src/include/lwip/priv -I../Middlewares/Third_Party/LwIP/src/include/lwip/prot -I../Middlewares/Third_Party/LwIP/src/include/netif -I../Middlewares/Third_Party/LwIP/src/include/compat/posix -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/arpa -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/net -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/sys -I../Middlewares/Third_Party/LwIP/src/include/compat/stdc -I../Middlewares/Third_Party/LwIP/system/arch -I../lvgl/src/font/lv_font_montserrat_32.c -I../lvgl/src/font/lv_font_montserrat_32.c -I../lvgl/src/font -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-examples-2f-libs-2f-png

clean-lvgl-2f-examples-2f-libs-2f-png:
	-$(RM) ./lvgl/examples/libs/png/img_wink_png.cyclo ./lvgl/examples/libs/png/img_wink_png.d ./lvgl/examples/libs/png/img_wink_png.o ./lvgl/examples/libs/png/img_wink_png.su ./lvgl/examples/libs/png/lv_example_png_1.cyclo ./lvgl/examples/libs/png/lv_example_png_1.d ./lvgl/examples/libs/png/lv_example_png_1.o ./lvgl/examples/libs/png/lv_example_png_1.su

.PHONY: clean-lvgl-2f-examples-2f-libs-2f-png

