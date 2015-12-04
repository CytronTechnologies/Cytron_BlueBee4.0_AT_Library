#ifndef _HM12_H
#define _HM12_H

#include "Arduino.h"
#include "Stream.h"
#include <SoftwareSerial.h>

#define HM12_CMD_QUERY 0
#define	HM12_CMD_SETUP 1

#define SLAVE 0
#define	MASTER 1

class HM12: public Stream
{
  public:
	HM12(uint8_t rxpin, uint8_t txpin);
	bool begin(int32_t baudrate = 115200);
	void end();
	bool setBaud(int32_t baudrate);
	bool test();
	bool reset();
	bool digitalWrite(uint8_t pin, uint8_t state);
	uint8_t digitalRead(uint8_t pin);
	String firmwareVersion();
	bool setBLEName(String name);
	bool setEDRName(String name);
	String BLEName();
	String EDRName();
	String BLEMacAddress();
	String EDRMacAddress();
	bool setMode(uint8_t);
	uint8_t getMode();
	bool setRole(uint8_t);
	uint8_t getRole();
	bool setDualMode(bool);
	bool isDualMode();
	int getRSSB();
	int getRSSE();
	bool searchForNewDevice();
	
	int available();
	size_t write(uint8_t);
	int read();
	int peek();
	void flush();
	void listen();
  
  protected:
    Stream *_serial;
	
  private:
	uint8_t _rxpin;
	uint8_t _txpin;
	SoftwareSerial *swSerial;
	bool isHardwareSerial;
	String _buffer;
	void sendCommand(const char * cmd, uint8_t type = 2, const char * params = NULL);
	bool readForResponse(uint8_t * rsp);
  
};

#endif
