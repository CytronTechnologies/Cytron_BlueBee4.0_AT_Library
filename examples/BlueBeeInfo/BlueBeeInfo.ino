/*
 * This example sketch allows settings configuration of BlueBee 4.0 module.
 * Author:  Ng Beng Chet from Cytron Technologies
 * Date:    4/12/2015
 */

#include <HM12.h>
#include <SoftwareSerial.h>

HM12 bluebee(8,9); // here using softwareSerial, rx - pin 8 Arduino, tx - pin 9 Arduino

void setup() {
  delay(5000);
  Serial.begin(115200);
  // put your setup code here, to run once:
  Serial.println("Start communicating with BlueBee");
  if(!bluebee.begin(115200)) // communicate with BlueBee 4.0 with default baudrate 115200
    Serial.println("Init failed");
    
  if(!bluebee.setBaud(115200)) //set BlueBee 4.0 baudrate to 115200
    Serial.println("Setup failed");

  if(!bluebee.reset()) // software reset BlueBee 4.0
    Serial.println("Reset failed");
  delay(5000);  
  Serial.println(bluebee.firmwareVersion()); //get firmware version
  if(!bluebee.setBLEName("BlueBee4.0")) //set name for BLE mode
  {
    Serial.println("Setup failed");
  }
  Serial.println(bluebee.BLEName()); //show name for BLE mode
  Serial.println(bluebee.EDRName()); //show name for EDR mode
  bluebee.setMode(1); // set to remote control mode (0 - data transmission mode only, 1 - remote control and data transmission)
  Serial.println(bluebee.getMode()); //get current mode of BlueBee 4.0
  if(!bluebee.setRole(0)) // set role to slave (0- slave, 1 - master)
  {
    Serial.println("Setup failed");
  }
  Serial.println(bluebee.getRole()); // get current role of BlueBee 4.0 (0- slave, 1 - master)
}

void loop() {
  // put your main code here, to run repeatedly:
}

void blinky() // set BlueBee 4.0 pin 3 HIGH and LOW for blinking effect
{
  for(int i=0;i<12;i++)
  {
    bluebee.digitalWrite(3,bluebee.digitalRead(3)^1);
    delay(100);
  }
}

