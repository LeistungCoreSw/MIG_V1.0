#include "../../lv_examples.h"
#if LV_USE_IMG && LV_BUILD_EXAMPLES


void lv_example_img_1(void)
{
//	   LV_IMG_DECLARE(return_12);
//    	lv_obj_t * img1 = lv_img_create(lv_scr_act());
//       lv_img_set_src(img1, &return_12 );
//       lv_obj_align(img1, LV_ALIGN_TOP_LEFT, 35, 4);
//       lv_obj_set_size(img1, 36, 35);
//
//       lv_obj_add_flag(img1, LV_OBJ_FLAG_CLICKABLE);
//
//         // Attach event handler
//         lv_obj_add_event_cb(img1, return_img_event_handler, LV_EVENT_ALL, NULL);

//
//       LV_IMG_DECLARE(lc_logo);
//       lv_obj_t * img2 = lv_img_create(lv_scr_act());
//       lv_img_set_src(img2, &lc_logo );
//       lv_obj_align(img2, LV_ALIGN_TOP_MID, 0, 0);
//       lv_obj_set_size(img2, 25, 25);

    	static lv_style_t style_NAME_LOGO;
        lv_style_init(&style_NAME_LOGO);
        lv_style_set_text_font(&style_NAME_LOGO, &lv_font_montserrat_18);  // Only 2 args

    	lv_obj_t * text_NAME = lv_label_create(lv_scr_act());
    	lv_label_set_text(text_NAME, "Leistung Core");
    	lv_obj_align(text_NAME, LV_ALIGN_TOP_MID, 5, 5);
    	lv_style_set_text_color(&style_NAME_LOGO, lv_color_hex(0xFF0000)); // Red text
    	lv_obj_add_style(text_NAME, &style_NAME_LOGO, 0);  // Apply the style to all states

}
//void create_new_page(void)
//{
//    lv_obj_t * new_scr = lv_obj_create(NULL);  // Create a new blank screen
//    lv_obj_clear_flag(new_scr, LV_OBJ_FLAG_SCROLLABLE);
//
//    lv_obj_t * label = lv_label_create(new_scr);
//    lv_label_set_text(label, "This is the new page!");
//    lv_obj_center(label);
//
//    lv_scr_load(new_scr);  // Load the new screen
//}
#endif
