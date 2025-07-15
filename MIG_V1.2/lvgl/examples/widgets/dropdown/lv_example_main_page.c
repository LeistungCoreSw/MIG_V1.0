
#include "../../lv_examples.h"
#include "main.h"
#include "stm32746g_discovery.h"
#include <stdio.h>
#include "lv_font.h"

LV_FONT_DECLARE(lv_font_montserrat_32);
#if LV_USE_DROPDOWN && LV_BUILD_EXAMPLES

#define CANVAS_WIDTH  120
#define CANVAS_HEIGHT 40

static lv_color_t cbuf[LV_CANVAS_BUF_SIZE_TRUE_COLOR(CANVAS_WIDTH, CANVAS_HEIGHT)];
static lv_color_t cbuf1[LV_CANVAS_BUF_SIZE_TRUE_COLOR(CANVAS_WIDTH, CANVAS_HEIGHT)];
static lv_color_t cbuf2[LV_CANVAS_BUF_SIZE_TRUE_COLOR(CANVAS_WIDTH, CANVAS_HEIGHT)];
static lv_color_t cbuf3[LV_CANVAS_BUF_SIZE_TRUE_COLOR(CANVAS_WIDTH, CANVAS_HEIGHT)];

LV_FONT_DECLARE(my_font_30);
lv_obj_t *dd;
lv_obj_t *dd1;
lv_obj_t *dd_MATERIAL_TYPE;
lv_obj_t *dd_GAS;
lv_obj_t *canvas1;
lv_obj_t *main_screen = NULL;  // Global or static variable to store main screen
lv_obj_t *new_scr = NULL;
lv_obj_t * tabview_screen = NULL;
lv_obj_t *TEXT_TORCH;


static lv_obj_t  *spinbox_start_current ;
static lv_obj_t  *spinbox_WELDING_current;
static lv_obj_t  *spinbox_CREATER_current;
static lv_obj_t  * spinbox_WELDING_VOLTAGE;
static lv_obj_t  * spinbox_POST_FLOW ;
static lv_obj_t  * spinbox_PRE_FLOW ;

void handle_two_t_screen (void);
static void return_event_handler(lv_event_t * e);
//void lv_example_main_page(float wiresize , float ampere, float wire_speed , float mat_Thick , float voltage , float arc_width );

static void two_t_event_handler(lv_event_t *e)
{

	lv_event_code_t code = lv_event_get_code(e);
	if(code == LV_EVENT_CLICKED)
	{

		lv_obj_t *New_screen_2t = lv_obj_create(NULL);
	    lv_obj_clear_flag(New_screen_2t, LV_OBJ_FLAG_SCROLLABLE);
	    lv_scr_load(New_screen_2t);




        lv_obj_t * return_btn_2t = lv_btn_create(New_screen_2t);
        lv_obj_set_size(return_btn_2t, 80, 30);
        lv_obj_align(return_btn_2t, LV_ALIGN_BOTTOM_RIGHT, -70, -5);

        // Create label on button
        lv_obj_t * return_label1 = lv_label_create(return_btn_2t);
        lv_label_set_text(return_label1, "Return");

        // Add event handler for return button
        lv_obj_add_event_cb(return_btn_2t, return_event_handler, LV_EVENT_CLICKED, NULL);
        lv_obj_set_style_bg_color(return_btn_2t, lv_color_hex(0x000000), LV_PART_MAIN);

}
}
// Event callback for 4T button
static void four_t_event_handler(lv_event_t *e) {

//    lv_label_set_text(TEXT_TORCH, "4T");
}

// Event callback for SPT button
static void spt_event_handler(lv_event_t *e) {
//    lv_label_set_text(TEXT_TORCH, "SPT");
}

static void return_event_handler_from_modes_to_options(lv_event_t * e)
{
    if (new_scr) {
        lv_scr_load(new_scr);  // Return to the saved main screen
    }
}



static void return_event_handler(lv_event_t * e)
{
    if (main_screen) {
        lv_scr_load(main_screen);  // Return to the saved main screen
    }
}





static void mig_function_event_handler(lv_event_t * e)
{
    	lv_event_code_t code = lv_event_get_code(e);
    	if(code == LV_EVENT_CLICKED)
    	{
    		   if (!new_scr)
    		        {
    		        	new_scr = lv_scr_act();
    		        }
//    		   main_screen = lv_scr_act();
            lv_obj_t * screen_mig_setting = lv_obj_create(NULL);
            lv_scr_load(screen_mig_setting);
            lv_obj_clear_flag(screen_mig_setting, LV_OBJ_FLAG_SCROLLABLE);

//            static lv_style_t mig_mode;
//                lv_style_init(&mig_mode);
//                lv_style_set_text_font(&mig_mode, &lv_font_montserrat_14);  // Only 2 args
//
//
	        lv_obj_t * START_CURRENT= lv_label_create(screen_mig_setting);
	        lv_label_set_text(START_CURRENT, "Start Current");
	        lv_obj_align(START_CURRENT, LV_ALIGN_TOP_LEFT, 30, 15);
//	        lv_obj_add_style(START_CURRENT, &mig_mode, 0);  // Apply th
//
	        lv_obj_t * WELDING_CURRENT = lv_label_create(screen_mig_setting);
	        lv_label_set_text(WELDING_CURRENT, "Welding  Current");
	        lv_obj_align(WELDING_CURRENT, LV_ALIGN_TOP_LEFT, 30, 45);
//	        lv_obj_add_style(WELDING_CURRENT, &mig_mode, 0);  // Apply th
//
	        lv_obj_t * CREATER_CURRENT= lv_label_create(screen_mig_setting);
	        lv_label_set_text(CREATER_CURRENT, "Creater Current");
	        lv_obj_align(CREATER_CURRENT, LV_ALIGN_TOP_LEFT, 30, 75);
//	        lv_obj_add_style(CREATER_CURRENT, &mig_mode, 0);  // Apply th
//
//
	        lv_obj_t * WELDING_VOLTAGE= lv_label_create(screen_mig_setting);
	        lv_label_set_text(WELDING_VOLTAGE, "Welding Voltage");
	        lv_obj_align(WELDING_VOLTAGE, LV_ALIGN_LEFT_MID, 30, -25);
//	        lv_obj_add_style(WELDING_VOLTAGE, &mig_mode, 0);  // Apply th
//
//
	        lv_obj_t * MATERIAL_TYPE= lv_label_create(screen_mig_setting);
	        lv_label_set_text(MATERIAL_TYPE, "Material Type");
	        lv_obj_align(MATERIAL_TYPE, LV_ALIGN_LEFT_MID, 30, 5);
//	        lv_obj_add_style(MATERIAL_TYPE, &mig_mode, 0);  // Apply th
//
//
//
	        lv_obj_t * GAS= lv_label_create(screen_mig_setting);
	        lv_label_set_text(GAS, "GAS");
	        lv_obj_align(GAS, LV_ALIGN_LEFT_MID, 30, 38);
//	        lv_obj_add_style(GAS, &mig_mode, 0);  // Apply th
//
	        lv_obj_t * PRE_FLOW= lv_label_create(screen_mig_setting);
	        lv_label_set_text(PRE_FLOW, "Pre Flow");
	        lv_obj_align(PRE_FLOW, LV_ALIGN_LEFT_MID, 30, 68);
//	        lv_obj_add_style(PRE_FLOW, &mig_mode, 0);  // Apply th
//
	        lv_obj_t * POST_FLOW= lv_label_create(screen_mig_setting);
	        lv_label_set_text(POST_FLOW, "Post Flow");
	        lv_obj_align(POST_FLOW, LV_ALIGN_LEFT_MID, 30,100 );
//	        lv_obj_add_style(POST_FLOW, &mig_mode, 0);  // Apply th
//
//
//	        //spinbox

			spinbox_start_current = lv_spinbox_create(screen_mig_setting);
			lv_spinbox_set_range(spinbox_start_current, 0, 10);
			lv_spinbox_set_value(spinbox_start_current, 0);
			lv_spinbox_set_digit_format(spinbox_start_current, 2, 3);
			lv_obj_set_size(spinbox_start_current, 70, 25);
			lv_obj_align(spinbox_start_current, LV_ALIGN_TOP_MID, 10, 10);

			lv_obj_set_style_text_align(spinbox_start_current, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);
			lv_obj_set_style_pad_left(spinbox_start_current, 3, LV_PART_MAIN);
			lv_obj_set_style_pad_right(spinbox_start_current, 0, LV_PART_MAIN);
			lv_obj_set_style_pad_top(spinbox_start_current, 3, LV_PART_MAIN);
			lv_obj_set_style_pad_bottom(spinbox_start_current, 0, LV_PART_MAIN);

//			lv_obj_add_event_cb(spinbox_start_current, spinbox_event_handler, LV_EVENT_FOCUSED, NULL);

//			lv_obj_add_event_cb(spinbox_stabilization_Delay, spinbox_event_handler, LV_EVENT_FOCUSED, (void*)5);
//			lv_obj_add_event_cb(spinbox_stabilization_Delay, spinbox_event_handler, LV_EVENT_VALUE_CHANGED, (void*)5);


			spinbox_WELDING_current = lv_spinbox_create(screen_mig_setting);
			lv_spinbox_set_range(spinbox_WELDING_current, 0, 10);
			lv_spinbox_set_value(spinbox_WELDING_current, 1);
			lv_spinbox_set_digit_format(spinbox_WELDING_current, 2, 3);
			lv_obj_set_size(spinbox_WELDING_current, 70, 25);
			lv_obj_align(spinbox_WELDING_current, LV_ALIGN_TOP_MID, 10, 40);

			lv_obj_set_style_text_align(spinbox_WELDING_current, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);
			lv_obj_set_style_pad_left(spinbox_WELDING_current, 3, LV_PART_MAIN);
			lv_obj_set_style_pad_right(spinbox_WELDING_current, 0, LV_PART_MAIN);
			lv_obj_set_style_pad_top(spinbox_WELDING_current, 3, LV_PART_MAIN);
			lv_obj_set_style_pad_bottom(spinbox_WELDING_current, 0, LV_PART_MAIN);

//			lv_obj_add_event_cb(spinbox_start_current, spinbox_event_handler, LV_EVENT_FOCUSED, NULL);

//			lv_obj_add_event_cb(spinbox_stabilization_Delay, spinbox_event_handler, LV_EVENT_FOCUSED, (void*)5);
//			lv_obj_add_event_cb(spinbox_stabilization_Delay, spinbox_event_handler, LV_EVENT_VALUE_CHANGED, (void*)5);


			spinbox_CREATER_current = lv_spinbox_create(screen_mig_setting);
			lv_spinbox_set_range(spinbox_CREATER_current, 0, 10);
			lv_spinbox_set_value(spinbox_CREATER_current, 2);
			lv_spinbox_set_digit_format(spinbox_CREATER_current, 2, 3);
			lv_obj_set_size(spinbox_CREATER_current, 70, 25);
			lv_obj_align(spinbox_CREATER_current, LV_ALIGN_TOP_MID, 10, 70);

			lv_obj_set_style_text_align(spinbox_CREATER_current, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);
			lv_obj_set_style_pad_left(spinbox_CREATER_current, 3, LV_PART_MAIN);
			lv_obj_set_style_pad_right(spinbox_CREATER_current, 0, LV_PART_MAIN);
			lv_obj_set_style_pad_top(spinbox_CREATER_current, 3, LV_PART_MAIN);
			lv_obj_set_style_pad_bottom(spinbox_CREATER_current, 0, LV_PART_MAIN);

//			lv_obj_add_event_cb(spinbox_start_current, spinbox_event_handler, LV_EVENT_FOCUSED, NULL);

//			lv_obj_add_event_cb(spinbox_stabilization_Delay, spinbox_event_handler, LV_EVENT_FOCUSED, (void*)5);
//			lv_obj_add_event_cb(spinbox_stabilization_Delay, spinbox_event_handler, LV_EVENT_VALUE_CHANGED, (void*)5);


			spinbox_WELDING_VOLTAGE = lv_spinbox_create(screen_mig_setting);
			lv_spinbox_set_range(spinbox_WELDING_VOLTAGE, 0, 40);
			lv_spinbox_set_value(spinbox_WELDING_VOLTAGE, 2);
			lv_spinbox_set_digit_format(spinbox_WELDING_VOLTAGE, 2, 3);
			lv_obj_set_size(spinbox_WELDING_VOLTAGE, 70, 25);
			lv_obj_align(spinbox_WELDING_VOLTAGE, LV_ALIGN_TOP_MID, 10, 100);

			lv_obj_set_style_text_align(spinbox_WELDING_VOLTAGE, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);
			lv_obj_set_style_pad_left(spinbox_WELDING_VOLTAGE, 3, LV_PART_MAIN);
			lv_obj_set_style_pad_right(spinbox_WELDING_VOLTAGE, 0, LV_PART_MAIN);
			lv_obj_set_style_pad_top(spinbox_WELDING_VOLTAGE, 3, LV_PART_MAIN);
			lv_obj_set_style_pad_bottom(spinbox_WELDING_VOLTAGE, 0, LV_PART_MAIN);

//			lv_obj_add_event_cb(spinbox_start_current, spinbox_event_handler, LV_EVENT_FOCUSED, NULL);

//			lv_obj_add_event_cb(spinbox_stabilization_Delay, spinbox_event_handler, LV_EVENT_FOCUSED, (void*)5);
//			lv_obj_add_event_cb(spinbox_stabilization_Delay, spinbox_event_handler, LV_EVENT_VALUE_CHANGED, (void*)5);


	           dd_MATERIAL_TYPE = lv_dropdown_create(screen_mig_setting);
	           lv_obj_set_style_pad_left(dd_MATERIAL_TYPE, 7, 0);
	           lv_obj_set_style_pad_right(dd_MATERIAL_TYPE, 7, 0);
	           lv_obj_set_style_pad_top(dd_MATERIAL_TYPE, 0, 0);
	           lv_obj_set_style_pad_bottom(dd_MATERIAL_TYPE, 7, 0);

	           lv_obj_align(dd_MATERIAL_TYPE, LV_ALIGN_BOTTOM_MID, 10, -118);
	           lv_obj_set_size(dd_MATERIAL_TYPE, 70, 25);

	           lv_dropdown_set_options(dd_MATERIAL_TYPE, "MS\nSS\nCU\nAISi\nAIMg");




	           dd_GAS = lv_dropdown_create(screen_mig_setting);
	           lv_obj_set_style_pad_left(dd_GAS, 7, 0);
	           lv_obj_set_style_pad_right(dd_GAS, 7, 0);
	           lv_obj_set_style_pad_top(dd_GAS, 0, 0);
	           lv_obj_set_style_pad_bottom(dd_GAS, 7, 0);

	           lv_obj_align(dd_GAS, LV_ALIGN_BOTTOM_MID, 10, -87);
	           lv_obj_set_size(dd_GAS, 70, 25);

	           lv_dropdown_set_options(dd_GAS, "CO2\nAr\nMix");


				spinbox_PRE_FLOW = lv_spinbox_create(screen_mig_setting);
				lv_spinbox_set_range(spinbox_PRE_FLOW, 0, 10);
				lv_spinbox_set_value(spinbox_PRE_FLOW, 1);
				lv_spinbox_set_digit_format(spinbox_PRE_FLOW, 2, 3);
				lv_obj_set_size(spinbox_PRE_FLOW, 70, 25);
				lv_obj_align(spinbox_PRE_FLOW, LV_ALIGN_BOTTOM_MID, 10, -57);

				lv_obj_set_style_text_align(spinbox_PRE_FLOW, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);
				lv_obj_set_style_pad_left(spinbox_PRE_FLOW, 3, LV_PART_MAIN);
				lv_obj_set_style_pad_right(spinbox_PRE_FLOW, 0, LV_PART_MAIN);
				lv_obj_set_style_pad_top(spinbox_PRE_FLOW, 3, LV_PART_MAIN);
				lv_obj_set_style_pad_bottom(spinbox_PRE_FLOW, 0, LV_PART_MAIN);

	//			lv_obj_add_event_cb(spinbox_start_current, spinbox_event_handler, LV_EVENT_FOCUSED, NULL);

	//			lv_obj_add_event_cb(spinbox_stabilization_Delay, spinbox_event_handler, LV_EVENT_FOCUSED, (void*)5);
	//			lv_obj_add_event_cb(spinbox_stabilization_Delay, spinbox_event_handler, LV_EVENT_VALUE_CHANGED, (void*)5);


				spinbox_POST_FLOW = lv_spinbox_create(screen_mig_setting);
				lv_spinbox_set_range(spinbox_POST_FLOW, 0, 10);
				lv_spinbox_set_value(spinbox_POST_FLOW, 2);
				lv_spinbox_set_digit_format(spinbox_POST_FLOW, 2, 3);
				lv_obj_set_size(spinbox_POST_FLOW, 70, 25);
				lv_obj_align(spinbox_POST_FLOW, LV_ALIGN_BOTTOM_MID, 10, -27);

				lv_obj_set_style_text_align(spinbox_POST_FLOW, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);
				lv_obj_set_style_pad_left(spinbox_POST_FLOW, 3, LV_PART_MAIN);
				lv_obj_set_style_pad_right(spinbox_POST_FLOW, 0, LV_PART_MAIN);
				lv_obj_set_style_pad_top(spinbox_POST_FLOW, 3, LV_PART_MAIN);
				lv_obj_set_style_pad_bottom(spinbox_POST_FLOW, 0, LV_PART_MAIN);

	//			lv_obj_add_event_cb(spinbox_start_current, spinbox_event_handler, LV_EVENT_FOCUSED, NULL);

	//			lv_obj_add_event_cb(spinbox_stabilization_Delay, spinbox_event_handler, LV_EVENT_FOCUSED, (void*)5);
	//			lv_obj_add_event_cb(spinbox_stabilization_Delay, spinbox_event_handler, LV_EVENT_VALUE_CHANGED, (void*)5);



    	     	lv_obj_t * return_btn = lv_btn_create(screen_mig_setting);
    	        lv_obj_set_size(return_btn, 80, 30);
    	        lv_obj_align(return_btn, LV_ALIGN_BOTTOM_RIGHT, -90, -10);
    	        lv_obj_set_style_bg_color(return_btn, lv_color_hex(0x008080), LV_PART_MAIN);
    	        // Create label on button
    	        lv_obj_t * return_label = lv_label_create(return_btn);
    	        lv_label_set_text(return_label, "Return");

    	     		lv_obj_t * return_btn1 = lv_btn_create(screen_mig_setting);
        	        lv_obj_set_size(return_btn1, 80, 30);
        	        lv_obj_align(return_btn1, LV_ALIGN_BOTTOM_RIGHT, 0, -10);
        	        lv_obj_set_style_bg_color(return_btn1, lv_color_hex(0x404040), LV_PART_MAIN);
        	        // Create label on button
        	        lv_obj_t * return_label1 = lv_label_create(return_btn1);
        	        lv_label_set_text(return_label1, "Home");


    	        lv_obj_add_event_cb(return_btn, return_event_handler_from_modes_to_options, LV_EVENT_CLICKED, NULL);
    	        lv_obj_add_event_cb(return_btn1, return_event_handler, LV_EVENT_CLICKED, NULL);
    	}


    	}


static void mode_event_handler_canvas(lv_event_t * e)
{
    	lv_event_code_t code = lv_event_get_code(e);
    	if(code == LV_EVENT_CLICKED) {

        // Store current screen before changing
        if (!main_screen)
        {
          main_screen = lv_scr_act();
        }



        // Create new screen
        lv_obj_t * new_scr = lv_obj_create(NULL);
        lv_scr_load(new_scr);

        lv_obj_t * mode_btn = lv_btn_create(new_scr);
        lv_obj_set_size(mode_btn, 80, 30);
        lv_obj_align(mode_btn, LV_ALIGN_TOP_LEFT, 0, 0);
        lv_obj_set_style_bg_color(mode_btn, lv_color_hex(0xFFA500), LV_PART_MAIN);

        // Create label on button
        lv_obj_t * mode_btn_lable = lv_label_create(mode_btn);
        lv_label_set_text(mode_btn_lable, "MODE");


        // Create return button
        lv_obj_t * return_btn_mode = lv_btn_create(new_scr);
        lv_obj_set_size(return_btn_mode, 80, 30);
        lv_obj_align(return_btn_mode, LV_ALIGN_BOTTOM_RIGHT, -70, -5);

        // Create label on button
        lv_obj_t * return_label = lv_label_create(return_btn_mode);
        lv_label_set_text(return_label, "Return");

        // Add event handler for return button
        lv_obj_add_event_cb(return_btn_mode, return_event_handler, LV_EVENT_CLICKED, NULL);
        lv_obj_set_style_bg_color(return_btn_mode, lv_color_hex(0x000000), LV_PART_MAIN);

//        MIG_MODE    //


         lv_obj_t * MIG_btn = lv_btn_create(new_scr);
         lv_obj_set_size(MIG_btn, 80, 50);
         lv_obj_align(MIG_btn, LV_ALIGN_LEFT_MID, 15, 0);
         lv_obj_set_style_bg_color(MIG_btn, lv_color_hex(0xFFA500), LV_PART_MAIN);

         // Create label on button MIG  ///

         lv_obj_t * MIG_label = lv_label_create(MIG_btn);
         lv_label_set_text(MIG_label, "MIG");
         lv_obj_align(MIG_label, LV_ALIGN_LEFT_MID, 10, 0);
         lv_obj_set_style_bg_color(MIG_label, lv_color_hex(0xFF0000), LV_PART_MAIN);

         lv_obj_add_event_cb(MIG_btn, mig_function_event_handler, LV_EVENT_CLICKED, NULL);

         lv_obj_t * MMA_btn = lv_btn_create(new_scr);
         lv_obj_set_size(MMA_btn, 80, 50);
         lv_obj_align(MMA_btn, LV_ALIGN_CENTER, 0, 0);
         lv_obj_set_style_bg_color(MMA_btn, lv_color_hex(0xFFA500), LV_PART_MAIN);

         // Create label on button MMA ////

         lv_obj_t * MMA_label = lv_label_create(MMA_btn);
         lv_label_set_text(MMA_label, "MMA");
         lv_obj_align(MMA_label, LV_ALIGN_CENTER, -5, 0);
         lv_obj_set_style_bg_color(MMA_label, lv_color_hex(0xFF0000), LV_PART_MAIN);


         lv_obj_t * TIG_btn = lv_btn_create(new_scr);
         lv_obj_set_size(TIG_btn, 80, 50);
         lv_obj_align(TIG_btn, LV_ALIGN_RIGHT_MID, -15, 0);
         lv_obj_set_style_bg_color(TIG_btn, lv_color_hex(0xFFA500), LV_PART_MAIN);

         // Create label on button MMA   //////

         lv_obj_t * TIG_label = lv_label_create(TIG_btn);
         lv_label_set_text(TIG_label, "TIG");
         lv_obj_align(TIG_label, LV_ALIGN_RIGHT_MID, -10, 0);
         lv_obj_set_style_bg_color(TIG_label, lv_color_hex(0xFF0000), LV_PART_MAIN);

    }
}


static void TORCH_event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_CLICKED) {

        // Store current screen before changing
        if (!main_screen) {
            main_screen = lv_scr_act();
        }
        lv_obj_t * new_scr4 = lv_obj_create(NULL);
        lv_obj_clear_flag(new_scr4, LV_OBJ_FLAG_SCROLLABLE);
        lv_scr_load(new_scr4);


        lv_obj_t * TWO_T_BUTTON = lv_btn_create(new_scr4);
        lv_obj_set_size(TWO_T_BUTTON, 80, 30);
        lv_obj_align(TWO_T_BUTTON, LV_ALIGN_LEFT_MID, 15, 5);
        lv_obj_set_style_bg_color(TWO_T_BUTTON, lv_color_hex(0xA52A2A), LV_PART_MAIN);



        // Create label on button MIG  ///

        lv_obj_t * TWO_T_label = lv_label_create(TWO_T_BUTTON);
        lv_label_set_text(TWO_T_label, "2T");
        lv_obj_set_style_bg_color(TWO_T_label, lv_color_hex(0xFF0000), LV_PART_MAIN);
        lv_obj_add_event_cb(TWO_T_BUTTON, two_t_event_handler, LV_EVENT_CLICKED, NULL);//two_t_event_handler



        lv_obj_t * FOUR_T_BUTTON = lv_btn_create(new_scr4);
        lv_obj_set_size(FOUR_T_BUTTON, 80, 30);
        lv_obj_align(FOUR_T_BUTTON, LV_ALIGN_CENTER, 0, 5);
        lv_obj_set_style_bg_color(FOUR_T_BUTTON, lv_color_hex(0xA52A2A), LV_PART_MAIN);

        // Create label on button MMA ////

        lv_obj_t * FOUR_T_label = lv_label_create(FOUR_T_BUTTON);
        lv_label_set_text(FOUR_T_label, "4T");
        lv_obj_set_style_bg_color(FOUR_T_label, lv_color_hex(0xFF0000), LV_PART_MAIN);
        lv_obj_add_event_cb(FOUR_T_BUTTON, four_t_event_handler, LV_EVENT_CLICKED, NULL);



        lv_obj_t * SPT_BUTTON = lv_btn_create(new_scr4);
        lv_obj_set_size(SPT_BUTTON, 80, 30);
        lv_obj_align(SPT_BUTTON, LV_ALIGN_RIGHT_MID, -15, 5);
        lv_obj_set_style_bg_color(SPT_BUTTON, lv_color_hex(0xA52A2A), LV_PART_MAIN);

        // Create label on button MMA   //////

        lv_obj_t * SPT_label = lv_label_create(SPT_BUTTON);
        lv_label_set_text(SPT_label, "SPT");
        lv_obj_set_style_bg_color(SPT_label, lv_color_hex(0xFF0000), LV_PART_MAIN);
        lv_obj_add_event_cb(SPT_BUTTON, spt_event_handler, LV_EVENT_CLICKED, NULL);




        lv_obj_t * return_btn1 = lv_btn_create(new_scr4);
        lv_obj_set_size(return_btn1, 80, 30);
        lv_obj_align(return_btn1, LV_ALIGN_BOTTOM_RIGHT, -70, -5);

        // Create label on button
        lv_obj_t * return_label1 = lv_label_create(return_btn1);
        lv_label_set_text(return_label1, "Return");

        // Add event handler for return button
        lv_obj_add_event_cb(return_btn1, return_event_handler, LV_EVENT_CLICKED, NULL);
        lv_obj_set_style_bg_color(return_btn1, lv_color_hex(0x000000), LV_PART_MAIN);






    }
}

static void WIRE_SIZE_event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_CLICKED) {

        // Store current screen before changing
        if (!main_screen) {
            main_screen = lv_scr_act();
        }
        lv_obj_t * new_scr1 = lv_obj_create(NULL);
        lv_scr_load(new_scr1);

           dd = lv_dropdown_create(new_scr1);
           lv_obj_set_style_pad_left(dd, 7, 0);
           lv_obj_set_style_pad_right(dd, 7, 0);
           lv_obj_set_style_pad_top(dd, 0, 0);
           lv_obj_set_style_pad_bottom(dd, 7, 0);

           lv_obj_align(dd, LV_ALIGN_LEFT_MID, 140, -30);
           lv_obj_set_size(dd, 70, 25);

           lv_dropdown_set_options(dd, "0.6\n0.8\n1.0\n1.2\n1.6\n2.0\n2.4");



           // Create return button
             lv_obj_t * return_btn_wire_size = lv_btn_create(new_scr1);
             lv_obj_set_size(return_btn_wire_size, 80, 30);
             lv_obj_align(return_btn_wire_size, LV_ALIGN_BOTTOM_RIGHT, -70, -5);

             // Create label on button
             lv_obj_t * return_label1 = lv_label_create(return_btn_wire_size);
             lv_label_set_text(return_label1, "Return");

             // Add event handler for return button
             lv_obj_add_event_cb(return_btn_wire_size, return_event_handler, LV_EVENT_CLICKED, NULL);
             lv_obj_set_style_bg_color(return_btn_wire_size, lv_color_hex(0x000000), LV_PART_MAIN);

    }

}



static void MAT_THICK_event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_CLICKED) {

        // Save current screen (optional)
        if (!main_screen) {
            main_screen = lv_scr_act();
        }

        lv_obj_t * new_scr2 = lv_obj_create(NULL);
        lv_scr_load(new_scr2);

        lv_obj_t * return_btn_MAT_THICK = lv_btn_create(new_scr2);
        lv_obj_set_size(return_btn_MAT_THICK, 80, 30);
        lv_obj_align(return_btn_MAT_THICK, LV_ALIGN_BOTTOM_RIGHT, -70, -5);

        lv_obj_t * return_LABLE_MAT_THICK = lv_label_create(return_btn_MAT_THICK);
        lv_label_set_text(return_LABLE_MAT_THICK, "Return");

        lv_obj_add_event_cb(return_btn_MAT_THICK, return_event_handler, LV_EVENT_CLICKED, NULL);
        lv_obj_set_style_bg_color(return_btn_MAT_THICK, lv_color_hex(0x000000), LV_PART_MAIN);


    }
}


static void PROCESS_event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_CLICKED) {

        // Save current screen (optional)
        if (!main_screen) {
            main_screen = lv_scr_act();
        }

        // Create tabview only once
        if (!tabview_screen) {
            tabview_screen = lv_tabview_create(NULL, LV_DIR_TOP, 35);
            lv_tabview_set_act(tabview_screen, 0, LV_ANIM_OFF);

            lv_obj_t * MODE_TAB = lv_tabview_add_tab(tabview_screen, "MODE TYPE");
            lv_obj_set_style_bg_color(MODE_TAB, lv_color_hex(0x00FF00), LV_PART_MAIN);


            lv_obj_t * TORCHTYPE_TAB = lv_tabview_add_tab(tabview_screen, "TORCH TYPE");
            lv_obj_set_style_bg_color(TORCHTYPE_TAB, lv_color_hex(0xF5F5DC), LV_PART_MAIN);


            lv_obj_t * GAS_SELECT_TAB = lv_tabview_add_tab(tabview_screen, "GAS TYPE");
            lv_obj_set_style_bg_color(GAS_SELECT_TAB, lv_color_hex(0xFA8072), LV_PART_MAIN);



            dd = lv_dropdown_create(TORCHTYPE_TAB);
            lv_obj_set_style_pad_left(dd, 7, 0);
            lv_obj_set_style_pad_right(dd, 7, 0);
            lv_obj_set_style_pad_top(dd, 0, 0);
            lv_obj_set_style_pad_bottom(dd, 7, 0);

            lv_obj_align(dd, LV_ALIGN_LEFT_MID, 140, -30);
            lv_obj_set_size(dd, 70, 25);

            lv_dropdown_set_options(dd, "2T\n4T\nSPT");



            dd1 = lv_dropdown_create(GAS_SELECT_TAB);
            lv_obj_set_style_pad_left(dd1, 7, 0);
            lv_obj_set_style_pad_right(dd1, 7, 0);
            lv_obj_set_style_pad_top(dd1, 0, 0);
            lv_obj_set_style_pad_bottom(dd1, 7, 0);

            lv_obj_align(dd1, LV_ALIGN_LEFT_MID, 140, -30);
            lv_obj_set_size(dd1, 70, 25);

            lv_dropdown_set_options(dd1, "AR\nC02\nAR+C02");



            // Create return button
            lv_obj_t * return_btn_MODE_TYPE = lv_btn_create(MODE_TAB);
            lv_obj_set_size(return_btn_MODE_TYPE, 80, 30);
            lv_obj_align(return_btn_MODE_TYPE, LV_ALIGN_BOTTOM_RIGHT, -70, -5);

            lv_obj_t * return_label_MODE_TYPE = lv_label_create(return_btn_MODE_TYPE);
            lv_label_set_text(return_label_MODE_TYPE, "Return");

            lv_obj_add_event_cb(return_btn_MODE_TYPE, return_event_handler, LV_EVENT_CLICKED, NULL);
            lv_obj_set_style_bg_color(return_btn_MODE_TYPE, lv_color_hex(0x000000), LV_PART_MAIN);



            lv_obj_t * return_btn_TORCH_TYPE = lv_btn_create(TORCHTYPE_TAB);
            lv_obj_set_size(return_btn_TORCH_TYPE, 80, 30);
            lv_obj_align(return_btn_TORCH_TYPE, LV_ALIGN_BOTTOM_RIGHT, -70, -5);

            lv_obj_t * return_label_TORCH_TYPE = lv_label_create(return_btn_TORCH_TYPE);
            lv_label_set_text(return_label_TORCH_TYPE, "Return");

            lv_obj_add_event_cb(return_btn_TORCH_TYPE, return_event_handler, LV_EVENT_CLICKED, NULL);
            lv_obj_set_style_bg_color(return_btn_TORCH_TYPE, lv_color_hex(0x000000), LV_PART_MAIN);


            lv_obj_t * return_btn_GAS_SELECT = lv_btn_create(GAS_SELECT_TAB);
            lv_obj_set_size(return_btn_GAS_SELECT, 80, 30);
            lv_obj_align(return_btn_GAS_SELECT, LV_ALIGN_BOTTOM_RIGHT, -70, -5);

            lv_obj_t * return_label_GAS_SELECT = lv_label_create(return_btn_GAS_SELECT);
            lv_label_set_text(return_label_GAS_SELECT, "Return");

            lv_obj_add_event_cb(return_btn_GAS_SELECT, return_event_handler, LV_EVENT_CLICKED, NULL);
            lv_obj_set_style_bg_color(return_btn_GAS_SELECT, lv_color_hex(0x000000), LV_PART_MAIN);
        }

        // Load the tabview screen
        lv_scr_load(tabview_screen);
    }
}





void lv_example_main_page(float wiresize , float ampere, float wire_speed , float mat_Thick , float voltage , float arc_width )
{


//    if (!main_screen) {
//           main_screen = lv_scr_act();
//       }

	char buf[16];
	lv_obj_set_style_bg_color(lv_scr_act(), lv_color_black(), 0);
	lv_obj_set_style_bg_opa(lv_scr_act(), LV_OPA_COVER, 0);

    lv_obj_t * canvas = lv_canvas_create(lv_scr_act());
    lv_obj_set_style_bg_color(lv_scr_act(), lv_color_white(), 0);
    lv_obj_set_style_bg_opa(lv_scr_act(), LV_OPA_COVER, 0);

//	lv_obj_set_style_bg_color(lv_scr_act(), lv_color_black(), 0);
//	lv_obj_set_style_bg_opa(lv_scr_act(), LV_OPA_COVER, 0);
    lv_canvas_set_buffer(canvas, cbuf, CANVAS_WIDTH, CANVAS_HEIGHT, LV_IMG_CF_TRUE_COLOR);
    lv_obj_align(canvas, LV_ALIGN_TOP_LEFT, 0, 0);

    // Fill background transparent
    lv_canvas_fill_bg(canvas, lv_color_white(), LV_OPA_0);

    // Define trapezoid points (clockwise)
    lv_point_t points[] = {
        {0, 0},                          // Top-left
        {CANVAS_WIDTH - 0, 0},         // Top-right (inset 10 pixels)
        {CANVAS_HEIGHT, CANVAS_WIDTH},  // Bottom-right
        {0, CANVAS_HEIGHT}              // Bottom-left
    };

    lv_draw_rect_dsc_t rect_dsc;
    lv_draw_rect_dsc_init(&rect_dsc);
    rect_dsc.bg_color = lv_color_hex(0xFFA500); // Orange
    rect_dsc.bg_opa = LV_OPA_COVER;

    lv_canvas_draw_polygon(canvas, points, 4, &rect_dsc);


    static lv_style_t style_MODE;
        lv_style_init(&style_MODE);
        lv_style_set_text_font(&style_MODE, &lv_font_montserrat_12);  // Only 2 args

    	lv_obj_t * text_MODE = lv_label_create(canvas);
    	lv_label_set_text(text_MODE, "MODE");
    	lv_obj_align(text_MODE, LV_ALIGN_TOP_LEFT, 5, 10);
    	lv_obj_add_style(text_MODE, &style_MODE, 0);  // Apply the style to all states

           lv_obj_add_flag(canvas, LV_OBJ_FLAG_CLICKABLE);

             // Attach event handler
             lv_obj_add_event_cb(canvas, mode_event_handler_canvas, LV_EVENT_ALL, NULL);

    //22222222222222//////////////////////////////////////////////


    lv_obj_t * canvas1 = lv_canvas_create(lv_scr_act());
//    lv_obj_set_style_bg_color(lv_scr_act(), lv_color_white(), 0);
 //   lv_obj_set_style_bg_opa(lv_scr_act(), LV_OPA_COVER, 0);

    lv_canvas_set_buffer(canvas1, cbuf1, CANVAS_WIDTH, CANVAS_HEIGHT, LV_IMG_CF_TRUE_COLOR);
    lv_obj_align(canvas1, LV_ALIGN_TOP_RIGHT, 0, 0);

    // Fill background transparent
    lv_canvas_fill_bg(canvas1, lv_color_white(), LV_OPA_0);

    // Define trapezoid points (clockwise)
    lv_point_t points1[] = {
        {0, 0},                          // Top-left
        {CANVAS_WIDTH - 0, 0},         // Top-right (inset 10 pixels)
        {CANVAS_WIDTH, CANVAS_HEIGHT},  // Bottom-right
        {35, CANVAS_HEIGHT}              // Bottom-left
    };

    lv_draw_rect_dsc_t rect_dsc1;
    lv_draw_rect_dsc_init(&rect_dsc1);
    rect_dsc1.bg_color = lv_color_hex(0x00FF00); // Orange
    rect_dsc1.bg_opa = LV_OPA_COVER;

    lv_canvas_draw_polygon(canvas1, points1, 4, &rect_dsc1);

    lv_obj_add_flag(canvas1, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(canvas1, TORCH_event_handler, LV_EVENT_ALL, NULL);

 	static lv_style_t style_TORCH;
    lv_style_init(&style_TORCH);
    lv_style_set_text_font(&style_TORCH, &lv_font_montserrat_12);  // Only 2 args
//
	lv_obj_t * TEXT_TORCH = lv_label_create(canvas1);
	lv_label_set_text(TEXT_TORCH, "TORCH");
	lv_obj_align(TEXT_TORCH, LV_ALIGN_TOP_RIGHT, -20, 10);
	lv_obj_add_style(TEXT_TORCH, &style_TORCH, 0);  // Apply the style to all states





	lv_obj_t *cont = lv_obj_create(lv_scr_act());
	lv_obj_set_size(cont, 125, 70);  // Adjust the size as needed
	lv_obj_align(cont, LV_ALIGN_TOP_LEFT, 5, 45);  // Align the container to the top-right corner
	lv_obj_set_style_border_width(cont, 2, LV_PART_MAIN);  // Set border width
	lv_obj_set_style_border_color(cont, lv_color_hex(0x000000), LV_PART_MAIN);  // Border color (blue)
	lv_obj_set_style_radius(cont, 10, LV_PART_MAIN);  // Rounded corners


 	static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_text_font(&style, &lv_font_montserrat_22);  // Only 2 args

 	static lv_style_t style0;
    lv_style_init(&style0);
    lv_style_set_text_font(&style0, &lv_font_montserrat_18);  // Only 2 args
	lv_obj_t * text = lv_label_create(lv_scr_act());

	snprintf(buf, sizeof(buf), "%.1f", wiresize);
	lv_label_set_text(text, buf);

	lv_obj_align(text, LV_ALIGN_TOP_LEFT, 55, 55);
    lv_obj_add_style(text, &style0, 0);  // Apply the style to all states

	lv_obj_t * text_wire_size = lv_label_create(lv_scr_act());
	lv_label_set_text(text_wire_size, "WIRE SIZE");
	lv_obj_align(text_wire_size, LV_ALIGN_TOP_LEFT, 35, 80);
	lv_obj_add_style(text_wire_size, &style, 0);
//    lv_obj_add_style(text_wire_size, &style, 0);  // Apply the style to all states

	lv_obj_add_event_cb(cont, WIRE_SIZE_event_handler, LV_EVENT_ALL, NULL);





	lv_obj_t *cont1 = lv_obj_create(lv_scr_act());
	lv_obj_set_size(cont1, 180, 70);  // Adjust the size as needed
	lv_obj_align(cont1, LV_ALIGN_TOP_MID, 0, 45);  // Align the container to the top-right corner
	lv_obj_set_style_border_width(cont1, 1, LV_PART_MAIN);  // Set border width
	lv_obj_set_style_border_color(cont1, lv_color_hex(0xFFA500), LV_PART_MAIN);  // Border color (ORENGE)
	lv_obj_set_style_radius(cont1, 10, LV_PART_MAIN);  // Rounded corners

 	static lv_style_t style1;
    lv_style_init(&style1);
    lv_style_set_text_font(&style1, &lv_font_montserrat_36);  // Only 2 args
	lv_obj_t * text1 = lv_label_create(cont1);

	snprintf(buf, sizeof(buf), "%.1f A", ampere);
	lv_label_set_text(text1, buf);

	lv_obj_align(text1, LV_ALIGN_TOP_MID, 0, -5);
	lv_obj_add_style(text1, &style1, 0);  // Apply the style to all states


	lv_obj_t *cont2 = lv_obj_create(lv_scr_act());
	lv_obj_set_size(cont2, 125, 70);  // Adjust the size as needed
	lv_obj_align(cont2, LV_ALIGN_TOP_RIGHT, -5, 45);  // Align the container to the top-right corner
	lv_obj_set_style_border_width(cont2, 2, LV_PART_MAIN);  // Set border width
	lv_obj_set_style_border_color(cont2, lv_color_hex(0x000000), LV_PART_MAIN);  // Border color (blue)
	lv_obj_set_style_radius(cont2, 10, LV_PART_MAIN);  // Rounded corners


 	static lv_style_t style2;
    lv_style_init(&style2);
    lv_style_set_text_font(&style2, &lv_font_montserrat_18);  // Only 2 args
	lv_obj_t * text2 = lv_label_create(cont2);

    snprintf(buf, sizeof(buf), "%.1f", wire_speed);
    lv_label_set_text(text2, buf);

	lv_obj_align(text2, LV_ALIGN_TOP_RIGHT, -30, -10);
	lv_obj_add_style(text2, &style2, 0);  // Apply the style to all states


	lv_obj_t * TEXT_WIRE_SPEED = lv_label_create(cont2);
	lv_label_set_text(TEXT_WIRE_SPEED, "WIRE SPD");
	lv_obj_align(TEXT_WIRE_SPEED, LV_ALIGN_TOP_RIGHT, -10, 15);
	lv_obj_add_style(TEXT_WIRE_SPEED, &style, 0);  // Apply the style to all states




	lv_obj_t *cont3 = lv_obj_create(lv_scr_act());
	lv_obj_set_size(cont3, 125, 70);  // Adjust the size as needed
	lv_obj_align(cont3, LV_ALIGN_BOTTOM_LEFT, 5, -80);  // Align the container to the top-right corner
	lv_obj_set_style_border_width(cont3, 2, LV_PART_MAIN);  // Set border width
	lv_obj_set_style_border_color(cont3, lv_color_hex(0x000000), LV_PART_MAIN);  // Border color (blue)
	lv_obj_set_style_radius(cont3, 10, LV_PART_MAIN);  // Rounded corners

	lv_obj_add_event_cb(cont3, MAT_THICK_event_handler, LV_EVENT_ALL, NULL);

 	static lv_style_t style3;
    lv_style_init(&style3);
    lv_style_set_text_font(&style3, &lv_font_montserrat_18);  // Only 2 args

	lv_obj_t * text3 = lv_label_create(cont3);

    snprintf(buf, sizeof(buf), "%.1f", mat_Thick);
    lv_label_set_text(text3, buf);

	lv_obj_align(text3, LV_ALIGN_LEFT_MID, 30, -15);
	lv_obj_add_style(text3, &style3, 0);  // Apply the style to all states

	lv_obj_t * TEXT_MAT_THICK = lv_label_create(cont3);
	lv_label_set_text(TEXT_MAT_THICK, "MAT THICK");
	lv_obj_align(TEXT_MAT_THICK, LV_ALIGN_LEFT_MID, 8, 5);
	lv_obj_add_style(TEXT_MAT_THICK, &style, 0);  // Apply the style to all states


	lv_obj_t *cont4 = lv_obj_create(lv_scr_act());
	lv_obj_set_size(cont4, 180, 70);  // Adjust the size as needed
	lv_obj_align(cont4, LV_ALIGN_BOTTOM_MID, 0, -80);  // Align the container to the top-right corner
	lv_obj_set_style_border_width(cont4, 1, LV_PART_MAIN);  // Set border width
	lv_obj_set_style_border_color(cont4, lv_color_hex(0xFFA500), LV_PART_MAIN);  // Border color (blue)
	lv_obj_set_style_radius(cont4, 10, LV_PART_MAIN);  // Rounded corners

 	static lv_style_t style4;
    lv_style_init(&style4);
    lv_style_set_text_font(&style4, &lv_font_montserrat_36);  // Only 2 args

	lv_obj_t * text4 = lv_label_create(cont4);

    snprintf(buf, sizeof(buf), "%.1f V", voltage);
    lv_label_set_text(text4, buf);

	lv_obj_align(text4, LV_ALIGN_BOTTOM_MID, 0, -5);
	lv_obj_add_style(text4, &style4, 0);  // Apply the style to all states

	lv_obj_t *cont5 = lv_obj_create(lv_scr_act());
	lv_obj_set_size(cont5, 125, 70);  // Adjust the size as needed
	lv_obj_align(cont5, LV_ALIGN_BOTTOM_RIGHT, -5, -80);  // Align the container to the top-right corner
	lv_obj_set_style_border_width(cont5, 2, LV_PART_MAIN);  // Set border width
	lv_obj_set_style_border_color(cont5, lv_color_hex(0x000000), LV_PART_MAIN);  // Border color (blue)
	lv_obj_set_style_radius(cont5, 10, LV_PART_MAIN);  // Rounded corners

 	static lv_style_t style5;
    lv_style_init(&style5);
    lv_style_set_text_font(&style5, &lv_font_montserrat_18);  // Only 2 args
	lv_obj_t * text5 = lv_label_create(cont5);

    snprintf(buf, sizeof(buf), "%.1f", arc_width);
    lv_label_set_text(text5, buf);

	lv_obj_align(text5, LV_ALIGN_BOTTOM_RIGHT, -28, -20);
	lv_obj_add_style(text5, &style5, 0);  // Apply the style to all states



	lv_obj_t * TEXT_ARC_WIDTH = lv_label_create(cont5);
	lv_label_set_text(TEXT_ARC_WIDTH, "ARC WIDTH");
	lv_obj_align(TEXT_ARC_WIDTH, LV_ALIGN_BOTTOM_RIGHT, 0, -5);
	lv_obj_add_style(TEXT_ARC_WIDTH, &style, 0);  // Apply the style to all states








    lv_obj_t * canvas2 = lv_canvas_create(lv_scr_act());
    lv_obj_set_style_bg_color(lv_scr_act(), lv_color_white(), 0);
    lv_obj_set_style_bg_opa(lv_scr_act(), LV_OPA_COVER, 0);

    lv_canvas_set_buffer(canvas2, cbuf2, CANVAS_WIDTH, CANVAS_HEIGHT, LV_IMG_CF_TRUE_COLOR);
    lv_obj_align(canvas2, LV_ALIGN_BOTTOM_LEFT, 0, 0);

    // Fill background transparent
    lv_canvas_fill_bg(canvas2, lv_color_white(), LV_OPA_0);

    // Define trapezoid points (clockwise)
    lv_point_t points2[] = {
        {0, 0},                          // Top-left
        {CANVAS_WIDTH - 35, 0},         // Top-right (inset 10 pixels)
        {CANVAS_WIDTH , CANVAS_HEIGHT},  // Bottom-right
        {0, CANVAS_HEIGHT}              // Bottom-left
    };

    lv_draw_rect_dsc_t rect_dsc2;
    lv_draw_rect_dsc_init(&rect_dsc2);
    rect_dsc2.bg_color = lv_color_hex(0xFFFF00); // Orange
    rect_dsc2.bg_opa = LV_OPA_COVER;

    lv_canvas_draw_polygon(canvas2, points2, 4, &rect_dsc2);

    lv_obj_t * canvas2_label = lv_label_create(canvas2);
    lv_label_set_text(canvas2_label, "KNOWLEDGE");
    lv_obj_set_style_bg_color(canvas2_label, lv_color_hex(0xFF0000), LV_PART_MAIN);
	lv_obj_align(canvas2_label, LV_ALIGN_BOTTOM_LEFT, 5, -10);
	lv_style_set_text_font(&style, &lv_font_montserrat_12);
	lv_obj_add_style(canvas2_label, &style, 0);  // Apply the style to all states


    lv_obj_t * canvas3 = lv_canvas_create(lv_scr_act());
    lv_obj_set_style_bg_color(lv_scr_act(), lv_color_white(), 0);
    lv_obj_set_style_bg_opa(lv_scr_act(), LV_OPA_COVER, 0);
    lv_obj_add_flag(canvas3, LV_OBJ_FLAG_CLICKABLE);
    lv_canvas_set_buffer(canvas3, cbuf3, CANVAS_WIDTH, CANVAS_HEIGHT, LV_IMG_CF_TRUE_COLOR);
    lv_obj_align(canvas3, LV_ALIGN_BOTTOM_RIGHT, 0, 0);

    // Fill background transparent
    lv_canvas_fill_bg(canvas3, lv_color_white(), LV_OPA_0);

    // Define trapezoid points (clockwise)
    lv_point_t points3[] = {
        {35, 0},                          // Top-left
        {CANVAS_WIDTH - 0, 0},         // Top-right (inset 10 pixels)
        {CANVAS_WIDTH , CANVAS_HEIGHT},  // Bottom-right
        {0, CANVAS_HEIGHT}              // Bottom-left
    };

    lv_draw_rect_dsc_t rect_dsc3;
    lv_draw_rect_dsc_init(&rect_dsc3);
    rect_dsc3.bg_color = lv_color_hex(0x87CEEB); // Orange
    rect_dsc3.bg_opa = LV_OPA_COVER;

    lv_canvas_draw_polygon(canvas3, points3, 4, &rect_dsc3);

    lv_obj_t * canvas3_label = lv_label_create(canvas3);
    lv_label_set_text(canvas3_label, "PROCESS");
    lv_obj_set_style_bg_color(canvas3_label, lv_color_hex(0xFF0000), LV_PART_MAIN);
	lv_obj_align(canvas3_label, LV_ALIGN_BOTTOM_RIGHT, -10,-10);
	lv_style_set_text_font(&style, &lv_font_montserrat_12);
	lv_obj_add_style(canvas3_label, &style, 0);  // Apply the style to all states
	lv_obj_clear_flag(canvas3_label, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_add_event_cb(canvas3, PROCESS_event_handler, LV_EVENT_ALL, NULL);
}

void handle_two_t_screen (void)
{


}

#endif
