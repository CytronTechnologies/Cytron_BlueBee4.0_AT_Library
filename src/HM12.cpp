/******************************************************************************
HM12.cpp
Cytron BlueBee 4.0 Module Library file
Created by Ng Beng Chet @ Cytron Technologies Sdn Bhd 
Original Creation Date: Oct 8, 2015
https://github.com/CytronTechnologies/Cytron_BlueBee4.0_AT_Library/

Development environment specifics:
	IDE: Arduino 1.6.5
	Hardware Platform: Arduino 

Distributed as-is; no warranty is given.
******************************************************************************/

#include "HM12.h"
#include "utils/HM12AT.h"

HM12::HM12(uint8_t rxpin, uint8_t txpin)
{  
  _rxpin = rxpin;
  _txpin = txpin;
  _buffer.reserve(25);
}

bool HM12::begin(int32_t baudrate)
{
	if(_rxpin==0&&_txpin==1)
	{
		Serial.begin(baudrate);
		_serial = &Serial;
		isHardwareSerial = true;
	}
	else
	{
		swSerial = new SoftwareSerial(_rxpin,_txpin);
		swSerial->begin(baudrate);
		_serial = swSerial;
		isHardwareSerial = false;
	}
	delay(100);
	
	if(reset())
	{
		int i = 100;
		while(i--)
		{
			if(test()) 
			{
				delay(100);
				return true;
			}
			delay(100);
		}
	}
	
	return false;
}

void HM12::end()
{
	if(_rxpin==0&&_txpin==1)
	{
		Serial.end();
		free(_serial);
	}
	else
	{
		swSerial->end();
		free(_serial);
	}
}

bool HM12::setBaud(int32_t baudrate)
{
	const char* num = "6";
	switch(baudrate)
	{
		case 9600: num = "2";break;
		case 19200: num = "3";break;
		case 38400: num = "4";break;
		case 57600: num = "5";break;
		case 115200: num = "6";break;
	}
	
	sendCommand(HM12_UART, HM12_CMD_SETUP, num);
	if(readForResponse(RESPONSE_SET))
	{
		if(_buffer.equals((String)num)) return reset();
		else return false;
	}
	return false;
}

bool HM12::test()
{
	sendCommand(HM12_TEST); // Send AT

	return readForResponse(RESPONSE_OK);
}

bool HM12::reset()
{
	sendCommand(HM12_RESET); // Send AT+RESET
	return readForResponse(RESPONSE_RST);
}

String HM12::firmwareVersion()
{
	sendCommand(HM12_VERSION,HM12_CMD_QUERY);
	if(readForResponse(RESPONSE_GET)) return _buffer;
	else return "";
}

bool HM12::setBLEName(String name)
{
	sendCommand(HM12_BLENAME,HM12_CMD_SETUP,name.c_str());
	if(readForResponse(RESPONSE_SET)) 
	{
		if(_buffer.equals(name)) return true;
	}
	return false;
}
bool HM12::setEDRName(String name)
{
	sendCommand(HM12_EDRNAME,HM12_CMD_SETUP,name.c_str());
	if(readForResponse(RESPONSE_SET)) 
	{
		if(_buffer.equals(name)) return true;
	}
	return false;
}

String HM12::BLEName()
{
	sendCommand(HM12_BLENAME,HM12_CMD_QUERY);
	if(readForResponse(RESPONSE_GET)) return _buffer;
	else return "";
}

String HM12::EDRName()
{
	sendCommand(HM12_EDRNAME,HM12_CMD_QUERY);
	if(readForResponse(RESPONSE_GET)) return _buffer;
	else return "";
}

String HM12::BLEMacAddress()
{
	sendCommand(HM12_BLEMAC,HM12_CMD_QUERY);
	if(readForResponse(RESPONSE_GET)) return _buffer;
	else return "";
}

String HM12::EDRMacAddress()
{
	sendCommand(HM12_EDRMAC,HM12_CMD_QUERY);
	if(readForResponse(RESPONSE_GET)) return _buffer;
	else return "";
}

bool HM12::setMode(uint8_t mode)
{
	const char *_mode;
	if(mode >0) _mode = "1";
	else _mode = "0";
	
	sendCommand(HM12_MODE,HM12_CMD_SETUP, _mode);
	if(readForResponse(RESPONSE_SET)) 
	{
		if(_buffer.equals(_mode)) return true;
	}
	return false;
}

uint8_t HM12::getMode()
{
	sendCommand(HM12_MODE,HM12_CMD_QUERY);
	if(readForResponse(RESPONSE_GET))
	{
		if(_buffer.equals("1")) return 1;
	}
	
	return 0; 
}

bool HM12::setRole(uint8_t role)
{
	const char* _role;
	if(role >0) _role = "1";
	else _role = "0";
	
	sendCommand(HM12_ROLE,HM12_CMD_SETUP, _role);
	if(readForResponse(RESPONSE_SET)) 
	{
		if(_buffer.equals(_role)) return true;
	}
	return false;
}

uint8_t HM12::getRole()
{
	sendCommand(HM12_ROLE,HM12_CMD_QUERY);
	if(readForResponse(RESPONSE_GET))
	{
		if(_buffer.equals("1")) return 1;
	}
	
	return 0; 
}

bool HM12::setDualMode(bool enable)
{
	const char* _mode;
	if(enable) _mode = "0";
	else _mode = "1";
	
	sendCommand(HM12_DUAL,HM12_CMD_SETUP, _mode);
	if(readForResponse(RESPONSE_SET)) 
	{
		if(_buffer.equals(_mode)) return true;
	}
	return false;
}

bool HM12::isDualMode()
{
	sendCommand(HM12_DUAL,HM12_CMD_QUERY);
	if(readForResponse(RESPONSE_GET))
	{
		if(_buffer.equals("0")) return true;
	}
	
	return false; 
}

int HM12::getRSSB()
{
	sendCommand(HM12_RSSB,HM12_CMD_QUERY);
	if(readForResponse(RESPONSE_RSSB))
	{
		return _buffer.toInt();
	}
	
	return 0; 
}

int HM12::getRSSE()
{
	sendCommand(HM12_RSSE,HM12_CMD_QUERY);
	if(readForResponse(RESPONSE_RSSE))
	{
		return _buffer.toInt();
	}
	
	return 0; 
}

bool HM12::searchForNewDevice()
{
	sendCommand(HM12_CLEAB);
	return readForResponse(RESPONSE_CLEARB);
}

bool HM12::digitalWrite(uint8_t pin, uint8_t state)
{
	String _pin="";
	if(pin>=2&&pin<=11)
	{
		if(pin==10) _pin = "A";
		else if(pin==11) _pin = "B";
		else _pin = (String)pin;
	}
	else return false;

	String params = _pin + (state>0? "1":"0");
	sendCommand(HM12_PIN, HM12_CMD_SETUP, params.c_str());
	if(readForResponse(RESPONSE_SET))
	{
		if(_buffer.equals(state>0? "1":"0")) return true;
	}
	return false;
}

uint8_t HM12::digitalRead(uint8_t pin)
{
	String _pin="";
	if(pin>=2&&pin<=11)
	{
		if(pin==10) _pin = "A";
		else if(pin==11) _pin = "B";
		else _pin = (String)pin;
	}
	else return 0;

	String params = _pin + "?";
	sendCommand(HM12_PIN, HM12_CMD_SETUP, params.c_str());
	if(readForResponse(RESPONSE_GET))
	{
		if(_buffer.equals("1")) return 1;
	}
	return 0;
}

int HM12::available()
{
	int available = _serial->available();
	if(available==0) delay(50);
	
	return _serial->available();
}

size_t HM12::write(uint8_t c)
{
	return _serial->write(c);
}

int HM12::read()
{
	return _serial->read();
}

int HM12::peek()
{
	return _serial->peek();
}

void HM12::flush()
{
	_serial->flush();
}

void HM12::listen()
{
	if(!isHardwareSerial)
	{
		if(!swSerial->isListening())
			swSerial->listen();
	}
}

void HM12::sendCommand(const char * cmd, uint8_t type, const char * params)
{
	listen();
	_serial->print((const __FlashStringHelper*)HM12_AT);
	_serial->print((const __FlashStringHelper*)cmd);
	if (type == HM12_CMD_QUERY)
		_serial->print(F("?"));
	else if (type == HM12_CMD_SETUP)
	{
		_serial->print(params);		
	}
}

bool HM12::readForResponse(uint8_t * rsp)
{
	_buffer = "";
	if(!_serial->find(rsp)) 
	{
		//Serial.println("Wrong response");
		return false;
	}
	while(available()>0)
		_buffer += (char)read();
	//Serial.println(_buffer);
	return true;
}

