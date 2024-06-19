#include "page_1.h"


/**********************
 *       WIDGETS
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/


lv_obj_t* button_1_ev_0;
static lv_obj_t * label;

static void btn_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * btn = lv_event_get_target(e);
    if(code == LV_EVENT_CLICKED) {
        static uint8_t cnt = 0;
        cnt++;

        /*Get the first child of the button which is the label and change its text*/
        lv_obj_t * label = lv_obj_get_child(btn, 0);
        lv_label_set_text_fmt(label, "Button: %d", cnt);
    }
}

static void slider_event_cb(lv_event_t * e)
{
    lv_obj_t * slider = lv_event_get_target(e);

    /*Refresh the text*/
    lv_label_set_text_fmt(label, "%"LV_PRId32, lv_slider_get_value(slider));
    lv_obj_align_to(label, slider, LV_ALIGN_OUT_TOP_MID, 0, -10);    /*Align top of the slider*/
}

lv_obj_t* page_1_create(){
    lv_obj_t *parent = lv_obj_create(NULL);
//    static lv_style_t style;
    lv_color32_t col ; col.full = 0xFF8080 ;

//    lv_style_init(&style);
//    col.full = 0xFF0000 ; lv_style_set_bg_color(&style, col);
//    col.full = 0x00FF00 ; lv_style_set_border_color(&style, col);
//    lv_style_set_border_width(&style, 2);

//    lv_obj_add_style(parent , &style , 0) ;

    lv_obj_set_style_bg_color(parent, col , LV_PART_MAIN);

    lv_obj_t * btn = lv_btn_create(parent);     /*Add a button the current screen*/
    lv_obj_set_pos(btn, 50, 50);                            /*Set its position*/
    lv_obj_set_size(btn, 120, 50);                          /*Set its size*/
    lv_obj_add_event_cb(btn, btn_event_cb, LV_EVENT_ALL, NULL);

    lv_obj_t * label1 = lv_label_create(btn);          /*Add a label to the button*/
    lv_label_set_text(label1, "Button");                     /*Set the labels text*/
    lv_obj_center(label1);

    lv_obj_t * sw = lv_switch_create(parent);
    lv_obj_center(sw);
    lv_obj_add_state(sw, LV_STATE_DEFAULT);
    //lv_obj_add_event_cb(sw, sw_event_cb, LV_EVENT_VALUE_CHANGED, label);

    lv_obj_t * slider = lv_slider_create(parent);
    lv_slider_set_range(slider , 0 , 400) ;
    lv_obj_set_pos(slider, 20, 120);                            /*Set its position*/
    lv_obj_set_size(slider, 400, 10);                          /*Set its size*/
    lv_obj_add_event_cb(slider, slider_event_cb, LV_EVENT_VALUE_CHANGED, NULL);     /*Assign an event function*/
    label = lv_label_create(parent);
    lv_label_set_text(label, "0");
    lv_obj_align_to(label, slider, LV_ALIGN_OUT_TOP_MID, 0, -10);


    lv_scr_load(parent);
    return parent;

}
