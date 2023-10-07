/* 
 * File:   hal_gpio.h
 * Author: Mahmoud Elgendy
 *
 * Created on August 2, 2023, 10:48 PM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

/* Section : Includes */
#include "pic16f877a.h"
#include "../std-types.h"
#include "../device_config.h"

/* Section : Macro Declaration */
#define BIT_MASK (uint8)1
#define PORT_MAX_NUMBER  5
#define PORT_PIN_B_C_D_MAX_NUMBER  8
#define PORT_PIN_A_MAX_NUMBER  6
#define PORT_PIN_E_MAX_NUMBER  3

/* Section : Macro Function Declaration */
#define SET_BIT(REG, BIT_POSN)    (REG |= (BIT_MASK << BIT_POSN))
#define CLEAR_BIT(REG, BIT_POSN)  (REG &= ~(BIT_MASK << BIT_POSN))
#define TOGGLE_BIT(REG, BIT_POSN) (REG ^= (BIT_MASK << BIT_POSN))
#define READ_BIT(REG, BIT_POSN)   ((REG >> BIT_POSN) & BIT_MASK)

/* Section : Data Type Declaration */
typedef enum{
    GPIO_LOW,
    GPIO_HIGH
}logic_t;

typedef enum{
    GPIO_DIRECTION_INPUT,
    GPIO_DIRECTION_OUTPUT
}direction_t;

typedef enum{
    GPIO_PIN0=0,
    GPIO_PIN1,
    GPIO_PIN2,
    GPIO_PIN3,
    GPIO_PIN4,
    GPIO_PIN5,
    GPIO_PIN6,
    GPIO_PIN7
}pin_index_t;

typedef enum{
    PORTA_INDEX=0,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX
}port_index_t;

typedef struct{
    uint8 port : 3;
    uint8 pin : 3;
    uint8 direction : 1;
    uint8 logic : 1;
}pin_config_t;

/* Section : Function Declaration */
STD_ReturnType gpio_pin_direction_initialize(const pin_config_t *_pin_config);
STD_ReturnType gpio_pin_initialize(const pin_config_t *_pin_config);
STD_ReturnType gpio_pin_get_direction_status(const pin_config_t *_pin_config, direction_t *direction_status);
STD_ReturnType gpio_pin_write_logic(const pin_config_t *_pin_config, logic_t logic);
STD_ReturnType gpio_pin_read_logic(const pin_config_t *_pin_config, logic_t *logic);
STD_ReturnType gpio_pin_toggle_logic(const pin_config_t *_pin_config);

STD_ReturnType gpio_port_direction_initialize( port_index_t port, uint8 direction);
STD_ReturnType gpio_port_get_direction_status( port_index_t port, uint8 *direction_status);
STD_ReturnType gpio_port_write_logic( port_index_t port, uint8 logic);
STD_ReturnType gpio_port_read_logic( port_index_t port,uint8 *logic);
STD_ReturnType gpio_port_toggle_logic( port_index_t port);

#endif	/* HAL_GPIO_H */

