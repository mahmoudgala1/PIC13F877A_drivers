/* 
 * File:   mcal_external_interrupt.h
 * Author: Mahmoud Elgendy
 *
 * Created on September 18, 2023, 10:31 PM
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_H
#define	MCAL_EXTERNAL_INTERRUPT_H

/* Section : Includes */
#include "mcal_interrupt_config.h"
/* Section : Macro Declaration */

/* Section : Macro Function Declaration */
#if EXTERNAL_INTERRUPT_INT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
#define EXTERNAL_INT_INTERRUPT_ENABLE()           (INTCONbits.INTE=1)
#define EXTERNAL_INT_INTERRUPT_DISABLE()          (INTCONbits.INTE=0)
#define EXTERNAL_INT_INTERRUPT_CLEAR_FLAG()       (INTCONbits.INTF=0)
#define EXTERNAL_INT_RISING_EDGE_SET()            (OPTION_REGbits.INTEDG=1)
#define EXTERNAL_INT_FALLING_EDGE_SET()           (OPTION_REGbits.INTEDG=0)
#endif
#if EXTERNAL_INTERRUPT_ONCHANGE_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
#define EXTERNAL_RBX_INTERRUPT_ENABLE()      (INTCONbits.RBIE=1)
#define EXTERNAL_RBX_INTERRUPT_DISABLE()     (INTCONbits.RBIE=0)
#define EXTERNAL_RBX_INTERRUPT_CLEAR_FLAG()  (INTCONbits.RBIF=0)
#endif
/* Section : Data Type Declaration */
typedef enum {
    INTERRUPT_FALLING_EDGE = 0,
    INTERRUPT_RISING_EDGE
} external_interrupt_INT_edge;
typedef struct{
    void (* Ex_InterruptHandler)(void);
    pin_config_t mcu_pin;
    external_interrupt_INT_edge edge;
}external_interrupt_INT_t;
typedef struct{
    void (* EXT_InterruptHandler_High)(void);
    void (* EXT_InterruptHandler_Low)(void);
    pin_config_t mcu_pin;
}external_interrupt_RBX_t;
/* Section : Function Declaration */
STD_ReturnType Interrupt_INT_Init(const external_interrupt_INT_t *int_obj);
STD_ReturnType Interrupt_INT_Denit(const external_interrupt_INT_t *int_obj);
STD_ReturnType Interrupt_RBX_Init(const external_interrupt_RBX_t *int_obj);
STD_ReturnType Interrupt_RBX_DeInit(const external_interrupt_RBX_t *int_obj);
#endif	/* MCAL_EXTERNAL_INTERRUPT_H */

