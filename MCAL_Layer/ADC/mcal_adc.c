/* 
 * File:   mcal_adc.h
 * Author: Mahmoud Elgendy
 *
 * Created on October 10, 2023, 6:19 PM
 */
#include "mcal_adc.h"

static inline void adc_input_channel_port_configration(adc_channel_select_t channel);
static inline void adc_select_result_format(const adc_t *adc_obj);
static inline void adc_select_clock(const adc_t *adc_obj);
#if ADC_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
static void (* ADC_InterruptHandler)(void) = NULL;
#endif

/**
 * 
 * @param adc_obj
 * @return 
 */
STD_ReturnType ADC_Init(const adc_t *adc_obj) {
    STD_ReturnType ret = E_OK;
    if (adc_obj == NULL) {
        ret = E_NOT_OK;
    } else {
        ADC_CONVERTER_DISABLED();
        ADCON0bits.CHS = adc_obj->adc_channel;
        adc_input_channel_port_configration(adc_obj->adc_channel);
        adc_select_result_format(adc_obj);
        adc_select_clock(adc_obj);
        ADC_ANALOG_DIGITAL_PORT_CONFIGRATION(adc_obj->adc_digital_analog);
#if ADC_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
        ADC_InterruptClearFlag();
        ADC_InterruptEnable();
        ADC_InterruptHandler = adc_obj->ADC_InterruptHandler;
        INTERRUPT_PeripheralInterruptEnable();
        INTERRUPT_GlobalInterruptEnable();
#endif
        ADC_CONVERTER_ENABLE();
    }
    return ret;
}

/**
 * 
 * @param adc_obj
 * @return 
 */
STD_ReturnType ADC_DeInit(const adc_t *adc_obj) {
    STD_ReturnType ret = E_OK;
    if (adc_obj == NULL) {
        ret = E_NOT_OK;
    } else {
        ADC_CONVERTER_DISABLED();
#if ADC_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
        ADC_InterruptDisable();
#endif
    }
    return ret;
}

/**
 * 
 * @param channel
 * @return 
 */
STD_ReturnType ADC_SelectChannel(adc_channel_select_t channel) {
    STD_ReturnType ret = E_OK;
    ADCON0bits.CHS = channel;
    adc_input_channel_port_configration(channel);
    return ret;
}

/**
 * 
 * @param adc_obj
 * @return 
 */
STD_ReturnType ADC_StartConversion(const adc_t *adc_obj) {
    STD_ReturnType ret = E_OK;
    if (adc_obj == NULL) {
        ret = E_NOT_OK;
    } else {
        ADC_START_CONVERSION();
    }
    return ret;
}

/**
 * 
 * @param adc_obj
 * @param conversion_status
 * @return 
 */
STD_ReturnType ADC_IsconversionDone(const adc_t *adc_obj, uint8 *conversion_status) {
    STD_ReturnType ret = E_OK;
    if (adc_obj == NULL) {
        ret = E_NOT_OK;
    } else {
        *conversion_status = !(ADC_CONVERSION_STATUS());
    }
    return ret;
}

/**
 * 
 * @param adc_obj
 * @param conversion_result
 * @return 
 */
STD_ReturnType ADC_GetConversionResult(const adc_t *adc_obj, uint16 *conversion_result) {
    STD_ReturnType ret = E_OK;
    if (adc_obj == NULL) {
        ret = E_NOT_OK;
    } else {
        if (ADC_RESULT_RIGHT == adc_obj->adc_result_format) {
            *conversion_result = (uint16) ((ADRESH << 8) + ADRESL);
        } else if (ADC_RESULT_LEFT == adc_obj->adc_result_format) {
            *conversion_result = (uint16) (((ADRESH << 8) + ADRESL) >> 6);
        } else {
            *conversion_result = (uint16) ((ADRESH << 8) + ADRESL);
        }
    }
    return ret;
}

/**
 * 
 * @param adc_obj
 * @param channel
 * @param conversion_result
 * @return 
 */
STD_ReturnType ADC_GetConversion_Blocking(const adc_t *adc_obj, adc_channel_select_t channel
        , uint16 *conversion_result) {
    STD_ReturnType ret = E_OK;
    if (adc_obj == NULL) {
        ret = E_NOT_OK;
    } else {
        ADC_SelectChannel(channel);
        ADC_StartConversion(adc_obj);
        while (ADCON0bits.GO_DONE);
        ADC_GetConversionResult(adc_obj, conversion_result);
    }
    return ret;
}

/**
 * 
 * @param adc_obj
 * @param channel
 * @return 
 */
STD_ReturnType ADC_GetConversion_Interrupt(const adc_t *adc_obj, adc_channel_select_t channel) {
    STD_ReturnType ret = E_OK;
    if (adc_obj == NULL) {
        ret = E_NOT_OK;
    } else {
        ADC_SelectChannel(channel);
        ADC_StartConversion(adc_obj);
    }
    return ret;
}

void ADC_ISR(void) {
    ADC_InterruptClearFlag();
    if (ADC_InterruptHandler) {
        ADC_InterruptHandler();
    }
}

static inline void adc_input_channel_port_configration(adc_channel_select_t channel) {
    switch (channel) {
        case ADC_CHANNEL_AN0:
            SET_BIT(TRISA, _TRISA_TRISA0_POSN);
            break;
        case ADC_CHANNEL_AN1:
            SET_BIT(TRISA, _TRISA_TRISA1_POSN);
            break;
        case ADC_CHANNEL_AN2:
            SET_BIT(TRISA, _TRISA_TRISA2_POSN);
            break;
        case ADC_CHANNEL_AN3:
            SET_BIT(TRISA, _TRISA_TRISA3_POSN);
            break;
        case ADC_CHANNEL_AN4:
            SET_BIT(TRISA, _TRISA_TRISA5_POSN);
            break;
        case ADC_CHANNEL_AN5:
            SET_BIT(TRISE, _TRISE_TRISE0_POSN);
            break;
        case ADC_CHANNEL_AN6:
            SET_BIT(TRISE, _TRISE_TRISE1_POSN);
            break;
        case ADC_CHANNEL_AN7:
            SET_BIT(TRISE, _TRISE_TRISE2_POSN);
            break;
    }
}

static inline void adc_select_result_format(const adc_t *adc_obj) {
    if (ADC_RESULT_RIGHT == adc_obj->adc_result_format) {
        ADC_RESULT_RIGHT_FORMAT();
    } else if (ADC_RESULT_LEFT == adc_obj->adc_result_format) {
        ADC_RESULT_LEFT_FORMAT();
    } else {
        ADC_RESULT_RIGHT_FORMAT();
    }
}

static inline void adc_select_clock(const adc_t *adc_obj) {
    ADCON0bits.ADCS = (uint8) ((adc_obj->adc_clock) & 0x03);
    ADCON1bits.ADCS2 = (uint8) ((adc_obj->adc_clock) >> 3);
}