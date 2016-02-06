/* --COPYRIGHT--,BSD
 * Copyright (c) 2014, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/

/*
 *  FlameSensor_Main.c
 *	Created on: Feb 05, 2016
 *  Author: Teja Chintalapati
 *	Contact: teja.chintalapati@gmail.com
 *	Phone: +91-8792-355-512
 *	Description: This program will watch for flame sensor output and will trigger LED/Buzzer in case fire is detected
 *
 *             MSP430FR5969
 *          -----------------
 *         |              XIN|-
 *         |                 |
 *         |             XOUT|-
 *         |                 |
 *    	   |             P2.4|<--> Flame Senosor
 *		   |				 |
 *		   |			 P4.6|<--> Red LED
 *		   |				 |
 *		   |				 |<--> Buzzer
 *
 */

#include "driverlib.h"
#include "mainApp.h"

void main(void)
{
	boardInitialisation();

	while(1)
	{
		//MCU will be in LPM4 untill Flame sensor detects fire.
		__low_power_mode_4();
		flameDetected();
		//After fire is detected, MCU sets Buzzer and red LED on and waits for user input(Button Press) in LPM4
		__low_power_mode_4();
		//After button is pressed, MCU turns LED and Buzzer off and goes to LPM4 again
		buttonPressed();
	}
}
