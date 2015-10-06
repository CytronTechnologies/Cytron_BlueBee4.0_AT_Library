#include <HM12.h>
#include <SoftwareSerial.h>

HM12 bluebee(8,9);

void setup() {
  delay(5000);
  Serial.begin(115200);
  // put your setup code here, to run once:
  Serial.println("Start communicating with BlueBee");
  if(!bluebee.begin(115200))
    Serial.println("Init failed");
    
  if(!bluebee.setBaud(115200))
    Serial.println("Setup failed");

  if(!bluebee.reset())
    Serial.println("Reset failed");
  delay(5000);  
  Serial.println(bluebee.firmwareVersion());
  if(!bluebee.setBLEName("BlueBee4.0"))
  {
    Serial.println("Setup failed");
  }
  Serial.println(bluebee.BLEName());
  Serial.println(bluebee.EDRName());
  bluebee.setMode(1);
  Serial.println(bluebee.getMode());
//  if(!bluebee.setRole(1))
//  {
//    Serial.println("Setup failed");
//  }
  Serial.println(bluebee.getRole());
}

void loop() {
  // put your main code here, to run repeatedly:


}

void blinky()
{
  for(int i=0;i<12;i++)
  {
    bluebee.digitalWrite(3,bluebee.digitalRead(3)^1);
    delay(100);
  }
}

