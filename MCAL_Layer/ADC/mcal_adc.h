/* 
 * File:   mcal_adc.h
 * Author: Mahmoud Elgendy
 *
 * Created on October 10, 2023, 6:19 PM
 */

#ifndef MCAL_ADC_H
#define	MCAL_ADC_H

/* Section : Includes */
#include"../GPIO/hal_gpio.h"
#include "../Interrupt/mcal_internal_interrupt.h"
/* Section : Macro Declaration */
#define ADC_AN0_ANALOG_FUNCTIONALITY 0x0E
#define ADC_AN3_ANALOG_FUNCTIONALITY 0x04
#define ADC_AN4_ANALOG_FUNCTIONALITY 0x02
#define ADC_AN6_ANALOG_FUNCTIONALITY 0x09
#define ADC_ALL_ANALOG_FUNCTIONALITY  0x00
#define ADC_ALL_DIGITAL_FUNCTIONALITY 0x07

#define ADC_RESULT_RIGHT    0x01U
#define ADC_RESULT_LEFT     0x00U

#define ADC_CONVERSION_COMPLETED  0x01U
#define ADC_CONVERSION_INPROGRESS 0x00U

/* Section : Macro Function Declaration */
#define ADC_CONVERSION_STATUS() (ADCON0bits.GO_DONE)
#define ADC_START_CONVERSION() (ADCON0bits.GO_DONE=1)
#define ADC_CONVERTER_ENABLE() (ADCON0bits.ADON=1)
#define ADC_CONVERTER_DISABLED() (ADCON0bits.ADON=0)
#define ADC_ANALOG_DIGITAL_PORT_CONFIGRATION(_CONFIG) (ADCON1bits.PCFG = _CONFIG)
#define ADC_RESULT_RIGHT_FORMAT()(ADCON1bits.ADFM = 1)
#define ADC_RESULT_LEFT_FORMAT() (ADCON1bits.ADFM = 0)

/* Section : Data Type Declaration */
typedef enum {
    ADC_CONVERSION_CLOCK_FOSC_DIV_2 = 0,
    ADC_CONVERSION_CLOCK_FOSC_DIV_8,
    ADC_CONVERSION_CLOCK_FOSC_DIV_32,
    ADC_CONVERSION_CLOCK_FOSC_DIV_FRC,
    ADC_CONVERSION_CLOCK_FOSC_DIV_4,
    ADC_CONVERSION_CLOCK_FOSC_DIV_16,
    ADC_CONVERSION_CLOCK_FOSC_DIV_64
} adc_conversion_clock_t;

typedef enum {
    ADC_CHANNEL_AN0 = 0,
    ADC_CHANNEL_AN1,
    ADC_CHANNEL_AN2,
    ADC_CHANNEL_AN3,
    ADC_CHANNEL_AN4,
    ADC_CHANNEL_AN5,
    ADC_CHANNEL_AN6,
    ADC_CHANNEL_AN7
} adc_channel_select_t;

typedef struct {
#if ADC_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
    void (* ADC_InterruptHandler)(void);
#endif
    adc_channel_select_t adc_channel;
    adc_conversion_clock_t adc_clock;
    uint8 adc_digital_analog : 4;
    uint8 adc_result_format : 1;
    uint8 adc_reserved : 3;
} adc_t;
/* Section : Function Declaration */
STD_ReturnType ADC_Init(const adc_t *adc_obj);
STD_ReturnType ADC_DeInit(const adc_t *adc_obj);
STD_ReturnType ADC_SelectChannel(adc_channel_select_t channel);
STD_ReturnType ADC_StartConversion(const adc_t *adc_obj);
STD_ReturnType ADC_IsconversionDone(const adc_t *adc_obj, uint8 *conversion_status);
STD_ReturnType ADC_GetConversionResult(const adc_t *adc_obj, uint16 *conversion_result);
STD_ReturnType ADC_GetConversion_Blocking(const adc_t *adc_obj, adc_channel_select_t channel
        , uint16 *conversion_result);
STD_ReturnType ADC_GetConversion_Interrupt(const adc_t *adc_obj, adc_channel_select_t channel);
#endif	/* MCAL_ADC_H */

