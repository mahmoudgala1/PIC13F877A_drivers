/* 
 * File:   ecu_relay.c
 * Author: Mahmoud Elgendy
 *
 * Created on August 18, 2023, 5:59 PM
 */
#include "ecu_relay.h"
/**
 * 
 * @param relay
 * @return 
 */
STD_ReturnType relay_initialize(const relay_t *relay){
    STD_ReturnType ret =E_OK;
    if(NULL == relay){
        ret = E_NOT_OK;
    }else{
        gpio_pin_initialize(&(relay->relay_pin));
    }
    return ret;
}
/**
 * 
 * @param relay
 * @return 
 */
STD_ReturnType relay_turn_off(const relay_t *relay){
    STD_ReturnType ret =E_OK;
    if(NULL == relay){
        ret = E_NOT_OK;
    }else{
        gpio_pin_write_logic(&(relay->relay_pin), GPIO_LOW);
    }
    return ret;
}
/**
 * 
 * @param relay
 * @return 
 */
STD_ReturnType relay_turn_on(const relay_t *relay){
    STD_ReturnType ret =E_OK;
    if(NULL == relay){
        ret = E_NOT_OK;
    }else{
        gpio_pin_write_logic(&(relay->relay_pin), GPIO_HIGH);
    }
    return ret;
}