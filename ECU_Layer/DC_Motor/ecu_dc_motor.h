/* 
 * File:   ecu_dc_motor.h
 * Author: Mahmoud Elgendy
 *
 * Created on August 19, 2023, 2:02 PM
 */

#ifndef ECU_DC_MOTOR_H
#define	ECU_DC_MOTOR_H

/* Section : Includes */
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/* Section : Macro Declaration */

/* Section : Macro Function Declaration */

/* Section : Data Type Declaration */
typedef enum{
    DC_MOTOR_OFF_STATE,
    DC_MOTOR_ON_STATE        
}dc_motor_state_t;

typedef struct{
    pin_config_t dc_motor_pins[2];
}dc_motor_t;

/* Section : Function Declaration */
STD_ReturnType dc_motor_initialize(const dc_motor_t *dc_motor);
STD_ReturnType dc_motor_move_forword(const dc_motor_t *dc_motor);
STD_ReturnType dc_motor_move_reverse(const dc_motor_t *dc_motor);
STD_ReturnType dc_motor_stop(const dc_motor_t *dc_motor);


#endif	/* ECU_DC_MOTOR_H */

