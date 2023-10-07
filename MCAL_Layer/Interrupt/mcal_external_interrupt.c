
/* 
 * File:   mcal_external_interrupt.c
 * Author: Mahmoud Elgendy
 *
 * Created on September 18, 2023, 10:31 PM
 */
#include "mcal_external_interrupt.h"
static void (* INT_InterruptHandler)(void);

static void (* RB4_InterruptHandler_High)(void);
static void (* RB4_InterruptHandler_Low)(void);
static void (* RB5_InterruptHandler_High)(void);
static void (* RB5_InterruptHandler_Low)(void);
static void (* RB6_InterruptHandler_High)(void);
static void (* RB6_InterruptHandler_Low)(void);
static void (* RB7_InterruptHandler_High)(void);
static void (* RB7_InterruptHandler_Low)(void);

void INT_ISR(void) {
    EXTERNAL_INT_INTERRUPT_CLEAR_FLAG();
    if (INT_InterruptHandler) {
        INT_InterruptHandler();
    }
}

void RB4_ISR(uint8 RB4_Source) {
    EXTERNAL_RBX_INTERRUPT_CLEAR_FLAG();
    if (0 == RB4_Source) {
        if (RB4_InterruptHandler_High) {
            RB4_InterruptHandler_High();
        }
    } else if (1 == RB4_Source) {
        if (RB4_InterruptHandler_Low) {
            RB4_InterruptHandler_Low();
        }
    } else {
        /*NoThing*/
    }
}

void RB5_ISR(uint8 RB5_Source) {
    EXTERNAL_RBX_INTERRUPT_CLEAR_FLAG();
    if (0 == RB5_Source) {
        if (RB5_InterruptHandler_High) {
            RB5_InterruptHandler_High();
        }
    } else if (1 == RB5_Source) {
        if (RB5_InterruptHandler_Low) {
            RB5_InterruptHandler_Low();
        }
    } else {
        /*NoThing*/
    }
}

void RB6_ISR(uint8 RB6_Source) {
    EXTERNAL_RBX_INTERRUPT_CLEAR_FLAG();
    if (0 == RB6_Source) {
        if (RB6_InterruptHandler_High) {
            RB6_InterruptHandler_High();
        }
    } else if (1 == RB6_Source) {
        if (RB6_InterruptHandler_Low) {
            RB6_InterruptHandler_Low();
        }
    } else {
        /*NoThing*/
    }
}

void RB7_ISR(uint8 RB7_Source) {
    EXTERNAL_RBX_INTERRUPT_CLEAR_FLAG();
    if (0 == RB7_Source) {
        if (RB7_InterruptHandler_High) {
            RB7_InterruptHandler_High();
        }
    } else if (1 == RB7_Source) {
        if (RB7_InterruptHandler_Low) {
            RB7_InterruptHandler_Low();
        }
    } else {
        /*NoThing*/
    }
}

/**
 * 
 * @param int_pbj
 * @return 
 */
STD_ReturnType Interrupt_INT_Init(const external_interrupt_INT_t *int_obj) {
    STD_ReturnType ret = E_OK;
    if (NULL == int_obj) {
        ret = E_NOT_OK;
    } else {
        EXTERNAL_INT_INTERRUPT_DISABLE();
        EXTERNAL_INT_INTERRUPT_CLEAR_FLAG();
        switch (int_obj->edge) {
            case INTERRUPT_FALLING_EDGE:
                EXTERNAL_INT_FALLING_EDGE_SET();
                break;
            case INTERRUPT_RISING_EDGE:
                EXTERNAL_INT_RISING_EDGE_SET();
                break;
            default:
                break;
        }
        gpio_pin_direction_initialize(&(int_obj->mcu_pin));
        INT_InterruptHandler = int_obj->Ex_InterruptHandler;
        INTERRUPT_PeripheralInterruptEnable();
        INTERRUPT_GlobalInterruptEnable();
        EXTERNAL_INT_INTERRUPT_ENABLE();
    }
    return ret;
}

/**
 * 
 * @param int_pbj
 * @return 
 */
STD_ReturnType Interrupt_INT_Denit(const external_interrupt_INT_t *int_obj) {
    STD_ReturnType ret = E_OK;
    if (NULL == int_obj) {
        ret = E_NOT_OK;
    } else {
        EXTERNAL_INT_INTERRUPT_DISABLE();
    }
    return ret;
}

/**
 * 
 * @param int_obj
 * @return 
 */
STD_ReturnType Interrupt_RBX_Init(const external_interrupt_RBX_t *int_obj) {
    STD_ReturnType ret = E_OK;
    if (NULL == int_obj) {
        ret = E_NOT_OK;
    } else {
        EXTERNAL_RBX_INTERRUPT_DISABLE();
        EXTERNAL_RBX_INTERRUPT_CLEAR_FLAG();
        gpio_pin_direction_initialize(&(int_obj->mcu_pin));
        switch (int_obj->mcu_pin.pin) {
            case GPIO_PIN4:
                RB4_InterruptHandler_High = int_obj->EXT_InterruptHandler_High;
                RB4_InterruptHandler_Low = int_obj->EXT_InterruptHandler_Low;
                break;
            case GPIO_PIN5:
                RB5_InterruptHandler_High = int_obj->EXT_InterruptHandler_High;
                RB5_InterruptHandler_Low = int_obj->EXT_InterruptHandler_Low;
                break;
            case GPIO_PIN6:
                RB6_InterruptHandler_High = int_obj->EXT_InterruptHandler_High;
                RB6_InterruptHandler_Low = int_obj->EXT_InterruptHandler_Low;
                break;
            case GPIO_PIN7:
                RB7_InterruptHandler_High = int_obj->EXT_InterruptHandler_High;
                RB7_InterruptHandler_Low = int_obj->EXT_InterruptHandler_Low;
                break;
            default:
                break;
        }
        INTERRUPT_PeripheralInterruptEnable();
        INTERRUPT_GlobalInterruptEnable();
        EXTERNAL_RBX_INTERRUPT_ENABLE();
    }
    return ret;
}

/**
 * 
 * @param int_obj
 * @return 
 */
STD_ReturnType Interrupt_RBX_DeInit(const external_interrupt_RBX_t *int_obj) {
    STD_ReturnType ret = E_OK;
    if (NULL == int_obj) {
        ret = E_NOT_OK;
    } else {
        EXTERNAL_RBX_INTERRUPT_DISABLE();
    }
    return ret;
}
