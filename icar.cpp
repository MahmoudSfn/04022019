#include "SPI.h"
#include "mcp_can.h"

//TODO : 
/*
    1) initialisation du CAN
*/


int _SPI_CS_PIN=9;
MCP_CAN CAN(_SPI_CS_PIN);

icar::icar() 
{
    //default constructor
}

icar::icar(long pin)
{
    _pin = pin;
}

void icar::init_can()
{
    Serial.begin(_baud);
    while(CAN_OK != CAN.begin(CAN_500KBPS))
    {
        Serial.println("CAN BUS initialisation failed! Trying again ...");
        delay(10);
    }
    Serial.println("CAN BUS initialisation succeeded!");
}

void icar::init_FS_Pin(int FS_Pin)
{
    FootSwitch_pin = FS_Pin;
    pinMode(FootSwitch_pin, INPUT_PULLUP);
}

int icar::FootSwitch_Read(int FootSwitch_pin)
{   
    int fs = digitalRead(FootSwitch_pin);
    return fs;
}

int icar::Acceleration_Read(int Acc_pin)
{
    int analog = analogRead(Acc_pin);
    analog = map(analog_value, 0, 1023, 0,255);
    return analog;
} 

unsigned char initializingMessage(int target_board, int analog, int AV_AR, int FS_status)
{
    unsigned char message[8];

    message[0] = target_board;
    message[1] = analog_value;
    message[2] = FS_status;
    message[3] = AV_AR;
    message[4] = "0";
    message[5] = "0";
    message[6] = "0";
    message[7] = "0";

    return message;
}

void icar::MessageCanWriter(unsigned char messagetowrite[8])  //le messagetowrite porte les differente detail recuperer et qui sont
{
    message = messagetowrite;
    Can.sendMsgBuf(0x00,0,8,(byte *)message);
    delay(100);
}

unsigned char icar::MessageCanReader(unsigned char messagetoread[8])
{
    unsigned char length = 8;

    if(CAN_MSGAVAIL == CAN.checkRecive())
    {
        CAN.reasMsgBuf(&length, messagetoread);
        unsigned long canId = CAN.getCanId();
    }
    return messagetoread;
}