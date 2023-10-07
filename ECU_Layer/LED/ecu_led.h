/* 
 * File:   ecu_led.h
 * Author: Mahmoud Elgendy
 *
 * Created on August 2, 2023, 11:01 PM
 */

#ifndef ECU_LED_H
#define	ECU_LED_H

/* Section : Includes */
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/* Section : Macro Declaration */

/* Section : Macro Function Declaration */

/* Section : Data Type Declaration */
typedef enum{
    LED_OFF,
    LED_ON
}led_state_t;

typedef struct{
    pin_config_t led_pin;
}led_t;
/* Section : Function Declaration */
STD_ReturnType led_initialize(const led_t *led);
STD_ReturnType led_on(const led_t *led);
STD_ReturnType led_off(const led_t *led);
STD_ReturnType led_toggle(const led_t *led);

#endif	/* ECU_LED_H */

