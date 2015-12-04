/* 
 * This sketch allows communication between Arduino and PC.
 * Steps:
 * 1. Upload the sketch to Arduino Board via USB cable.
 * 2. Stack it with XBee Shield + BlueBee 4.0.
 * 3. Set UART jumpers to RX - D0 and TX - D1.
 * 4. Disconnect Arduino from PC and power with external power supply.
 * 5. Connect Arduino with PC using Bluetooth.
 * 6. Open Serial Monitor with appropriate COM port.
 * 7. Send something to Arduino from PC using Serial Monitor.
 * 
 * For more info please refer to http://tutorial.cytron.com.my/2015/10/08/getting-started-with-bluebee-4-0/
   Communication between Computer and Microcontroller

   Author:  Ng Beng Chet from Cytron Technologies 
   Date:    4/12/2015
 */

#include <HM12.h>

HM12 BlueBee(0,1); //here using hardware Serial

void setup() {
  // put your setup code here, to run once:
  BlueBee.begin(115200); // set baudrate according to BlueBee 4.0 baudrate
}

void loop() {
  // put your main code here, to run repeatedly:
  if(BlueBee.available()>0) //wait for PC to send something to Arduino
  {
    String s="";
    while(BlueBee.available()) //if available
    {
      s+=(char)BlueBee.read(); //Read what PC has sent
      delay(5);
    }
    BlueBee.print("From BlueBee4.0: "); //Arduino send back to PC what have been read
    BlueBee.print(s);
    BlueBee.println();
  }
}
