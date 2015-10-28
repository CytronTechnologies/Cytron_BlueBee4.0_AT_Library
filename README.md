# Cytron_BlueBee4.0_AT_Library

This library provides users API to communicate with BlueBee 4.0 with Arduino.

List of APIs:

1. <strong>HM12(uint8_t rx_pin, uint8_t tx_pin) </strong></br>Users can set appropriate RX and TX pins from Arduino to start UART communication with BlueBee 4.0.

  E.g.<strong> HM12 BlueBee(2,3) </strong>
  - pin 2 from Arduino act as RX connecting to TX of BlueBee 4.0
  - pin 3 from Arduino act as TX connecting to RX of BlueBee 4.0
  
2. bool <strong>begin(unsigned long baudrate)</strong></br>Initialize the UART communication at specified baudrate. Default baudrate for BlueBee 4.0 is 115200. Returns true if successful.

  E.g.<strong> BlueBee.begin(115200) </strong>
  
3. void <strong>end()</strong></br>End the UART communication between Arduino and BlueBee 4.0.

  E.g.<strong> BlueBee.end() </strong>
  
4. bool <strong>setBaud(unsigned long baudrate)</strong></br>Set the UART baudrate of BlueBee 4.0. Returns true if successful.

  E.g.<strong> BlueBee.setBaud(9600) </strong>

5. bool <strong>test()</strong></br>Test the communication with BlueBee 4.0. Returns true if successful.

  E.g.<strong> BlueBee.test() </strong>

6. bool <strong>reset()</strong></br>Reset BlueBee 4.0. Returns true if successful.

  E.g.<strong> BlueBee.reset() </strong>

7. bool <strong>digitalWrite(uint8_t pin, uint8_t state)</strong></br> set output of BlueBee 4.0 I/O. Returns true if successful.

  E.g.<strong> BlueBee.digitalWrite(2, HIGH) </strong>
  
8. uint8_t <strong>digitalRead(uint8_t pin, uint8_t state)</strong></br> Returns BlueBee 4.0 I/O status, HIGH or LOW.

  E.g.<strong> BlueBee.digitalRead(2) </strong>
  
9. String <strong>firmwareVersion()</strong></br> Returns BlueBee 4.0 firmware version in string form.

10.bool <strong>setBLEName(String name)</strong></br> Set BLE name for BlueBee 4.0. Returns true if successful.

  E.g.<strong> BlueBee.digitalRead(2) </strong>

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
	int getRSSI();
	bool searchForNewDevice();
