/* 
 * File:   mcal_interrupt_config.h
 * Author: Mahmoud Elgendy
 *
 * Created on September 18, 2023, 10:31 PM
 */

#ifndef MCAL_INTERRUPT_CONFIG_H
#define	MCAL_INTERRUPT_CONFIG_H

/* Section : Includes */
#include "../GPIO/hal_gpio.h"
#include "mcal_interrupt_gen_cfg.h"
/* Section : Macro Declaration */
#define INTERRUPT_ENABLE    1
#define INTERRUPT_DISABLE   0
#define INTERRUPT_OCCUR     1
#define INTERRUPT_NOT_OCCUR 0
/* Section : Macro Function Declaration */
#define INTERRUPT_GlobalInterruptEnable()      (INTCONbits.GIE=1)
#define INTERRUPT_GlobalInterruptDisable()     (INTCONbits.GIE=0)
#define INTERRUPT_PeripheralInterruptEnable()  (INTCONbits.PEIE=1)
#define INTERRUPT_PeripheralInterruptDisable() (INTCONbits.PEIE=0)
/* Section : Data Type Declaration */

/* Section : Function Declaration */

#endif	/* MCAL_INTERRUPT_CONFIG_H */

