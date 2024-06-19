#include "lvgl/lvgl.h"

lv_obj_t * screen_analog_clock_1 ;

void AnalogClock_Set_Time(int32_t hour, int32_t min, int32_t sec)
{
    lv_analogclock_set_time(screen_analog_clock_1, hour , min , sec);
}

/**
 * Create a button with a label and react on click event.
 */
void lvgl_example(void)
{	
    //Write codes screen_analog_clock_1
    screen_analog_clock_1 = lv_analogclock_create(lv_scr_act());
    lv_analogclock_hide_digits(screen_analog_clock_1, false);
    lv_analogclock_set_major_ticks(screen_analog_clock_1, 2, 10, lv_color_hex(0x555555), 10);
    lv_analogclock_set_ticks(screen_analog_clock_1, 2, 5, lv_color_hex(0x333333));
    lv_analogclock_set_hour_needle_line(screen_analog_clock_1, 2, lv_color_hex(0x00ff00), -40);
    lv_analogclock_set_min_needle_line(screen_analog_clock_1, 2, lv_color_hex(0xFF0000), -30);
    lv_analogclock_set_sec_needle_line(screen_analog_clock_1, 2, lv_color_hex(0x6600FF), -10);
    lv_analogclock_set_time(screen_analog_clock_1, 5, 3,30);

    lv_obj_set_pos(screen_analog_clock_1, 90, 10);
    lv_obj_set_size(screen_analog_clock_1, 300, 300);
    //lv_obj_center(screen_analog_clock_1);

    //Write style for screen_analog_clock_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(screen_analog_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(screen_analog_clock_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(screen_analog_clock_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(screen_analog_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(screen_analog_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_analog_clock_1, Part: LV_PART_TICKS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(screen_analog_clock_1, lv_color_hex(0xff0000), LV_PART_TICKS|LV_STATE_DEFAULT);
    //lv_obj_set_style_text_font(screen_analog_clock_1, &lv_font_simsun_16_cjk, LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(screen_analog_clock_1, 255, LV_PART_TICKS|LV_STATE_DEFAULT);

    //Write style for screen_analog_clock_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(screen_analog_clock_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(screen_analog_clock_1, lv_color_hex(0x000000), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(screen_analog_clock_1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
}
