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
#ifndef BT_APP_H
#define BT_APP_H

#include <stdbool.h>
#include <stdint.h>

void BTAPP_Init( void );
void BTAPP_Task( void );
void BTAPP_Timer1MS_event( void );
// @ request define
enum {
    BT_REQ_NONE = 0,
    BT_REQ_SYSTEM_ON,   //BM64 power on request(outside application must control RESET and MFB timing, then call this request)
    BT_REQ_SYSTEM_OFF,  //BM64 power off request(after call this, outside application must control RESET and MFB)
};

enum {
    BT_SINGLE_PKT = 0,
    BT_FRAGMENTED_START_PKT,  
    BT_FRAGMENTED_CONT_PKT, 
    BT_FRAGMENTED_END_PKT,
};

void BTAPP_TaskReq(uint8_t request);

// @ event define
enum {
    BT_EVENT_NONE = 0,

    BT_EVENT_CMD_SENT_ACK_OK,       //ACK OK
    BT_EVENT_CMD_SENT_ACK_ERROR,        //ACK error
    BT_EVENT_CMD_SENT_NO_ACK,           //no ACK
    
    BT_EVENT_NSPK_STATUS,
    BT_EVENT_LINE_IN_STATUS,
    BT_EVENT_A2DP_STATUS,
    BT_EVENT_CALL_STATUS_CHANGED,

    BT_EVENT_HFP_CONNECTED,
    BT_EVENT_HFP_DISCONNECTED,
    BT_EVENT_A2DP_CONNECTED,
    BT_EVENT_A2DP_DISCONNECTED,
    BT_EVENT_AVRCP_CONNECTED,
    BT_EVENT_AVRCP_DISCONNECTED,
    BT_EVENT_SPP_CONNECTED,
    BT_EVENT_IAP_CONNETED,
    BT_EVENT_SPP_IAP_DISCONNECTED,
    BT_EVENT_ACL_CONNECTED,
    BT_EVENT_ACL_DISCONNECTED,
    BT_EVENT_SCO_CONNECTED,
    BT_EVENT_SCO_DISCONNECTED,
    BT_EVENT_MAP_CONNECTED,
    BT_EVENT_MAP_DISCONNECTED,

    BT_EVENT_SYS_POWER_ON,
    BT_EVENT_SYS_POWER_OFF,
    BT_EVENT_SYS_STANDBY,
    BT_EVENT_SYS_PAIRING_START,
    BT_EVENT_SYS_PAIRING_OK,
    BT_EVENT_SYS_PAIRING_FAILED,

    BT_EVENT_LINKBACK_SUCCESS,
    BT_EVENT_LINKBACK_FAILED,

    BT_EVENT_BD_ADDR_RECEIVED,
    BT_EVENT_NAME_RECEIVED,
    BT_EVENT_PAIR_RECORD_RECEIVED,
    BT_EVENT_LINK_MODE_RECEIVED,

    BT_EVENT_PLAYBACK_STATUS_CHANGED,
    BT_EVENT_AVRCP_VOLUME_CTRL,
    BT_EVENT_AVRCP_ABS_VOLUME_CHANGED,
    BT_EVENT_HFP_VOLUME_CHANGED,
	BT_EVENT_TYPE_CODEC,

    
    NSPK_EVENT_SYNC_POWER_OFF,
    NSPK_EVENT_SYNC_VOL_CTRL,
    NSPK_EVENT_SYNC_INTERNAL_GAIN,
    NSPK_EVENT_SYNC_ABS_VOL,
    NSPK_EVENT_CHANNEL_SETTING,
    NSPK_EVENT_ADD_SPEAKER3,
    
    LE_STATUS_CHANGED,
    LE_ADV_CONTROL_REPORT,
    LE_CONNECTION_PARA_REPORT,
    LE_CONNECTION_PARA_UPDATE_RSP,
    GATT_ATTRIBUTE_DATA,
    
    PORT0_INPUT_CHANGED,
    PORT1_INPUT_CHANGED,
    PORT2_INPUT_CHANGED,
    PORT3_INPUT_CHANGED,

	NSPK_EVENT_VENDOR_CMD,
	NSPK_EVENT_VOL_MODE,
	NSPK_EVENT_EQ_MODE,	
	FEATURE_LIST_REPLY

};

#define DSP_EQ_SIZE    84
#define DSP_EQ_SEND_INTERVAL   100		   //  100ms
#define VENDOR_CMD_SIZE 	   9   
#define BTEQ_MAX_INDEX		   11		   // 84bytes + 1-seq each packet ==> 84/8 = 11 packets


enum {
    BT_STATUS_NONE,
    BT_STATUS_OFF,
    BT_STATUS_ON,
    BT_STATUS_READY
};
typedef enum {
    BT_SYSTEM_INIT,         //init
    BT_SYSTEM_POWER_OFF,    //event
    BT_SYSTEM_POWER_ON,     //event
    BT_SYSTEM_STANDBY,      //event
    BT_SYSTEM_CONNECTED,    //event
    BT_SYSTEM_PAIRING,      //event
} BT_SYS_STATUS;        // BM64 internal system status
#define BIT_SCO_LINK_STATUS 0x01//bit0: SCO link status
#define BIT_ACL_LINK_STATUS 0x02//bit1: ACL link status
#define BIT_HFP_LINK_STATUS 0x04//bit2: HFP link status
#define BIT_A2DP_LINK_STATUS 0x08//bit3: A2DP link status
#define BIT_AVRCP_LINK_STATUS 0x10//bit4: AVRCP link status
#define BIT_SPP_LINK_STATUS 0x20//bit5: SPP link status
#define BIT_IAP_LINK_STATUS 0x40//bit6: iAP link status
#define BIT_MAP_LINK_STATUS 0x80//bit7: MAP link status

uint8_t BTAPP_GetStatus(void);
void BT_SendEQBytes(void);


void BTAPP_EventHandler(uint8_t event, uint16_t para, uint8_t* para_full);

void BTAPP_EnterBTPairingMode( void );
/*void BTAPP_SetBTDiscoverable( void );*/
void BTAPP_ResetEEPROMtoDefault( void );
void BTAPP_PlayNextSong( void );
void BTAPP_PlayPreviousSong( void );
void BTAPP_PlayPause( void );
void BTAPP_StartFastForward( void );
void BTAPP_StartFastRewind( void );
void BTAPP_CancelForwardOrRewind( void );
void BTAPP_BroadcastBtnLongPress(void);
void BTAPP_BroadcastBtnDbClick(void);
void BTAPP_ExitBroadcastRegisterMode( void );
void BTAPP_GroupSpeakerSoundSync( void );
void BTAPP_NSPKBtnLongPress( void );
void BTAPP_NSPKBtnDbClick( void );
void BTAPP_NSPKBtnShortPress( void );
void BTAPP_CallEventShort( void );
void BTAPP_CallEventLong(void);
void BTAPP_VolUp(uint8_t cmdInfo);
void BTAPP_VolDown( uint8_t cmdInfo );
//void BTAPP_LineInEvent( uint8_t lineInIsPlugged);
bool getI2SAuxInJumper( void );
bool getDatabase3Jumper( void );
//SPP data exchange
void BT_SPPBuffClear( void );
bool BTAPP_SendDataOverSPP(uint8_t* addr, uint32_t size);
bool BTAPP_SendCharOverSPP(uint8_t byte);
bool BT_AddBytesToSPPBuff(uint8_t* data, uint8_t size);
bool BT_AddBytesToSPPBuffFromBeginning(uint8_t* data, uint8_t size, bool data_True_Command_False)  ;   
bool BT_AddBytesToSPPBuff_Fragmented_Pkt(uint8_t* data, uint8_t size, uint8_t pkt_type);
void SPPTask(void);                                 //test
uint8_t IsSPPTaskIdle(void);

bool BT_ReadOneByteFromSPPBuff( uint8_t* byte );
void BT_SaveLocalBDAddress(uint8_t* address);
void BT_SaveMasterBDAddress(uint8_t* address);
bool BT_CustomerGATT_AttributeData(uint8_t attributeIndex, uint8_t* attributeData, uint8_t attributeDataLength);
bool BT_isBLEConnected(void);
bool BT_SendMultiSpkEQBytes(uint8_t* data, uint8_t size);
void BT_SetMultiSpkEQRoute(uint8_t route);
bool BT_isA2DPPlaying(void);
bool BT_isA2DPPaused(void);
void BT_SaveDeviceName(uint8_t* name);
void BT_ToggleAudioPath(void);
void BT_A2DPAppStatus(void);
bool BT_isMaster(void);
bool BT_isStandalone(void);
void BT_SendVolInfo(void);
uint8_t BT_GetSysStatus(void);
uint8_t BT_GetLinkStatus(void);
void BTAPP_MFBOnMode(void);
void BT_SendMuteInfo(uint8_t mute);
bool BT_isCallIdle(void);
void BTAPP_MultiEventShort(void);


#endif
