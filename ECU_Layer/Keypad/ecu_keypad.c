/* 
 * File:   ecu_keypad.h
 * Author: Mahmoud Elgendy
 *
 * Created on August 20, 2023, 10:37 PM
 */
#include "ecu_keypad.h"

/**
 * 
 * @param _keypad
 * @return 
 */

/*static const uint8 btn_values[MAX_ROW_PINS][MAX_COLUMN_PINS] = {
    {'7', '8', '9', '/'},
    {'4', '5', '6', '*'},
    {'1', '2', '3', '-'},
    {'#', '0', '=', '+'}
};*/
static const uint8 btn_values[MAX_ROW_PINS][MAX_COLUMN_PINS] = {
    {'1', '2', '3', '/'},
    {'4', '5', '6', '*'},
    {'7', '8', '9', '-'},
    {'#', '0', '=', '+'}
};

STD_ReturnType keypad_initialize(const keypad_t *_keypad) {
    STD_ReturnType ret = E_OK;
    uint8 l_counter = 0;
    if (NULL == _keypad) {
        ret = E_NOT_OK;
    } else {
        for (l_counter = 0; l_counter < MAX_ROW_PINS; l_counter++) {
            gpio_pin_initialize(&(_keypad->keypad_row_pins[l_counter]));
            gpio_pin_direction_initialize(&(_keypad->keypad_column_pins[l_counter]));
        }
    }
    return ret;
}

/**
 * 
 * @param _keypad
 * @param value
 * @return 
 */
STD_ReturnType keypad_get_value(const keypad_t *_keypad, uint8 *value) {
    STD_ReturnType ret = E_OK;
    uint8 l_counter = 0, l_row_counter = 0, l_column_counter = 0;
    logic_t column_logic = GPIO_LOW;
    *value = NOT_PRESSED;
    if ((NULL == _keypad) || (NULL == value)) {
        ret = E_NOT_OK;
    } else {
        for (l_row_counter = 0; l_row_counter < MAX_ROW_PINS; l_row_counter++) {
            for (l_counter = 0; l_counter < MAX_ROW_PINS; l_counter++) {
                gpio_pin_write_logic(&(_keypad->keypad_row_pins[l_counter]), GPIO_LOW);
            }
            gpio_pin_write_logic(&(_keypad->keypad_row_pins[l_row_counter]), GPIO_HIGH);
            __delay_ms(20);
            for (l_column_counter = 0; l_column_counter < MAX_COLUMN_PINS; l_column_counter++) {
                gpio_pin_read_logic(&(_keypad->keypad_column_pins[l_column_counter]), &column_logic);
                if (GPIO_HIGH == column_logic) {
                    while (GPIO_HIGH == column_logic) {
                        gpio_pin_read_logic(&(_keypad->keypad_column_pins[l_column_counter]), &column_logic);
                    }
                    *value = btn_values[l_row_counter][l_column_counter];
                }
            }
        }

    }
    return ret;
}
