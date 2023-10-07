/* 
 * File:   ecu_led.c
 * Author: Mahmoud Elgendy
 *
 * Created on August 2, 2023, 11:01 PM
 */
#include "ecu_led.h"
/**
 * 
 * @param led
 * @return 
 */
STD_ReturnType led_initialize(const led_t *led){
    STD_ReturnType ret =E_OK;
    if(NULL == led){
        ret = E_NOT_OK;
    }else{
        gpio_pin_initialize(led);
    }
    return ret;
}
/**
 * 
 * @param led
 * @return 
 */
STD_ReturnType led_on(const led_t *led){
    STD_ReturnType ret =E_OK;
    if(NULL == led){
        ret = E_NOT_OK;
    }else{
        gpio_pin_write_logic(led, GPIO_HIGH);
    }
    return ret;
}
/**
 * 
 * @param led
 * @return 
 */
STD_ReturnType led_off(const led_t *led){
    STD_ReturnType ret =E_OK;
    if(NULL == led){
        ret = E_NOT_OK;
    }else{
        gpio_pin_write_logic(led, GPIO_LOW);
    }
    return ret;
}
/**
 * 
 * @param led
 * @return 
 */
STD_ReturnType led_toggle(const led_t *led){
    STD_ReturnType ret =E_OK;
    if(NULL == led){
        ret = E_NOT_OK;
    }else{
        gpio_pin_toggle_logic(led);
    }
    return ret;
}