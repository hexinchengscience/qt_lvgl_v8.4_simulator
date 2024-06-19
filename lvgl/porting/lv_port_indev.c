/**
 * @file lv_port_indev_templ.c
 *
 */

/*Copy this file as "lv_port_indev.c" and set this value to "1" to enable content*/
#if 1

/*********************
 *      INCLUDES
 *********************/
#include "lv_port_indev.h"


int16_t TouchFlag = 0 , TouchX = 0 , TouchY = 0 ;

//! 硬件触摸位置读取-----------------------------------------------------------------------
void Touch_Read(struct _lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    LV_UNUSED(indev_drv);


    //! TouchFlag = 1 表示按下   0 表示释放------------------------------------------------
    data->state = TouchFlag ? LV_INDEV_STATE_PR : LV_INDEV_STATE_REL ;


    data->point.x = TouchX ;
    data->point.y = TouchY ;
}

void lv_port_indev_init(void)
{
    /**
     * Here you will find example implementation of input devices supported by LittelvGL:
     *  - Touchpad
     *  - Mouse (with cursor support)
     *  - Keypad (supports GUI usage only with key)
     *  - Encoder (supports GUI usage only with: left, right, push)
     *  - Button (external buttons to press points on the screen)
     *
     *  The `..._read()` function are only examples.
     *  You should shape them according to your hardware
     */

    static lv_indev_drv_t indev_drv;

    /*------------------
     * Touchpad
     * -----------------*/


    /*Register a touchpad input device*/
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = Touch_Read;
    lv_indev_drv_register(&indev_drv);

}



#endif
