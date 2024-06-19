 /******************************************************************************
 *
 * Module: mq135 gas sensor
 *
 * File Name: mq135.h
 *
 * Description: Header file for the gas sensor driver
 *
 * Author: Omar Ashraf
 *
 *******************************************************************************/

#ifndef MQ135_H_
#define MQ135_H_

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define SENSOR_CHANNEL_ID         0

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for calculate the gass Percentage from the ADC digital value.
 */
int MQ135_getGassPer(void);


#endif /* MQ135_H_ */
