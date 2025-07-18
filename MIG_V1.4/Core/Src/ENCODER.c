/*
 * ENCODER.c
 *
 *  Created on: Jul 17, 2025
 *      Author: admin
 */


/*
 * rotary_encoder.c

 */
#include <main.h>
#include "../../lvgl/lvgl.h"

//lv_indev_t *encoder_indev;
//lv_group_t *encoder_group;
//
//static TIM_HandleTypeDef *encoder_htim;
//
//static uint32_t old_counter;
//
//uint8_t re_key_press() {
//    if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15) == GPIO_PIN_RESET) {
//        return 1;
//    }
//    return 0;
//}
//
//int16_t re_get_new_moves(void) {
//    int16_t new_moves;
//    new_moves = 0;
//    uint32_t counter = __HAL_TIM_GET_COUNTER(encoder_htim);
//    if (counter < old_counter) {
//    	 new_moves = 1; // LV_KEY_RIGHT
//    }
//    if (counter > old_counter) {
//    	new_moves = -1; // LV_KEY_LEFT
//    }
//    old_counter = counter;
//
//    return new_moves;
//
//}
//
//void lvgl_encoder_read_cb(struct _lv_indev_drv_t * indev, lv_indev_data_t* data) {
//  //data->key = get_key();;
//	data->enc_diff = re_get_new_moves();    //rotation
//	if (re_key_press()) {					// switch
//		data->state = LV_INDEV_STATE_PRESSED;
//	} else {
//		data->state = LV_INDEV_STATE_RELEASED;
//		//data->enc_diff = re_get_new_moves();
//	}
//
// }
//
//
//
//
//
//void lvgl_rotary_encoder_init(TIM_HandleTypeDef *htim){
//	encoder_htim = htim;
//	HAL_TIM_Encoder_Start(htim,  TIM_CHANNEL_ALL);
//	__HAL_TIM_SET_COUNTER(encoder_htim,32768);
//	old_counter = 32768;
//
//	// setup rotary encoder input device
//	static lv_indev_drv_t indev_drv;           /*Descriptor of a input device driver*/
//	lv_indev_drv_init(&indev_drv);             /*Basic initialization*/
//	indev_drv.type = LV_INDEV_TYPE_ENCODER;    /*Rotary Encoder device*/
//
//	indev_drv.read_cb = lvgl_encoder_read_cb;      /*Set your driver function*/
//
//	indev_drv.long_press_time=1000;
//	indev_drv.long_press_repeat_time=100;
//	encoder_indev = lv_indev_drv_register(&indev_drv);         /*Finally register the driver*/
//	encoder_group = lv_group_create();
//
//	//lv_group_set_default(kg);
//	lv_indev_set_group(encoder_indev, encoder_group);
//}


