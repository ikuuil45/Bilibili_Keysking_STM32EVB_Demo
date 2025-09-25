/*================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/
/**
 ******************************************************************************
 * @file    test.C
 * @author  Qeus Team
 * @version V1.0.0
 * @date    2025/09/25
 * @brief   This file tests GPIO toggle on pins 14 and 15
 ******************************************************************************
 */

#include <stdio.h>
#include "ql_gpio.h"
#include "ql_rtos.h"
#include "ql_application.h"
#include "ql_type.h"

#define test_log(fmt, args...)    printf(fmt, ##args)

void quec_gpio_toggle_test(void * argv)
{
    int ret = 0;
    
    test_log("quec_gpio_toggle_test start.\n");
    
    // Initialize GPIO_PIN_14 as output with pull disable and initial low level
    ret = ql_gpio_init(GPIO_PIN_NO_14, PIN_DIRECTION_OUT, PIN_PULL_DISABLE, PIN_LEVEL_LOW);
    if(ret < 0) {
        test_log("GPIO_PIN_NO_14 init failed, ret=%d\n", ret);
        return;
    }
    
    // Initialize GPIO_PIN_15 as output with pull disable and initial low level
    ret = ql_gpio_init(GPIO_PIN_NO_15, PIN_DIRECTION_OUT, PIN_PULL_DISABLE, PIN_LEVEL_LOW);
    if(ret < 0) {
        test_log("GPIO_PIN_NO_15 init failed, ret=%d\n", ret);
        return;
    }
    
    while(1) {
        // Toggle GPIO_PIN_14 to HIGH
        ret = ql_gpio_set_level(GPIO_PIN_NO_14, PIN_LEVEL_HIGH);
        if(ret == 0) {
            test_log("GPIO_PIN_14 set HIGH\n");
        }
        
        // Toggle GPIO_PIN_15 to HIGH  
        ret = ql_gpio_set_level(GPIO_PIN_NO_15, PIN_LEVEL_HIGH);
        if(ret == 0) {
            test_log("GPIO_PIN_15 set HIGH\n");
        }
        
        // Wait 1 second
        ql_rtos_task_sleep_s(1);
        
        // Toggle GPIO_PIN_14 to LOW
        ret = ql_gpio_set_level(GPIO_PIN_NO_14, PIN_LEVEL_LOW);
        if(ret == 0) {
            test_log("GPIO_PIN_14 set LOW\n");
        }
        
        // Toggle GPIO_PIN_15 to LOW
        ret = ql_gpio_set_level(GPIO_PIN_NO_15, PIN_LEVEL_LOW);
        if(ret == 0) {
            test_log("GPIO_PIN_15 set LOW\n");
        }
        
        // Wait 1 second
        ql_rtos_task_sleep_s(1);
    }
}

// Uncomment the line below to enable the application
// application_init(quec_gpio_toggle_test, "quec_gpio_toggle_test", 2, 0);
