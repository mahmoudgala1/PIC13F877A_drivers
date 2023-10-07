/* 
 * File:   mcal_interrupt_manager.h
 * Author: Mahmoud Elgendy
 *
 * Created on September 18, 2023, 10:34 PM
 */

#ifndef MCAL_INTERRUPT_MANAGER_H
#define	MCAL_INTERRUPT_MANAGER_H

/* Section : Includes */
#include "mcal_interrupt_config.h"
/* Section : Macro Declaration */

/* Section : Macro Function Declaration */

/* Section : Data Type Declaration */

/* Section : Function Declaration */
void INT_ISR(void);
void RB4_ISR(uint8 RB4_Source);
void RB5_ISR(uint8 RB5_Source);
void RB6_ISR(uint8 RB6_Source);
void RB7_ISR(uint8 RB7_Source);
#endif	/* MCAL_INTERRUPT_MANAGER_H */

