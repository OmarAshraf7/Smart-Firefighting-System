 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ADC AVR driver
 *
 * Author: Kirelos Isaac
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void ADC_init();
int ADC_Read(unsigned char Channel);

/*******************************************************************************
 *                      		Definitions                                    *
 *******************************************************************************/

/*for Aref Selection*/
#define ADC_AREF_With_VREF_OFF				 0
#define ADC_AREF_AVCC_With_ExternalCap		 1
#define ADC_AREF_With_256mv_With_ExternalCap 3


/*for Prescaler*/
#define Prescaler_withDivFactor_2_0		0
#define Prescaler_withDivFactor_2_1		1
#define Prescaler_withDivFactor_4		2
#define Prescaler_withDivFactor_8		3
#define Prescaler_withDivFactor_16		4
#define Prescaler_withDivFactor_32		5
#define Prescaler_withDivFactor_64		6
#define Prescaler_withDivFactor_128		7

#define ADC_Channel0	0
#define ADC_Channel1	1
#define ADC_Channel2	2
#define ADC_Channel3	3
#define ADC_Channel4	4
#define ADC_Channel5	5
#define ADC_Channel6	6
#define ADC_Channel7	7



/*******************************************************************************
 *                      Definitions for Configuration                          *
 *******************************************************************************/

#define	ADC_Reference_Selection		ADC_AREF_AVCC_With_ExternalCap
#define ADC_Prescaler				Prescaler_withDivFactor_128





#endif /* ADC_H_ */
