/*
  Project Name: BM89 EVB                            Module name:yda174dsp_handler.c
  Bluetooth Chip: IS1689-151                        Bluetooth UI Version:
  MCU chip: SH79F6488
  Oscillator: IRIC                                  Freq: 12MHz
  Author: Jerry.Chen
  Kick off date: 2014-04-03
  Copyright: 2014 ISSC Technologies Corp.. All Rights Reserved.
*/

#include <xc.h>
#include "mcc/mcc.h"
#include "yda174dsp_handler.h"

#ifdef      PEQTab_TAB
uint8_t const PEQTab[ ] = {
    0x20, 0x00, 0x00,    /* Band0 */
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x20, 0x00, 0x00,    /* Band1 */
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x20, 0x00, 0x00,    /* Band2 */
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x20, 0x00, 0x00,    /* Band3 */
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x20, 0x00, 0x00,    /* Band4 */
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x20, 0x00, 0x00,    /* Band5 */
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x20, 0x00, 0x00,    /* Band6 */
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x20, 0x00, 0x00,    /* Band7 */
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x20, 0x00, 0x00,    /* Band8 */
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x20, 0x00, 0x00,    /* Band9 */
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00
};
#endif

uint8_t const VolTab[] = {
  //PRESETROM3 area
  0x37,         //0   -42.0dB    //refer to p209 of firmware manual
  0x33,         //1   -40.0dB    //refer to p209 of firmware manual
  0x2F,         //2   -38.0dB
  0x2B,         //3   -36.0dB
  0x27,         //4   -34.0dB
  0x23,         //5   -32.0dB
  0x1F,         //6   -30.0dB
  0x1B,         //7   -28.0dB
  0x17,         //8   -26.0dB
  0x13,         //9   -24.0dB     initial volume
  0x0F,         //10  -22.0dB
  0x0B,         //11  -20.0dB
  0x07,         //12  -18.0dB
  0x03,         //13  -16.0dB
  //PRESETROM2 area
  0xFF,         //14  -14.0dB
  0xFB,         //15  -12.0dB
  0xF7,         //16  -10.0dB
  0xF3,         //17  -08.0dB
  0xEF,         //18  -06.0dB
  0xEB,         //19  -04.0dB
  0xE7,         //20  -02.0dB
  0xE3,         //21  -00.0dB
  0xDF,         //22  +02.0dB
  0xDB,         //23  +04.0dB
  0xD7,         //24  +06.0dB
  0xD3,         //25  +08.0dB
  0xCF,         //26  +10.0dB
  0xCB,         //27  +12.0dB
  0xC7,         //28  +14.0dB
  0xC3,         //29  +16.0dB
  0xBF          //30  +18.0dB
};

struct flags
  {
     unsigned bit0     :1;
     unsigned bit1     :1;
     unsigned bit2     :1;
     unsigned bit3     :1;
     unsigned bit4     :1;
     unsigned bit5     :1;
     unsigned bit6     :1;
     unsigned bit7     :1;
  };
struct flags flag0;
#define yda174_status flag0.bit0
#define play_standby flag0.bit1
uint8_t ext_dsp_vol, yda_soundeffect_mode;
#define EXT_DSP_INIT_VOL 20
uint8_t   ram_bank_bak;
uint8_t DSP_Timer, I2C_limitedTimer;
#define YDADSP_DATA_BUFF_SIEZ 7
uint8_t   yda_data_buff[YDADSP_DATA_BUFF_SIEZ];
I2C_MESSAGE_STATUS i2c_status;
#define DSP_I2C_ADDR1 0x6C//0xD8
/*-----------------------------------------------------------------------------
Function name:
  yda174dsp_init
Description:
  This function used to initialize dsp

Notice:
  refer to p168~176 of the firmware manual of yamaha for intialization flow chart
  refer to p29~38 of yda174a30 for i2c interface
  refer to p111~ of yda174a30 for power on flow chart

Input Parameter:
  None
Return:
  None
*/
static bool DSP_Write(uint16_t dataLen, uint8_t* data)
{
//    uint16_t i;
//    uint8_t length;

    while(I2C_MasterQueueIsFull() == true);

    I2C_MasterWrite(data, dataLen, DSP_I2C_ADDR1, &i2c_status);

    I2C_limitedTimer = 5;
    while(!I2C_IsIdle())
    {
        if(!I2C_limitedTimer)
            return false;
    }
    return true;
}

void DSP_Timer1MS_event(void)
{
    DSP_Timer++;
    if(I2C_limitedTimer)
        --I2C_limitedTimer;
}
void Delay_Some(unsigned int D_Count)
{
    unsigned int i;
    for (i= 0; i< D_Count; i++)
        Nop();
}
void yda174dsp_init(void)
{
  ext_dsp_vol = EXT_DSP_INIT_VOL;
  yda_soundeffect_mode = SOUNDEFFECT1;

//  ram_bank_bak = 0x40;
//  INSCON = 0x40;      //Select bank 1

  DSP_RESET_SetLow();//RST_DSP = LOW;
  DSP_POWER_DN_SetLow();//DSP_SLEEP = LOW;       //step1-A

  //Delay for >=15mS
  DSP_Timer = 0;
  for ( ; DSP_Timer < 15; ) ;


  DSP_RESET_SetHigh();//RST_DSP = HIGH;             //step1-B
  DSP_Timer = 0;
  for ( ; DSP_Timer < 3; ) ;

  DSP_POWER_DN_SetHigh();//DSP_SLEEP = HIGH;       //step1-C

//  ram_bank_bak = 0x00;
//  INSCON = 0x00;      //Select bank 0

//  P2CR = 0x00;        //1:output
//  P2PCR = 0xF2;
  DSP_PORT_TRIS = INPUT; //TRISB |= 0B00110000;  //IRQ_N,PROT_N as input mode
  DSP_IRQ_TRIS = INPUT; //TRISB |= 0B00110000;  //IRQ_N,PROT_N as input mode

//  ram_bank_bak = 0x40;
//  INSCON = 0x40;      //Select bank 1


  yda_data_buff[0] = PRESETROM0;
  yda_data_buff[1] = 0xC1;                    //step2   set to A/V mode, refer to 81/p199 of firmware manual
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );

  yda_data_buff[0] = PRESETROM0;
  yda_data_buff[1] = 0xD5;//5;                //HS 10Band PEQ +0, 3b, refer to 83/p199 of firmware manual
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );

  yda_data_buff[0] = PRESETROM2;
  yda_data_buff[1] = 0xBE;                    //step 3    SV SDSP Sel, refer to 139/p207 of firmware manual
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );


  yda_data_buff[0] = RAM_WRITE_READ;
  yda_data_buff[1] = 0x40;
  yda_data_buff[2] = 0x7F;
  yda_data_buff[3] = 0x00;
  yda_data_buff[4] = 0x07;
  yda_data_buff[5] = 0x00;
  yda_data_buff[6] = 0x04;                    //step4  ,refer to p76 of firmware manual
  Delay_Some(80);
  DSP_Write( 7, yda_data_buff );

  yda_data_buff[0] = PRESETROM2;
  yda_data_buff[1] = 0x44;                    //step5-A       LPS No Delay, refer to 85/p205 of firmware manual
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );

  yda_data_buff[0] = PRESETROM2;
  yda_data_buff[1] = 0x6D;                    //P3D DTV Sports, refer to 109/p2XX of firmware manual
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );

  yda_data_buff[0] = PRESETROM3;
  yda_data_buff[1] = 0xD6;                    //D3;  step5-B     DTV Theater/Sports, refer to p163/213 of firmware manual
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );

#ifdef      PEQTab_TAB
  Delay_Some(80);
  DSP_Write( ( sizeof(PEQTab)/sizeof(PEQTab[0]) ), (uint8_t *) PEQTab );         //step 6
#endif

  yda_data_buff[0] = AIFMD;
  yda_data_buff[1] = AIFMD_EN_IN_INSIDE;     //step7
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );

  yda_data_buff[0] = MDSPMD;
  yda_data_buff[1] = MDSPMD_RUN_TRANSFER;    //step8
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );

  yda_data_buff[0] = GAIN;
  yda_data_buff[1] = GAIN_P6DB;              //step9
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );

  yda_data_buff[0] = GAIN;
  yda_data_buff[1] = GAIN_N6DB;               //GAIN_P6DB;              //step9
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );

  yda_data_buff[0] = AIFIFMT;
  yda_data_buff[1] = (AIFIFMT_INPUT_I2S_FORMAT|AIFIFMT_24BIT|AIFIFMT_START_FRAME_FALLING|AIFIFMT_CHANGE_BCLK_FALLING);     //step10-A
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );

  yda_data_buff[0] = AIFOFMT;
  yda_data_buff[1] = (AIFOFMT_OUTPUT_I2S_FORMAT|AIFOFMT_24BIT|AIFOFMT_START_FRAME_FALLING|AIFOFMT_CHANGE_BLCK_FALLING);    //step10-B
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );


  yda_data_buff[0] = SDSPMD;
  yda_data_buff[1] = SDSPMD_DEFAULT;              //step10-C
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );

  yda_data_buff[0] = DAMPMD;
  yda_data_buff[1] = DAMPMD_DEFAULT;              //step10-D
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );

  yda_data_buff[0] = IRQN;
  yda_data_buff[1] = IRQN_DIS_TO_IRQPIN;
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );


  yda_data_buff[0] = FSM;
  yda_data_buff[1] = FSM_DEFAULT;                 //step10-E
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );

  yda_data_buff[0] = PLLERR;
  yda_data_buff[1] = PLLERR_ERR_DETECT_DIS;       //step10-F
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );

  yda_data_buff[0] = DSPSTART;
  yda_data_buff[1] = (DSPSTART_MDSP2_START | DSPSTART_SDSP_START );  //step11
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );

  yda_data_buff[0] = PRESETROM2;
  yda_data_buff[1] = 0x4D;                    //step12-A     LPS SDI0 Sel, refer to 85/p205 of firmware manual
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );

  yda_data_buff[0] = PRESETROM2;
  yda_data_buff[1] = 0x4A;                    //step12-B      LPS Through Sel, refer to 85/p205 of firmware manual
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );

  yda_data_buff[0] = PRESETROM1;
  yda_data_buff[1] = 0x27;                    //DRC3 Bass Boost 0, refer to 115/p2xx of firmware manual
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );

  yda_data_buff[0] = PRESETROM1;
  yda_data_buff[1] = 0x59;                    //step12-C      GEQ FM Mix, refer to 125/p201 of firmware manual
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );

  yda_data_buff[0] = PRESETROM1;
  yda_data_buff[1] = 0x58;                    //step12-D      GEQ Active, refer to 125/p201 of firmware manual
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );

  yda_data_buff[0] = PRESETROM2;
  yda_data_buff[1] = 0xB7;                    //SV Ln DEQ0 High, refer to 139/p207 of firmware manual
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );

  yda_data_buff[0] = PRESETROM2;
  yda_data_buff[1] = 0xBC;                    //step12-E   SV Ln Active, refer to 139/p207 of firmware manual
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );

  yda_data_buff[0] = PRESETROM2;
  yda_data_buff[1] = 0xB4;                    //step13-A   SV Curve Mid, refer to 139/p207 of firmware manual
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );

  yda_data_buff[0] = MUTE;
  yda_data_buff[1] = (MUTE_MDSP2MUTE_CANCLE | MUTE_SDSPMUTE_CANCLE);    //step13-C
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );

  DSP_Timer = 0;
  for ( ; DSP_Timer < 20; ) ;                //110

  yda_data_buff[0] = MUTE;
  yda_data_buff[1] = (MUTE_QMUTE_EN | MUTE_MDSP2MUTE_CANCLE | MUTE_SDSPMUTE_CANCLE);  //step13-D
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );

  DSP_MUTE_SetHigh();//MUTE_DSP = HIGH;


//  ram_bank_bak = 0x00;
//  INSCON = 0x00;      //Select bank 0

  yda174_soundeffec1();
  yda174_voladj();
}




/*-----------------------------------------------------------------------------
Function name:
  yda174_soundeffec1
Description:
  This function used to set yda174 sound effection

Notice:
  refer to p168~176 of the firmware manual of yamaha for intialization flow chart
  refer to p29~38 of yda174a30 for i2c interface
  refer to p111~ of yda174a30 for power on flow chart

Input Parameter:
  None
Return:
  None
*/
void yda174_soundeffec1(void)
{
  yda_data_buff[0] = PRESETROM2;
  yda_data_buff[1] = 0x73;                   //P3D DTV Through, refer to 109/p2XX of firmware manual
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );

  yda_data_buff[0] = PRESETROM1;
  yda_data_buff[1] = 0x2A;                   // DRC3 Through, refer to 115/p2xx of firmware manual
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );

  yda_data_buff[0] = PRESETROM1;
  yda_data_buff[1] = 0x5D;                   //GEQ Bass -6dB , refer to 125/p213 of firmware manual
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );

  yda_data_buff[0] = PRESETROM1;
  yda_data_buff[1] = 0x6F;                   // GEQ Treble 0dB,  refer to p125/213 of firmware manual
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );

  yda_data_buff[0] = PRESETROM1;
  yda_data_buff[1] = 0x4F;                   //GEQ Flat , refer to p201 of firmware manual
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );

  yda_data_buff[0] = PRESETROM3;
  yda_data_buff[1] = 0xDA;                   //DTV Through, refer to p164/213 of firmware manual
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );

  yda174_voladj();
}



/*-----------------------------------------------------------------------------
Function name:
  yda174_soundeffec2
Description:
  This function used to set yda174 sound effection

Notice:
  refer to p168~176 of the firmware manual of yamaha for intialization flow chart
  refer to p29~38 of yda174a30 for i2c interface
  refer to p111~ of yda174a30 for power on flow chart

Input Parameter:
  None
Return:
  None
*/
void yda174_soundeffec2(void)
{
  uint8_t     temp;


  temp = ext_dsp_vol;

  if ( ext_dsp_vol  > 4 )
  {
    ext_dsp_vol -= 4;
  }
  else
  {
    ext_dsp_vol = 0;
  }

  yda174_voladj();
  ext_dsp_vol = temp;

  //...P3_0 = HIGH;                               //mode 1 leds on

  ram_bank_bak = 0x40;
//  INSCON = 0x40;                             //Select bank 1

  yda_data_buff[0] = PRESETROM2;
  yda_data_buff[1] = 0x74;                   //P3D DTV Active, refer to 109/p2XX of firmware manual
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );

  yda_data_buff[0] = PRESETROM1;
  yda_data_buff[1] = 0x2B;                   //DRC3 Active, refer to 115/p2xx of firmware manual
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );

  yda_data_buff[0] = PRESETROM1;
  yda_data_buff[1] = 0x5F;                   //GEQ Bass -2dB , refer to 125/p213 of firmware manual
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );

  yda_data_buff[0] = PRESETROM1;
  yda_data_buff[1] = 0x51;                   // GEQ Dynamic , refer to p201 of firmware manual
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );

  yda_data_buff[0] = PRESETROM3;
  yda_data_buff[1] = 0xDB;                   //DTV Active, refer to p164/213 of firmware manual
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );

  //...yda_soundeffect_mode = SOUNDEFFECT2;       //SOUNDEFFECT0;
  ram_bank_bak = 0x00;
//  INSCON = 0x00;                             //Select bank 0
}


/*-----------------------------------------------------------------------------
Function name:
  yda174_soundeffec3
Description:
  This function used to set yda174 sound effection

Notice:
  refer to p168~176 of the firmware manual of yamaha for intialization flow chart
  refer to p29~38 of yda174a30 for i2c interface
  refer to p111~ of yda174a30 for power on flow chart

Input Parameter:
  None
Return:
  None
*/
void yda174_soundeffec3(void)
{
  uint8_t     temp;


  temp = ext_dsp_vol;

  if ( ext_dsp_vol  > 2 )
  {
    ext_dsp_vol -= 2;
  }
  else
  {
    ext_dsp_vol = 0;
  }

  yda174_voladj();
  ext_dsp_vol = temp;

  //P3_0 = LOW;                               //mode 1 leds off
  //P3_1 = HIGH;                              //mode 2 leds on

  ram_bank_bak = 0x40;
//  INSCON = 0x40;      //Select bank 1

  yda_data_buff[0] = PRESETROM2;
  yda_data_buff[1] = 0x73;                   //P3D DTV Through, refer to 109/p2XX of firmware manual
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );

  //yda_data_buff[0] = PRESETROM1;
  //yda_data_buff[1] = 0x2A;                   // DRC3 Through, refer to 115/p2xx of firmware manual
  //DSP_Write( 2, yda_data_buff );

  yda_data_buff[0] = PRESETROM1;
  yda_data_buff[1] = 0x5B;                   //GEQ Bass -10dB , refer to 125/p213 of firmware manual
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );

  yda_data_buff[0] = PRESETROM1;
  yda_data_buff[1] = 0x71;                   // GEQ Treble 4dB,  refer to p125/213 of firmware manual
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );

  yda_data_buff[0] = PRESETROM1;
  yda_data_buff[1] = 0x57;                   // GEQ Through, refer to p125/p201 of firmware manual
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );

  //yda_data_buff[0] = PRESETROM3;
  //yda_data_buff[1] = 0xDA;                   //DTV Through, refer to p164/213 of firmware manual
  //DSP_Write( 2, yda_data_buff );

  //...yda_soundeffect_mode = SOUNDEFFECT0;

  ram_bank_bak = 0x00;
 // INSCON = 0x00;      //Select bank 0
}


void yda174_soundeffec_change(void)
{
    switch(yda_soundeffect_mode)
    {
        case SOUNDEFFECT1:
            yda_soundeffect_mode = SOUNDEFFECT2;
            yda174_soundeffec2();
            break;
        case SOUNDEFFECT2:
            yda_soundeffect_mode = SOUNDEFFECT3;
            yda174_soundeffec3();
            break;
        case SOUNDEFFECT3:
            yda_soundeffect_mode = SOUNDEFFECT1;
            yda174_soundeffec1();
            break;
        default:
            yda_soundeffect_mode = SOUNDEFFECT1;
            yda174_soundeffec1();
            break;
    }
}

/*-----------------------------------------------------------------------------
Function name:
  yda174_audio_interace_setting
Description:
  This function used to enable playback

Notice:
  refer to p168~176 of the firmware manual of yamaha for intialization flow chart
  refer to p29~38 of yda174a30 for i2c interface
  refer to p111~ of yda174a30 for power on flow chart

Input Parameter:
  None
Return:
  None
*/
void yda174_playback(void)
{
  ram_bank_bak = 0x40;
//  INSCON = 0x40;      //Select bank 1

  DSP_POWER_DN_SetHigh();//DSP_SLEEP = HIGH;
  DSP_MUTE_SetHigh();//MUTE_DSP = HIGH;
  yda174_status = true;

  play_standby = false;

  ram_bank_bak = 0x00;
 // INSCON = 0x00;      //Select bank 0
}


/*-----------------------------------------------------------------------------
Function name:
  yda174_stop
Description:
  This function used to stop playbck

Notice:
  refer to p168~176 of the firmware manual of yamaha for intialization flow chart
  refer to p29~38 of yda174a30 for i2c interface
  refer to p111~ of yda174a30 for power on flow chart

Input Parameter:
  None
Return:
  None
*/
void yda174_stop(void)
{
  //ram_bank_bak = 0x40;
  //INSCON = 0x40;      //Select bank 1

  //MUTE_DSP = LOW;
  yda174_status = false;
  play_standby = true;
  //DSP_SLEEP = LOW;

  //ram_bank_bak = 0x00;
  //INSCON = 0x00;      //Select bank 0
}



/*-----------------------------------------------------------------------------
Function name:
  yda174_voladj
Description:
  This function used to set yda174 volume

Notice:
  refer to p168~176 of the firmware manual of yamaha for intialization flow chart
  refer to p29~38 of yda174a30 for i2c interface
  refer to p111~ of yda174a30 for power on flow chart

Input Parameter:
  None
Return:
  None
*/
void yda174_voladj(void)
{
  ram_bank_bak = 0x40;
//  INSCON = 0x40;      //Select bank 1

  yda_data_buff[1] = VolTab[ ext_dsp_vol ];     //Software volume
  if ( yda_data_buff[1] >= 0xBF )
  {
    yda_data_buff[0] = PRESETROM2;
  }
  else
  {
    yda_data_buff[0] = PRESETROM3;
  }

  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );

  ram_bank_bak = 0x00;
 // INSCON = 0x00;      //Select bank 0
}

/*-----------------------------------------------------------------------------
Function name:
  yda174_QMute
Description:
  This function used to set yda174 quite mute

Notice:
  refer to p168~176 of the firmware manual of yamaha for intialization flow chart
  refer to p29~38 of yda174a30 for i2c interface
  refer to p111~ of yda174a30 for power on flow chart

Input Parameter:
  None
Return:
  None
*/
void yda174_QMute(void)
{
  ram_bank_bak = 0x40;
  yda_data_buff[0] = MUTE;
  yda_data_buff[1] = (MUTE_MDSP2MUTE_CANCLE | MUTE_SDSPMUTE_CANCLE);  //step13-D
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );
  ram_bank_bak = 0x00;
}

/*-----------------------------------------------------------------------------
Function name:
  yda174_QMute
Description:
  This function used to set yda174 quite mute

Notice:
  refer to p168~176 of the firmware manual of yamaha for intialization flow chart
  refer to p29~38 of yda174a30 for i2c interface
  refer to p111~ of yda174a30 for power on flow chart

Input Parameter:
  None
Return:
  None
*/
void yda174_QMuteOff(void)
{
  ram_bank_bak = 0x40;
  yda_data_buff[0] = MUTE;
  yda_data_buff[1] = (MUTE_QMUTE_EN | MUTE_MDSP2MUTE_CANCLE | MUTE_SDSPMUTE_CANCLE);  //step13-D
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );
  ram_bank_bak = 0x00;
}


/*-----------------------------------------------------------------------------
Function name:
  yda174_AllMute
Description:
  This function used to set yda174 all mute

Notice:
  refer to p168~176 of the firmware manual of yamaha for intialization flow chart
  refer to p29~38 of yda174a30 for i2c interface
  refer to p111~ of yda174a30 for power on flow chart

Input Parameter:
  None
Return:
  None
*/
void yda174_AllMute(void)
{
  ram_bank_bak = 0x40;
  yda_data_buff[0] = MUTE;
  yda_data_buff[1] = MUTE_DEFAULT;  //step13-D
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );
  ram_bank_bak = 0x00;
}

/*-----------------------------------------------------------------------------
Function name:
  yda174_DSPStop
Description:
  This function used to stop yda174 dsp

Notice:
  refer to p168~176 of the firmware manual of yamaha for intialization flow chart
  refer to p29~38 of yda174a30 for i2c interface
  refer to p111~ of yda174a30 for power on flow chart

Input Parameter:
  None
Return:
  None
*/
void yda174_DSPStop(void)
{
  ram_bank_bak = 0x40;
//  INSCON = 0x40;      //Select bank 1

  yda_data_buff[0] = DSPSTART;
  yda_data_buff[1] = DSPSTART_DEFAULT;  //step11
  Delay_Some(80);
  DSP_Write( 2, yda_data_buff );

  ram_bank_bak = 0x00;
//  INSCON = 0x00;      //Select bank 0
}
/*
uint8_t yda174_Get4bitsVol(void)
{
    return ext_dsp_vol>>1;
}        

uint8_t yda174_Get7bitsVol(void)
{
    return ext_dsp_vol*127/30;
} 

void yda174_Set4bitVol(uint8_t vol)
{
    vol &= 0x0f;
    ext_dsp_vol = vol<<1;
    yda174_voladj();
}

void yda174_Set7bitVol(uint8_t vol)
{
    vol &= 0x7f;
    ext_dsp_vol = vol*30/127;
    yda174_voladj();
}*/

/*uint8_t yda174_GetVol(void)
{
    return ext_dsp_vol;
}*/

/*-----------------------------------------------------------------------------
 *
*/
void yda174_vol_up(void)
{
    if(!ext_dsp_vol)
        yda174_QMuteOff();
    if(ext_dsp_vol < 30)
    {
        ext_dsp_vol++;
        yda174_voladj();
    }
}


/*-----------------------------------------------------------------------------
 *
*/
void yda174_vol_down(void)
{
    if(ext_dsp_vol > 0)
    {
        ext_dsp_vol --;
        yda174_voladj();

        if(!ext_dsp_vol)
            yda174_AllMute();
    }
}

void yda174_SetVol(uint8_t vol)
{
    if(ext_dsp_vol != vol)
    {
        if(!vol)        //new volume is 0, old volume is non-zero.
            yda174_AllMute();
        else if(!ext_dsp_vol)       //old volume is 0, new volume is non-zero
            yda174_QMuteOff();
        if (vol <= 30) {
            ext_dsp_vol = vol;
            yda174_voladj();
        }
    }
}

void yda174_ForceMute(uint8_t mute)
{
	if(mute)
		yda174_AllMute();
	else		//old volume is 0, new volume is non-zero
		yda174_QMuteOff();
}

