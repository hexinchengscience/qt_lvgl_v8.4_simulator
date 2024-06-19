#include "lvgl/lvgl.h"



/**
 * Create a button with a label and react on click event.
 */
void lvgl_example(void)
{	
	lv_obj_t * barcode_1 = lv_barcode_create(lv_scr_act());
	lv_obj_set_height(barcode_1, 50);
	lv_barcode_set_scale(barcode_1, 1);
	lv_barcode_set_dark_color(barcode_1, lv_color_hex(0x2C3224));
	lv_barcode_set_light_color(barcode_1, lv_color_hex(0xffffff));
	
	lv_barcode_update(barcode_1, "https://www.nxp.com/");
	lv_obj_set_pos(barcode_1, 39, 45);
	lv_obj_set_height(barcode_1, 50);
	
	
}
