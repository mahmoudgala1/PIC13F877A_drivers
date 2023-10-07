/* 
 * File:   ecu_relay.h
 * Author: Mahmoud Elgendy
 *
 * Created on August 18, 2023, 5:59 PM
 */

#ifndef ECU_RELAY_H
#define	ECU_RELAY_H

/* Section : Includes */
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/* Section : Macro Declaration */

/* Section : Macro Function Declaration */

/* Section : Data Type Declaration */
typedef enum {
    RELAY_OFF_STATE,
    RELAY_ON_STATE
} relay_state_t;

typedef struct{
    pin_config_t relay_pin;
}relay_t;

/* Section : Function Declaration */
STD_ReturnType relay_initialize(const relay_t *relay);
STD_ReturnType relay_turn_off(const relay_t *relay);
STD_ReturnType relay_turn_on(const relay_t *relay);

#endif	/* ECU_RELAY_H */

