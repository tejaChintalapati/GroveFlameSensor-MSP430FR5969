/*
 * 	Flame.c
 *
 *  Created on: Feb 05, 2016
 *  Author: Teja Chintalapati
 *	Contact: teja.chintalapati@gmail.com
 *	Phone: +91-8792-355-512
 *	Description: Contains to handle Flame Sensor Interrupt
 *
 */

/******************************************************************************
 * INCLUDES
 */

#include "mainApp.h"

/******************************************************************************
 * FUNCTION DEFINITIONS
 */

void flameDetected(void)
{
	GPIO_disableInterrupt(FLAMESENSORPORT, FLAMESENSORPIN);
    GPIO_enableInterrupt(BUTTONPORT, BUTTONPIN);
    GPIO_setOutputHighOnPin(LEDPORT, LEDPIN);
#if BUZZER_PRESENT
    GPIO_setOutputHighOnPin(BUZZERPORT, BUZZERPIN);
#endif
}


void buttonPressed(void)
{
	GPIO_disableInterrupt(BUTTONPORT, BUTTONPIN);
	GPIO_enableInterrupt(FLAMESENSORPORT, FLAMESENSORPIN);
	GPIO_setOutputLowOnPin(LEDPORT, LEDPIN);
#if BUZZER_PRESENT
	GPIO_setOutputLowOnPin(BUZZERPORT, BUZZERPIN);
#endif
}
