/**
  Generated Pin Manager File

  Company:
    Microchip Technology Inc.

  File Name:
    pin_manager.c

  Summary:
    This is the Pin Manager file generated using MPLAB?Code Configurator

  Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB?Code Configurator - v2.25.2
        Device            :  PIC18F26K20
        Driver Version    :  1.02
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

#include <xc.h>
#include "pin_manager.h"

void PIN_MANAGER_Initialize(void)           //modify later
{
    ADCON1bits.PCFG = 0b1111;       //All AN ports are configured as digital port
    LATA = 0x00;
    TRISA = 0x00;
    LATB = 0x00;
    TRISB = 0x00;
    LATC = 0x00;
    TRISC = 0x00;
    LATD = 0x00;
    TRISD = 0x00;
    LATE = 0x00;
    TRISE = 0x00;
    LATF = 0x00;
    TRISF = 0x00;
    LATG = 0x00;
    TRISG = 0x00;
    LATH = 0x00;
    TRISH = 0x00;
    LATJ = 0x00;
    TRISJ = 0x00;
    INTCON2bits.nRBPU = 0x01;       //disable all PORTB pull up

    KEY_R0_TRIS = OUTPUT;
    KEY_R0_SetHigh();
    KEY_R1_TRIS = OUTPUT;
    KEY_R1_SetHigh();
    KEY_R2_TRIS = OUTPUT;
    KEY_R2_SetHigh();
    KEY_C0_TRIS = INPUT;
    KEY_C1_TRIS = INPUT;
    KEY_C2_TRIS = INPUT;

    BM6X_MFB_TRIS = OUTPUT;
    BM6X_MFB_SetLow();
    BM6X_RESET_TRIS = OUTPUT;
    BM6X_RESET_SetLow();
    BM6X_TX_IND_TRIS = INPUT;

    DSP_PORT_TRIS = INPUT;
    DSP_IRQ_TRIS = INPUT;
    DSP_MUTE_TRIS = OUTPUT;
    DSP_MUTE_SetLow();
    DSP_POWER_DN_TRIS = OUTPUT;
    DSP_POWER_DN_SetLow();
    DSP_RESET_TRIS = OUTPUT;
    DSP_RESET_SetLow();

    LINE_IN_DETECT_TRIS = INPUT;
    AMP_ENABLE_TRIS = INPUT;
    NFC_DETECT_TRIS = INPUT;

    RB4_SetDigitalInput();
    SCL_SetDigitalInput();
    SDA_SetDigitalInput();
    U2RX_SetDigitalInput();
    U2TX_SetDigitalOutput();
    U2TX_SetHigh();

}
/**
 End of File
*/