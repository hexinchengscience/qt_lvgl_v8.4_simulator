#include "lvgl/lvgl.h"


/**
 * Create a button with a label and react on click event.
 */
void lvgl_example(void)
{
    static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_radius(&style, 5);

    /*Make a gradient*/
    lv_style_set_bg_opa(&style, LV_OPA_COVER);
    static lv_grad_dsc_t grad;
    grad.dir = LV_GRAD_DIR_VER;
    grad.stops_count = 2;
    grad.stops[0].color = lv_palette_lighten(LV_PALETTE_GREY, 1);
    grad.stops[1].color = lv_palette_main(LV_PALETTE_BLUE);

    /*Shift the gradient to the bottom*/
    grad.stops[0].frac  = 128;
    grad.stops[1].frac  = 192;

    lv_style_set_bg_grad(&style, &grad);

    /*Create an object with the new style*/
    //lv_obj_t * obj = lv_obj_create(lv_scr_act());
    lv_obj_t * obj = lv_scr_act() ;
    //lv_obj_set_pos(obj, 0, 0);                            /*Set its position*/
    //lv_obj_set_size(obj, 480, 320);                          /*Set its size*/
    lv_obj_add_style(obj, &style, 0);

    //lv_obj_center(obj);
}
