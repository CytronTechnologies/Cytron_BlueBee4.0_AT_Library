/******************************************************************************
HM12AT.h
Cytron BlueBee 4.0 Module AT Command List header file
Created by Ng Beng Chet @ Cytron Technologies Sdn Bhd 
Original Creation Date: Oct 8, 2015
https://github.com/CytronTechnologies/Cytron_BlueBee4.0_AT_Library/

Development environment specifics:
	IDE: Arduino 1.6.5
	Hardware Platform: Arduino 

Distributed as-is; no warranty is given.
******************************************************************************/

#ifndef _HM12AT_H_
#define _HM12AT_H_

//////////////////////
// Common Responses //
//////////////////////
uint8_t RESPONSE_OK[] = "OK";
uint8_t RESPONSE_GET[] = "OK+Get:";
uint8_t RESPONSE_SET[] = "OK+Set:";
uint8_t RESPONSE_RSSI[] = "OK+RSSB:";
uint8_t RESPONSE_RST[] = "OK+RESET";
uint8_t RESPONSE_CLEARB[] = "OK+CLEAB";

///////////////////////
// Basic AT Commands //
///////////////////////
const char HM12_AT[] PROGMEM = "AT";
const char HM12_TEST[] PROGMEM= "";	// Test AT startup
const char HM12_RESET[] PROGMEM= "+RESET"; // Restart module
const char HM12_VERSION[] PROGMEM= "+VERS"; // View version info
const char HM12_BLENAME[] PROGMEM ="+NAMB";
const char HM12_EDRNAME[] PROGMEM = "+NAME";
const char HM12_BLEMAC[] PROGMEM = "+ADDB";
const char HM12_EDRMAC[] PROGMEM = "+ADDE";
const char HM12_MODE[] PROGMEM= "+MODE";
const char HM12_ROLE[] PROGMEM= "+ROLB";
const char HM12_DUAL[] PROGMEM= "+DUAL";
const char HM12_UART[] PROGMEM= "+BAUD"; // Factory reset
const char HM12_RSSI[] PROGMEM= "+RSSB";
const char HM12_CLEAB[] PROGMEM= "+CLEAB";
const char	HM12_PIN[] PROGMEM= "+PIO";

#endif