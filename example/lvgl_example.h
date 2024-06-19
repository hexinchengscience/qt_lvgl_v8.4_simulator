#ifndef APP_H
#define APP_H

#ifdef __cplusplus
extern "C" {
#endif

/**********************
 *      INCLUDES
 **********************/

#include "lvgl.h"


void AnalogClock_Set_Time(int32_t hour, int32_t min, int32_t sec) ;
void lvgl_example(void);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*APP_H*/
