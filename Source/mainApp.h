/*
 * mainApp.h
 *
 * Created on: Feb 05, 2016
 * Author: Teja Chintalapati
 * Contact: teja.chintalapati@gmail.com
 * Phone: +91-8792-355-512
 *
 */

#ifndef FLAMESENSOR_SOURCE_MAINAPP_H_
#define FLAMESENSOR_SOURCE_MAINAPP_H_

/******************************************************************************
 * INCLUDES
 */

#include <driverlib.h>
#include "clockInitialisation.h"
#include "pinInitialisation.h"
#include "portInitialisation.h"
#include "Flame.h"

/******************************************************************************
 * DEFINITIONS
 */

//If you want to see clock frequencies, then make this true.
#define DEBUG																   false
//If you want to attach any external circuit(Like Buzzer), make this true. Else, make it false
#define BUZZER_PRESENT														   true

//Used in pinInitialisation.c
#define FLAMESENSORPORT														   GPIO_PORT_P2
#define FLAMESENSORPIN														   GPIO_PIN5
#define BUTTONPORT															   GPIO_PORT_P4
#define BUTTONPIN															   GPIO_PIN5

//TODO: If you change these pins, please make appropriate changes in ISRs (pinInitialisation.c)

#define LEDPORT																   GPIO_PORT_P4
#define LEDPIN																   GPIO_PIN6

#if BUZZER_PRESENT
#define BUZZERPORT															   GPIO_PORT_P2
#define BUZZERPIN															   GPIO_PIN6
#endif

//Used in clockInitiaisation.c
#define LF_CRYSTAL_FREQUENCY_IN_HZ     										   32768
#define HF_CRYSTAL_FREQUENCY_IN_HZ											   0            // FR5969 Launchpad does not have 16MHz crystal

//Used in portInitialisation.c
#define allPins																   GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 + GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 + GPIO_PIN6 + GPIO_PIN7

/******************************************************************************
 * FUNCTION DECLARATION
 */

void boardInitialisation(void);

#endif /* FLAMESENSOR_SOURCE_MAINAPP_H_ */
