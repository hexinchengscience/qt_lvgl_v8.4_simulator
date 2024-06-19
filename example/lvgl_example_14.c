#include "lvgl/lvgl.h"



/**
 * Create a button with a label and react on click event.
 */
void lvgl_example(void)
{
    lv_obj_t * img = lv_img_create(lv_scr_act());
    /* Assuming a File system is attached to letter 'A'
     * E.g. set LV_USE_FS_STDIO 'A' in lv_conf.h */

    lv_img_set_src(img, "PC:/ProgramCode/QT/Image_LVGL_V8.4/image2/image/example/wink.png");

    lv_obj_center(img);
}
