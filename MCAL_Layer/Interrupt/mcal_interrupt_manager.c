/* 
 * File:   mcal_interrupt_manager.h
 * Author: Mahmoud Elgendy
 *
 * Created on September 18, 2023, 10:34 PM
 */
#include "mcal_interrupt_manager.h"
#include "mcal_external_interrupt.h"
volatile static uint8 RB4_Flag = 1, RB5_Flag = 1, RB6_Flag = 1, RB7_Flag = 1;

void __interrupt() InterruptManager(void) {
    if (INTERRUPT_ENABLE == INTCONbits.INTE && INTERRUPT_OCCUR == INTCONbits.INTF) {
        INT_ISR();
    } else {
        /*Nothing*/
    }
    if ((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB4 == GPIO_HIGH) && (1 == RB4_Flag)) {
        RB4_Flag = 0;
        RB4_ISR(0);
    } else {
        /*NoThing*/
    }
    if ((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB4 == GPIO_LOW)&& (0 == RB4_Flag)) {
        RB4_Flag = 1;
        RB4_ISR(1);
    } else {
        /*NoThing*/
    }
    if ((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB5 == GPIO_HIGH) && (1 == RB5_Flag)) {
        RB5_Flag = 0;
        RB5_ISR(0);
    } else {
        /*NoThing*/
    }
    if ((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB5 == GPIO_LOW)&& (0 == RB5_Flag)) {
        RB5_Flag = 1;
        RB5_ISR(1);
    } else {
        /*NoThing*/
    }
    if ((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB6 == GPIO_HIGH) && (1 == RB6_Flag)) {
        RB6_Flag = 0;
        RB6_ISR(0);
    } else {
        /*NoThing*/
    }
    if ((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB6 == GPIO_LOW)&& (0 == RB6_Flag)) {
        RB6_Flag = 1;
        RB6_ISR(1);
    } else {
        /*NoThing*/
    }
    if ((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB7 == GPIO_HIGH) && (1 == RB7_Flag)) {
        RB7_Flag = 0;
        RB7_ISR(0);
    } else {
        /*NoThing*/
    }
    if ((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB7 == GPIO_LOW)&& (0 == RB7_Flag)) {
        RB7_Flag = 1;
        RB7_ISR(1);
    } else {
        /*NoThing*/
    }
}
