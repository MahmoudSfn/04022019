#include <Arduino.h>
#include <mcp_can.h>
#include <SPI.h>

#include "icar.h"


icar ICar(1);
const int AVAR = 5;
const int FS = 3;
const int ACC = A0;

int AVAR_Status;
int FS_Status;
int ACC_Value;

unsigned char message_to_send[8] = {};

void setup() {
  Serial.begin(9600);
  ICar.init_can();
  ICar.init_FS_Pin(FS);
}

void loop() {
  //recuperer les information
  // 1) FS :
  FS_Status = ICar.FootSwitch_Read(FS);
  
  // 2) AVAR :
  AVAR_Status = ICar.AVAR_Read(AVAR);
  
  // 3) Acceleration
  ACC_Value = ICar.Acceleration_Read(ACC);
  
  //initialiser le message
  //diffuser le message au can
}
