/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB?Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB?Code Configurator - v2.25.2
        Device            :  PIC18F26K20
        Version           :  1.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 v1.34
        MPLAB             :  MPLAB X v2.35 or v3.00
*/

/*
Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

//KEYs
//KEY ROW0 OUTPUT: RE0
#define KEY_R0_TRIS 			TRISE0
#define KEY_R0_LAT				LATE0
#define KEY_R0_PORT				PORTEbits.RE0
#define KEY_R0_SetHigh()		do { LATE0 = 1; } while(0)
#define KEY_R0_SetLow()			do { LATE0 = 0; } while(0)
#define KEY_R0_Toggle()			do { LATE0 = ~LATE0; } while(0)
#define KEY_R0_GetValue()		PORTEbits.RE0
#define KEY_R0_SetDigitalInput()	do { TRISE0 = 1; } while(0)
#define KEY_R0_SetDigitalOutput()	do { TRISE0 = 0; } while(0)

//KEY ROW1 OUTPUT: RE1
#define KEY_R1_TRIS 			TRISE1
#define KEY_R1_LAT				LATE1
#define KEY_R1_PORT				PORTEbits.RE1
#define KEY_R1_SetHigh()		do { LATE1 = 1; } while(0)
#define KEY_R1_SetLow()			do { LATE1 = 0; } while(0)
#define KEY_R1_Toggle()			do { LATE1 = ~LATE1; } while(0)
#define KEY_R1_GetValue()		PORTEbits.RE1
#define KEY_R1_SetDigitalInput()	do { TRISE1 = 1; } while(0)
#define KEY_R1_SetDigitalOutput()	do { TRISE1 = 0; } while(0)

//KEY ROW2 OUTPUT: RE2
#define KEY_R2_TRIS 			TRISE2
#define KEY_R2_LAT				LATE2
#define KEY_R2_PORT				PORTEbits.RE2
#define KEY_R2_SetHigh()		do { LATE2 = 1; } while(0)
#define KEY_R2_SetLow()			do { LATE2 = 0; } while(0)
#define KEY_R2_Toggle()			do { LATE2 = ~LATE2; } while(0)
#define KEY_R2_GetValue()		PORTEbits.RE2
#define KEY_R2_SetDigitalInput()	do { TRISE2 = 1; } while(0)
#define KEY_R2_SetDigitalOutput()	do { TRISE2 = 0; } while(0)

//KEY COL0 INPUT: RB0
#define KEY_C0_TRIS 			TRISB0
#define KEY_C0_LAT				LATB0
#define KEY_C0_PORT				PORTBbits.RB0
#define KEY_C0_SetHigh()		do { LATB0 = 1; } while(0)
#define KEY_C0_SetLow()			do { LATB0 = 0; } while(0)
#define KEY_C0_Toggle()			do { LATB0 = ~LATB0; } while(0)
#define KEY_C0_GetValue()		PORTBbits.RB0
#define KEY_C0_SetDigitalInput()	do { TRISB0 = 1; } while(0)
#define KEY_C0_SetDigitalOutput()	do { TRISB0 = 0; } while(0)

//KEY COL1 INPUT: RB1
#define KEY_C1_TRIS 			TRISB1
#define KEY_C1_LAT				LATB1
#define KEY_C1_PORT				PORTBbits.RB1
#define KEY_C1_SetHigh()		do { LATB1 = 1; } while(0)
#define KEY_C1_SetLow()			do { LATB1 = 0; } while(0)
#define KEY_C1_Toggle()			do { LATB1 = ~LATB1; } while(0)
#define KEY_C1_GetValue()		PORTBbits.RB1
#define KEY_C1_SetDigitalInput()	do { TRISB1 = 1; } while(0)
#define KEY_C1_SetDigitalOutput()	do { TRISB1 = 0; } while(0)

//KEY COL2 INPUT: RB2
#define KEY_C2_TRIS 			TRISB2
#define KEY_C2_LAT				LATB2
#define KEY_C2_PORT				PORTBbits.RB2
#define KEY_C2_SetHigh()		do { LATB2 = 1; } while(0)
#define KEY_C2_SetLow()			do { LATB2 = 0; } while(0)
#define KEY_C2_Toggle()			do { LATB2 = ~LATB2; } while(0)
#define KEY_C2_GetValue()		PORTBbits.RB2
#define KEY_C2_SetDigitalInput()	do { TRISB2 = 1; } while(0)
#define KEY_C2_SetDigitalOutput()	do { TRISB2 = 0; } while(0)

//MFB output: RG0
#define BM6X_MFB_TRIS 			TRISG0
#define BM6X_MFB_LAT				LATG0
#define BM6X_MFB_PORT				PORTGbits.RG0
#define BM6X_MFB_SetHigh()		do { LATG0 = 1; } while(0)
#define BM6X_MFB_SetLow()			do { LATG0 = 0; } while(0)
#define BM6X_MFB_Toggle()			do { LATG0 = ~LATG0; } while(0)
#define BM6X_MFB_GetValue()		PORTGbits.RG0
#define BM6X_MFB_SetDigitalInput()	do { TRISG0 = 1; } while(0)
#define BM6X_MFB_SetDigitalOutput()	do { TRISG0 = 0; } while(0)

//BM6x RESET output: RG3
#define BM6X_RESET_TRIS 			TRISG3
#define BM6X_RESET_LAT				LATG3
#define BM6X_RESET_PORT				PORTGbits.RG3
#define BM6X_RESET_SetHigh()		do { LATG3 = 1; } while(0)
#define BM6X_RESET_SetLow()			do { LATG3 = 0; } while(0)
#define BM6X_RESET_Toggle()			do { LATG3 = ~LATG3; } while(0)
#define BM6X_RESET_GetValue()		PORTGbits.RG3
#define BM6X_RESET_SetDigitalInput()	do { TRISG3 = 1; } while(0)
#define BM6X_RESET_SetDigitalOutput()	do { TRISG3 = 0; } while(0)

//LINE IN DETECT input: RF4
#define LINE_IN_DETECT_TRIS 			TRISF4
#define LINE_IN_DETECT_LAT				LATF4
#define LINE_IN_DETECT_PORT				PORTFbits.RF4
#define LINE_IN_DETECT_SetHigh()		do { LATF4 = 1; } while(0)
#define LINE_IN_DETECT_SetLow()			do { LATF4 = 0; } while(0)
#define LINE_IN_DETECT_Toggle()			do { LATF4 = ~LATF4; } while(0)
#define LINE_IN_DETECT_GetValue()		PORTFbits.RF4
#define LINE_IN_DETECT_SetDigitalInput()	do { TRISF4 = 1; } while(0)
#define LINE_IN_DETECT_SetDigitalOutput()	do { TRISF4 = 0; } while(0)

//AMP_ENABLE : RH6
#define AMP_ENABLE_TRIS 			TRISH6
#define AMP_ENABLE_LAT				LATH6
#define AMP_ENABLE_PORT				PORTHbits.RH6
#define AMP_ENABLE_SetHigh()		do { LATH6 = 1; } while(0)
#define AMP_ENABLE_SetLow()			do { LATH6 = 0; } while(0)
#define AMP_ENABLE_Toggle()			do { LATH6 = ~LATH6; } while(0)
#define AMP_ENABLE_GetValue()		PORTHbits.RH6
#define AMP_ENABLE_SetDigitalInput()	do { TRISH6 = 1; } while(0)
#define AMP_ENABLE_SetDigitalOutput()	do { TRISH6 = 0; } while(0)

//NFC DETECT input: RA0
#define NFC_DETECT_TRIS 			TRISA0
#define NFC_DETECT_LAT				LATA0
#define NFC_DETECT_PORT				PORTAbits.RA0
#define NFC_DETECT_SetHigh()		do { LATA0 = 1; } while(0)
#define NFC_DETECT_SetLow()			do { LATA0 = 0; } while(0)
#define NFC_DETECT_Toggle()			do { LATA0 = ~LATA0; } while(0)
#define NFC_DETECT_GetValue()		PORTAbits.RA0
#define NFC_DETECT_SetDigitalInput()	do { TRISA0 = 1; } while(0)
#define NFC_DETECT_SetDigitalOutput()	do { TRISA0 = 0; } while(0)

//BM6x TX IND input: RB3
#define BM6X_TX_IND_TRIS 			TRISB3
#define BM6X_TX_IND_LAT				LATB3
#define BM6X_TX_IND_PORT				PORTBbits.RB3
#define BM6X_TX_IND_SetHigh()		do { LATB3 = 1; } while(0)
#define BM6X_TX_IND_SetLow()			do { LATB3 = 0; } while(0)
#define BM6X_TX_IND_Toggle()			do { LATB3 = ~LATB3; } while(0)
#define BM6X_TX_IND_GetValue()		PORTBbits.RB3
#define BM6X_TX_IND_SetDigitalInput()	do { TRISB3 = 1; } while(0)
#define BM6X_TX_IND_SetDigitalOutput()	do { TRISB3 = 0; } while(0)

//DSP_PORT_IN input: RA1
#define DSP_PORT_TRIS 			TRISA1
#define DSP_PORT_LAT				LATA1
#define DSP_PORT_PORT				PORTAbits.RA1
#define DSP_PORT_SetHigh()		do { LATA1 = 1; } while(0)
#define DSP_PORT_SetLow()			do { LATA1 = 0; } while(0)
#define DSP_PORT_Toggle()			do { LATA1 = ~LATA1; } while(0)
#define DSP_PORT_GetValue()		PORTAbits.RA1
#define DSP_PORT_SetDigitalInput()	do { TRISA1 = 1; } while(0)
#define DSP_PORT_SetDigitalOutput()	do { TRISA1 = 0; } while(0)

//DSP_IRQ_IN input: RB5
#define DSP_IRQ_TRIS 			TRISB5
#define DSP_IRQ_LAT				LATB5
#define DSP_IRQ_PORT				PORTBbits.RB5
#define DSP_IRQ_SetHigh()		do { LATB5 = 1; } while(0)
#define DSP_IRQ_SetLow()			do { LATB5 = 0; } while(0)
#define DSP_IRQ_Toggle()			do { LATB5 = ~LATB5; } while(0)
#define DSP_IRQ_GetValue()		PORTBbits.RB5
#define DSP_IRQ_SetDigitalInput()	do { TRISB5 = 1; } while(0)
#define DSP_IRQ_SetDigitalOutput()	do { TRISB5 = 0; } while(0)

//DSP_MUTE output: RD4
#define DSP_MUTE_TRIS 			TRISD4
#define DSP_MUTE_LAT				LATD4
#define DSP_MUTE_PORT				PORTDbits.RD4
#define DSP_MUTE_SetHigh()		do { LATD4 = 1; } while(0)
#define DSP_MUTE_SetLow()			do { LATD4 = 0; } while(0)
#define DSP_MUTE_Toggle()			do { LATD4 = ~LATD4; } while(0)
#define DSP_MUTE_GetValue()		PORTDbits.RD4
#define DSP_MUTE_SetDigitalInput()	do { TRISD4 = 1; } while(0)
#define DSP_MUTE_SetDigitalOutput()	do { TRISD4 = 0; } while(0)

//DSP_POWER_DN output: RD3
#define DSP_POWER_DN_TRIS 			TRISD3
#define DSP_POWER_DN_LAT				LATD3
#define DSP_POWER_DN_PORT				PORTDbits.RD3
#define DSP_POWER_DN_SetHigh()		do { LATD3 = 1; } while(0)
#define DSP_POWER_DN_SetLow()			do { LATD3 = 0; } while(0)
#define DSP_POWER_DN_Toggle()			do { LATD3 = ~LATD3; } while(0)
#define DSP_POWER_DN_GetValue()		PORTDbits.RD3
#define DSP_POWER_DN_SetDigitalInput()	do { TRISD3 = 1; } while(0)
#define DSP_POWER_DN_SetDigitalOutput()	do { TRISD3 = 0; } while(0)

//DSP_RESET output: RD2
#define DSP_RESET_TRIS 			TRISD2
#define DSP_RESET_LAT				LATD2
#define DSP_RESET_PORT				PORTDbits.RD2
#define DSP_RESET_SetHigh()		do { LATD2 = 1; } while(0)
#define DSP_RESET_SetLow()			do { LATD2 = 0; } while(0)
#define DSP_RESET_Toggle()			do { LATD2 = ~LATD2; } while(0)
#define DSP_RESET_GetValue()		PORTDbits.RD2
#define DSP_RESET_SetDigitalInput()	do { TRISD2 = 1; } while(0)
#define DSP_RESET_SetDigitalOutput()	do { TRISD2 = 0; } while(0)

//RB4: don't know usage
#define RB4_TRIS 			TRISB4
#define RB4_LAT				LATB4
#define RB4_PORT				PORTBbits.RB4
#define RB4_SetHigh()		do { LATB4 = 1; } while(0)
#define RB4_SetLow()			do { LATB4 = 0; } while(0)
#define RB4_Toggle()			do { LATB4 = ~LATB4; } while(0)
#define RB4_GetValue()		PORTBbits.RB4
#define RB4_SetDigitalInput()	do { TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()	do { TRISB4 = 0; } while(0)

//SCL: RD6
#define SCL_TRIS 			TRISD6
#define SCL_LAT				LATD6
#define SCL_PORT				PORTDbits.RD6
#define SCL_SetHigh()		do { LATD6 = 1; } while(0)
#define SCL_SetLow()			do { LATD6 = 0; } while(0)
#define SCL_Toggle()			do { LATD6 = ~LATD6; } while(0)
#define SCL_GetValue()		PORTDbits.RD6
#define SCL_SetDigitalInput()	do { TRISD6 = 1; } while(0)
#define SCL_SetDigitalOutput()	do { TRISD6 = 0; } while(0)
//SDA: RD5
#define SDA_TRIS 			TRISD5
#define SDA_LAT				LATD5
#define SDA_PORT				PORTDbits.RD5
#define SDA_SetHigh()		do { LATD5 = 1; } while(0)
#define SDA_SetLow()			do { LATD5 = 0; } while(0)
#define SDA_Toggle()			do { LATD5 = ~LATD5; } while(0)
#define SDA_GetValue()		PORTDbits.RD5
#define SDA_SetDigitalInput()	do { TRISD5 = 1; } while(0)
#define SDA_SetDigitalOutput()	do { TRISD5 = 0; } while(0)

//UART2 TX: RG1
#define U2TX_TRIS 			TRISG1
#define U2TX_LAT				LATG1
#define U2TX_PORT				PORTGbits.RG1
#define U2TX_SetHigh()		do { LATG1 = 1; } while(0)
#define U2TX_SetLow()			do { LATG1 = 0; } while(0)
#define U2TX_Toggle()			do { LATG1 = ~LATG1; } while(0)
#define U2TX_GetValue()		PORTGbits.RG1
#define U2TX_SetDigitalInput()	do { TRISG1 = 1; } while(0)
#define U2TX_SetDigitalOutput()	do { TRISG1 = 0; } while(0)
//UART2 RX: RG2
#define U2RX_TRIS 			TRISG2
#define U2RX_LAT				LATG2
#define U2RX_PORT				PORTGbits.RG2
#define U2RX_SetHigh()		do { LATG2 = 1; } while(0)
#define U2RX_SetLow()			do { LATG2 = 0; } while(0)
#define U2RX_Toggle()			do { LATG2 = ~LATG2; } while(0)
#define U2RX_GetValue()		PORTGbits.RG2
#define U2RX_SetDigitalInput()	do { TRISG2 = 1; } while(0)
#define U2RX_SetDigitalOutput()	do { TRISG2 = 0; } while(0)

//legacy define
#define RA3_BM64_MFB_SetHigh()    do { LATA3 = 1; } while(0)
#define RA3_BM64_MFB_SetLow()   do { LATA3 = 0; } while(0)
#define RA0_BM64_RESET_SetHigh()    do { LATA0 = 1; } while(0)
#define RA0_BM64_RESET_SetLow()   do { LATA0 = 0; } while(0)

#define RA2_RX_LED_LAT         LATA2
#define RA2_RX_LED_SetHigh()    do { LATA2 = 1; } while(0)
#define RA2_RX_LED_SetLow()   do { LATA2 = 0; } while(0)
#define RA2_RX_LED_Toggle()   do { LATA2 = ~LATA2; } while(0)

#define RB3_A_RESET_SetHigh()    do { LATB3 = 1; } while(0)
#define RB3_A_RESET_SetLow()   do { LATB3 = 0; } while(0)
#define RB4_A_MUTE_SetHigh()    do { LATB4 = 1; } while(0)
#define RB4_A_MUTE_SetLow()   do { LATB4 = 0; } while(0)
#define RB5_P_DOWN_SetHigh()    do { LATB5 = 1; } while(0)
#define RB5_P_DOWN_SetLow()   do { LATB5 = 0; } while(0)

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    GPIO and peripheral I/O initialization
 * @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);

#endif // PIN_MANAGER_H
/**
 End of File
*/