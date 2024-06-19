#include "lvgl/lvgl.h"

#include "ImageMap.c"

/**
 * Create a button with a label and react on click event.
 */
void lvgl_example(void)
{
    /*Create an object with the new style*/
    lv_obj_t * obj = lv_img_create(lv_scr_act());
    
    lv_img_set_src(obj, &ImgDefault);

    lv_obj_center(obj);
}
