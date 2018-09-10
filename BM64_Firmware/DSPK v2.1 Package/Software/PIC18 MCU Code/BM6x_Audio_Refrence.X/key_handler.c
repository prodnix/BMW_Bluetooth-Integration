/******************************************************************************
 Software License Agreement:

 The software supplied herewith by Microchip Technology Incorporated
 (the "Company") for its PICmicro(r) Microcontroller is intended and
 supplied to you, the Company's customer, for use solely and
 exclusively on Microchip PICmicro Microcontroller products. The
 software is owned by the Company and/or its supplier, and is
 protected under applicable copyright laws. All rights are reserved.
 Any use in violation of the foregoing restrictions may subject the
 user to criminal sanctions under applicable laws, as well as to
 civil liability for the breach of the terms and conditions of this
 license.

 THIS SOFTWARE IS PROVIDED IN AN "AS IS" CONDITION. NO WARRANTIES,
 WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
********************************************************************/
#include <xc.h>
#define KEY_HANDLER_C
 #include "key_handler.h"
#include "key.h"
#include "yda174dsp_handler.h"
#include "bt_app.h"
#include "bt_command_send.h"
#define HID_MOUSE_MOVEMENT		(20)

void KEY_Handler ( uint8_t key, uint8_t event )
{
    switch ( key )
    {
        case KEY_ID_PLAY_PAUSE:
            if(event == KEY_EVENT_PRIMARY)
            {
                if(BTAPP_GetStatus() == BT_STATUS_READY)
                {
                    BTAPP_PlayPause();
                }
            }
            else if(event == KEY_EVENT_SECONDARY)
            {
                if(BTAPP_GetStatus() == BT_STATUS_READY)
                {
                    BTAPP_GroupSpeakerSoundSync();
                }
            }
            break;
        case KEY_ID_MFB:
            if(event == KEY_EVENT_PRIMARY)
            {
                if(BTAPP_GetStatus() == BT_STATUS_OFF)
                {
                    BTAPP_TaskReq(BT_REQ_SYSTEM_ON);
                }
                else if(BTAPP_GetStatus() == BT_STATUS_READY || BTAPP_GetStatus() == BT_STATUS_ON)
                {
  					BTAPP_MFBOnMode();              	
//                    BTAPP_TaskReq(BT_REQ_SYSTEM_OFF);
                }
            }
            else if(event == KEY_EVENT_SECONDARY)
            {
                if(BTAPP_GetStatus() == BT_STATUS_READY)
                {
                    BTAPP_EnterBTPairingMode();
                }
            }
            else if(event == ADDITIONAL_EVENT_HOLD_FOR_10S)
            {
                BTAPP_ResetEEPROMtoDefault();
            }
            break;
        case KEY_ID_VOL_UP:
            if(BTAPP_GetStatus() == BT_STATUS_READY)
            {
                if(event == KEY_EVENT_PRIMARY)
                    BTAPP_VolUp(CMD_INFO_MCU);
            }
            else
            {
                if(event == KEY_EVENT_PRIMARY)
                    yda174_vol_up();
            }
            break;
        case KEY_ID_VOL_DN:
            if(BTAPP_GetStatus() == BT_STATUS_READY)
            {
                if(event == KEY_EVENT_PRIMARY)
                    BTAPP_VolDown(CMD_INFO_MCU);
            }
            else
            {
                 if(event == KEY_EVENT_PRIMARY)
                    yda174_vol_down();
            }
            break;
        case KEY_ID_PREVIOUS:
            if(event == KEY_EVENT_PRIMARY)
            {
                if(BTAPP_GetStatus() == BT_STATUS_READY)
                    BTAPP_PlayPreviousSong();
            }
            else if(event == KEY_EVENT_SECONDARY)
            {
                if(BTAPP_GetStatus() == BT_STATUS_READY)
                    BTAPP_StartFastRewind();
            }
            else if(event == KEY_EVENT_SECONDARY_RELEASED)
            {
                if(BTAPP_GetStatus() == BT_STATUS_READY)
                    BTAPP_CancelForwardOrRewind();
            }
            break;
        case KEY_ID_NEXT:
            if(event == KEY_EVENT_PRIMARY)
            {
                if(BTAPP_GetStatus() == BT_STATUS_READY)
                    BTAPP_PlayNextSong();
            }
            else if(event == KEY_EVENT_SECONDARY)
            {
                if(BTAPP_GetStatus() == BT_STATUS_READY)
                    BTAPP_StartFastForward();
            }
            else if(event == KEY_EVENT_SECONDARY_RELEASED)
            {
                if(BTAPP_GetStatus() == BT_STATUS_READY)
                    BTAPP_CancelForwardOrRewind();
            }
            break;
		case KEY_ID_SW39:	
			if(event == KEY_EVENT_SINGLE_CLICK)
			{
				BT_Send_HIDMouseCmd(HID_MOUSE_MOVEMENT, 0);
			}
			else if(event == KEY_EVENT_DOUBLE_CLICK)
			{
				BT_Send_HIDMouseCmd(0, 0xff-HID_MOUSE_MOVEMENT);
			}
			break;			
		case KEY_ID_SW22:		
			if(event == KEY_EVENT_SINGLE_CLICK)
			{
				BT_Send_HIDMouseCmd(0xff-HID_MOUSE_MOVEMENT, 0);
			}
			else if(event == KEY_EVENT_DOUBLE_CLICK)
			{
				BT_Send_HIDMouseCmd(0, HID_MOUSE_MOVEMENT);
			}
			break;
        case KEY_ID_SW40:       //CALL button
            if(event == KEY_EVENT_PRIMARY)
            {
                if(BTAPP_GetStatus() == BT_STATUS_READY)
					BTAPP_MultiEventShort();
            }
            else if(event == KEY_EVENT_SECONDARY)
            {
                if(BTAPP_GetStatus() == BT_STATUS_READY)
                    BTAPP_CallEventLong();
            }
            break;
    }
}

