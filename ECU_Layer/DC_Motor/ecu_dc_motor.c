
/* 
 * File:   ecu_dc_motor.c
 * Author: Mahmoud Elgendy
 *
 * Created on August 19, 2023, 2:02 PM
 */
#include "ecu_dc_motor.h"

/**
 * 
 * @param dc_motor
 * @return 
 */
STD_ReturnType dc_motor_initialize(const dc_motor_t *dc_motor) {
    STD_ReturnType ret = E_OK;
    if (NULL == dc_motor) {
        ret = E_NOT_OK;
    } else {
        gpio_pin_initialize(&(dc_motor->dc_motor_pins[0]));
        gpio_pin_initialize(&(dc_motor->dc_motor_pins[1]));
    }
    return ret;
}

/**
 * 
 * @param dc_motor
 * @return 
 */
STD_ReturnType dc_motor_move_forword(const dc_motor_t *dc_motor) {
    STD_ReturnType ret = E_OK;
    if (NULL == dc_motor) {
        ret = E_NOT_OK;
    } else {
        gpio_pin_write_logic(&(dc_motor->dc_motor_pins[0]), GPIO_HIGH);
        gpio_pin_write_logic(&(dc_motor->dc_motor_pins[1]), GPIO_LOW);
    }
    return ret;
}

/**
 * 
 * @param dc_motor
 * @return 
 */
STD_ReturnType dc_motor_move_reverse(const dc_motor_t *dc_motor) {
    STD_ReturnType ret = E_OK;
    if (NULL == dc_motor) {
        ret = E_NOT_OK;
    } else {
        gpio_pin_write_logic(&(dc_motor->dc_motor_pins[0]), GPIO_LOW);
        gpio_pin_write_logic(&(dc_motor->dc_motor_pins[1]), GPIO_HIGH);
    }
    return ret;
}

/**
 * 
 * @param dc_motor
 * @return 
 */
STD_ReturnType dc_motor_stop(const dc_motor_t *dc_motor) {
    STD_ReturnType ret = E_OK;
    if (NULL == dc_motor) {
        ret = E_NOT_OK;
    } else {
        gpio_pin_write_logic(&(dc_motor->dc_motor_pins[0]), GPIO_LOW);
        gpio_pin_write_logic(&(dc_motor->dc_motor_pins[1]), GPIO_LOW);
    }
    return ret;
}