#include "lvgl/lvgl.h"

static lv_obj_t * label;

static void slider_event_cb(lv_event_t * e)
{
    lv_obj_t * slider = lv_event_get_target(e);

    /*Refresh the text*/
    lv_label_set_text_fmt(label, "%d", lv_slider_get_value(slider));
    lv_obj_align_to(label, slider, LV_ALIGN_OUT_TOP_MID, 0, -10);    /*Align top of the slider*/
}
/**
 * Create a button with a label and react on click event.
 */
void lvgl_example(void)
{
    /*Create a slider in the center of the display*/
    lv_obj_t * slider = lv_slider_create(lv_scr_act());
    lv_slider_set_range(slider , 0 , 400) ;
    lv_obj_set_pos(slider, 20, 120);                            /*Set its position*/
    lv_obj_set_size(slider, 400, 10);                           /*Set its size*/
    lv_obj_add_event_cb(slider, slider_event_cb, LV_EVENT_VALUE_CHANGED, NULL);     /*Assign an event function*/

    /*Create a label above the slider*/
    label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "0");
    lv_obj_align_to(label, slider, LV_ALIGN_OUT_TOP_MID, 0, -10);    /*Align top of the slider*/
}
