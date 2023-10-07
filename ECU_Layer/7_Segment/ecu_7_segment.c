/* 
 * File:   ecu_7_segment.h
 * Author: Mahmoud Elgendy
 *
 * Created on August 19, 2023, 4:09 PM
 */
#include "ecu_7_segment.h"

/**
 * 
 * @param segment
 * @return 
 */
STD_ReturnType seven_segment_initialize(const segment_t *segment) {
    STD_ReturnType ret = E_OK;
    if (NULL == segment) {
        ret = E_NOT_OK;
    } else {
        for (uint8 segment_pin = 0; segment_pin < 4; segment_pin++) {
            gpio_pin_initialize(&(segment->segment_pins[segment_pin]));
        }
    }
    return ret;
}

/**
 * 
 * @param segment
 * @param number
 * @return 
 */
STD_ReturnType seven_segment_write_number(const segment_t *segment, uint8 number) {
    STD_ReturnType ret = E_OK;
    if (NULL == segment) {
        ret = E_NOT_OK;
    } else {
        gpio_pin_write_logic(&(segment->segment_pins[SEVEN_SEGMENT_PIN_0]), number & 0x01);
        gpio_pin_write_logic(&(segment->segment_pins[SEVEN_SEGMENT_PIN_1]), (number >> 1) & 0x01);
        gpio_pin_write_logic(&(segment->segment_pins[SEVEN_SEGMENT_PIN_2]), (number >> 2) & 0x01);
        gpio_pin_write_logic(&(segment->segment_pins[SEVEN_SEGMENT_PIN_3]), (number >> 3) & 0x01);
    }
    return ret;
}
