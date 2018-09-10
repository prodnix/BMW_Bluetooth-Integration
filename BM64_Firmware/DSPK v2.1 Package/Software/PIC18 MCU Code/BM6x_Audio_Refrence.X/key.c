/*****************************************************************************
                     Microchip Technology Incorporated

    FileName:        key.c
    Dependencies:    See Includes Section
    Processor:       PIC24, PIC32

Copyright � 2009-2013 Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED ?AS IS? WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

******************************************************************************/
#include <xc.h>
#include "mcc/mcc.h"
#define KEY_C
#include "key.h"
#include "key_handler.h"
////////////////////////////////////////////////////////////////////////////////
#define KEY_NUMBER_OF 9

const uint8_t keyInitMap[KEY_NUMBER_OF] =
{
    KEY_ID_SW22,            //R0,C0
    KEY_ID_VOL_UP,          //R0,C1
    KEY_ID_SW39,            //R0,C2

    KEY_ID_PREVIOUS,        //R1,C0
    KEY_ID_PLAY_PAUSE,      //R1,C1
    KEY_ID_NEXT,            //R1,C2

    KEY_ID_MFB,             //R2,C0
    KEY_ID_VOL_DN,          //R2,C1
    KEY_ID_SW40,            //R2,C2
};

const uint8_t keyInitMapMode[KEY_NUMBER_OF] =
{
    KEY_MODE_TREBLE_ACTION,//KEY_MODE_DUAL_ACTION ,      //SW22
    KEY_MODE_AUTOREPEAT ,       //VOL UP
    KEY_MODE_TREBLE_ACTION,//KEY_MODE_DUAL_ACTION ,      //SW39
    KEY_MODE_DUAL_ACTION ,      //PREV
    KEY_MODE_DUAL_ACTION ,      //PLAY/PAUSE
    KEY_MODE_DUAL_ACTION ,      //NEXT
    KEY_MODE_DUAL_ACTION ,      //MFB
    KEY_MODE_AUTOREPEAT ,       //VOL DN
    KEY_MODE_DUAL_ACTION ,      //SW40
};

KEY_STATE keyState[KEY_NUMBER_OF];
uint8_t keyTimer = 0;

////////////////////////////////////////////////////////////////////////////////

void KEY_Initialize ( void )
{
    uint8_t i;
    for(i = 0; i< KEY_NUMBER_OF; i++)
    {
        keyState[i].id = keyInitMap[i];
        keyState[i].mode = keyInitMapMode[i];
        keyState[i].state = 0;
        keyState[i].time = 0;
    }
}

////////////////////////////////////////////////////////////////////////////////
uint16_t SYSTEM_GetKeys ( void )
{
    uint16_t state = 0, state1 = 0;
    uint8_t i;
    
    //MCU_P72 ROW
    KEY_R0_SetHigh();
    KEY_R1_SetHigh();
    KEY_R2_SetLow();
    for(i=0; i<10; i++);            //50us
    state = PORTB & 0b00000111;
    state <<= 3;

    //MCU_P71 ROW
    KEY_R0_SetHigh();
    KEY_R1_SetLow();
    KEY_R2_SetHigh();
    for(i=0; i<10; i++);            //50us
    state1 = PORTB & 0b00000111;
    state |= state1;
    state <<= 3;

    //MCU_P70 ROW
    KEY_R0_SetLow();
    KEY_R1_SetHigh();
    KEY_R2_SetHigh();
    for(i=0; i<10; i++);            //50us
    state1 = PORTB & 0b00000111;
    state |= state1;
    KEY_R0_SetHigh();
    state ^= 0b0000000111111111;

    return  ( state );
}
////////////////////////////////////////////////////////////////////////////////

void KEY_Timer1MS_event(void)
{
    if(keyTimer)
        --keyTimer;
}

void KEY_Task ( void )
{
    uint8_t i;
    uint16_t state;

    if(keyTimer)
        return;
    keyTimer = KEY_TASK_PERIOD;

    state = SYSTEM_GetKeys ();

    for ( i = 0; i < KEY_NUMBER_OF; i ++ )
    {
        keyState[i].state = state & 1;
        state >>= 1;
        KEY_Process ( &keyState[i], KEY_TASK_PERIOD );
    }
}

////////////////////////////////////////////////////////////////////////////////

void KEY_Process ( KEY_STATE *key, uint16_t time )
{
    if ( key->mode == KEY_MODE_DISABLED )
    {
        return;
    }

    if ( key->state == true )
    {
        if(key->time < 60000)
            key->time += time;
    }
    else
    {
        if( key->time_last_off < 60000 )
            key->time_last_off += time;
    }

    switch ( key->mode )
    {
        case KEY_MODE_CONTINUOUS:
            if ( key->state == true )
            {
                KEY_Handler ( key->id, KEY_EVENT_PRIMARY );     //send button every KEY_TASK_PERIOD ms
                key->last_action = KEY_EVENT_PRIMARY;
            }
            
            if (( key->time != 0 ) && ( key->state == false ))      //when key is released
            {
                key->time_last_off = 0;
            }
            break;

        case KEY_MODE_AUTOREPEAT:
            if (( key->time != 0 )
            && ( key->time < KEY_AUTOREPEAT_DELAY )
            && ( key->state == false ))
            {
                KEY_Handler ( key->id, KEY_EVENT_PRIMARY );     //for repeating button, send once if pressing time is short
                key->last_action = KEY_EVENT_PRIMARY;
            }
            else if (( key->time > KEY_AUTOREPEAT_DELAY + KEY_AUTOREPEAT_RATE ) && ( key->state == true ))
            {
                KEY_Handler ( key->id, KEY_EVENT_PRIMARY );     //for repeating button, send button repeatly
                key->time -= KEY_AUTOREPEAT_RATE;
                key->last_action = KEY_EVENT_PRIMARY;
            }
            
            if (( key->time != 0 ) && ( key->state == false ))      //when key is released
            {
                key->time_last_off = 0;
            }
            break;
            
        case KEY_MODE_SINGLE_ACTION:
            if (( key->time != 0 ) && ( key->state == false ))
            {
                KEY_Handler ( key->id, KEY_EVENT_PRIMARY );     //send button only once for every button pressing action, send button out at KEY_TASK_PERIOD ms
                key->last_action = KEY_EVENT_PRIMARY;
            }
            
            if (( key->time != 0 ) && ( key->state == false ))      //when key is released
            {
                key->time_last_off = 0;
            }
            break;

        case KEY_MODE_DUAL_ACTION:
            if (( key->time != 0 )
            && ( key->time < KEY_SINGLE_ACTION_DELAY )
            && ( key->state == false ))
            {
                KEY_Handler ( key->id, KEY_EVENT_PRIMARY );  //send a short pressing button for once at false edge
                key->last_action = KEY_EVENT_PRIMARY;
            }
            else if (( key->time == KEY_SINGLE_ACTION_DELAY ) && ( key->state == true ))
            {
                KEY_Handler ( key->id, KEY_EVENT_SECONDARY ); //send a long pressing button when button is holding
                key->last_action = KEY_EVENT_SECONDARY;
            }
            else if(( key->time != 0 )
            && ( key->time > KEY_SINGLE_ACTION_DELAY )
            && ( key->state == false ))
            {
                KEY_Handler ( key->id, KEY_EVENT_SECONDARY_RELEASED );
            }
            
            if (( key->time != 0 ) && ( key->state == false ))      //when key is released
            {
                key->time_last_off = 0;
            }
            break;

        case KEY_MODE_TREBLE_ACTION:
            //single click check
            if( ( key->time == 0 ) 
                    && ( key->state == false )
                    && ( key->time_last_off > KEY_TREBLE_ACTION_OFF_DELAY)
                    && (key->last_action == KEY_EVENT_PRIMARY) )
            {
                KEY_Handler ( key->id, KEY_EVENT_SINGLE_CLICK );
                key->last_action = KEY_EVENT_SINGLE_CLICK;
            }
            
            if (( key->time != 0 )
            && ( key->time < KEY_SINGLE_ACTION_DELAY )
            && ( key->state == false ))
            {
                //double click check
                if(key->time_last_off <= KEY_TREBLE_ACTION_OFF_DELAY && key->last_action == KEY_EVENT_PRIMARY)
                {
                    KEY_Handler ( key->id, KEY_EVENT_DOUBLE_CLICK );
                    key->last_action = KEY_EVENT_DOUBLE_CLICK;
                }
                else    //button short press check
                {
                    KEY_Handler ( key->id, KEY_EVENT_PRIMARY );  //send a short pressing button for once at false edge
                    key->last_action = KEY_EVENT_PRIMARY;
                }
            }
            else if (( key->time == KEY_SINGLE_ACTION_DELAY ) && ( key->state == true ))        //button long press check
            {
                KEY_Handler ( key->id, KEY_EVENT_SECONDARY ); //send a long pressing button when button is holding
                key->last_action = KEY_EVENT_SECONDARY;
            }
            
            if (( key->time != 0 ) && ( key->state == false ))      //when key is released
            {
                key->time_last_off = 0;
            }
            break;
            
        default:
            break;
    }

    if(( key->id == KEY_ID_MFB )            //MFB button only
            && ( key->time == 10000 )       //10 seconds hold
            && ( key->state == true ))      //hold status
    {
        KEY_Handler ( key->id, ADDITIONAL_EVENT_HOLD_FOR_10S );
    }
    
    if ( key->state == false )
    {
        key->time = 0;
    }
}

////////////////////////////////////////////////////////////////////////////////
