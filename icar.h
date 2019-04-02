#ifndef __icar_h__
#define __icar_h__

//include library :
#include <Arduino.h> 
#include <SPI.h>
#include <mcp_can.h>

class icar
{
    public:
        icar();
        icar(long pin);
        void init_can();
        void init_FS_Pin(int FS_Pin);
        int Acceleration_Read(int Acc_pin)
        void analogCanWriter(unsigned char tab[8], long analog, unsigned char e)
        unsigned char initializingMessage(int target_board, long analog, unsigned char AV_AR, unsigned char FS_status); //data to send are : concerned Arduino, FS status, Avant ou arriere, acceleration(speed) value
        unsigned char MessageCanReader(unsigned char messagetoread[8]);
    protected:
        long _pin ;
        int _baud=9600 const;
        unsigned char message[8];
        int FootSwitch_pin;

};

#endif