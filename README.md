# Cytron_BlueBee4.0_AT_Library

This library provides users API to communicate with BlueBee 4.0 with Arduino.

List of APIs:

1. <strong>HM12(uint8_t rx_pin, uint8_t tx_pin) </strong></br>Users can set appropriate RX and TX pins from Arduino to start UART communication with BlueBee 4.0.

  E.g.<strong> HM12 BlueBee(2,3); </strong>
  - pin 2 from Arduino act as RX connecting to TX of BlueBee 4.0
  - pin 3 from Arduino act as TX connecting to RX of BlueBee 4.0
  
2. bool <strong>begin(unsigned long baudrate)</strong></br>Initialize the UART communication at specified baudrate. Default baudrate for BlueBee 4.0 is 115200. Returns true if successful.

  E.g.<strong> BlueBee.begin(115200); </strong>
  
3. void <strong>end()</strong></br>End the UART communication between Arduino and BlueBee 4.0.

  E.g.<strong> BlueBee.end() ;</strong>
  
4. bool <strong>setBaud(unsigned long baudrate)</strong></br>Set the UART baudrate of BlueBee 4.0. Returns true if successful.

  E.g.<strong> BlueBee.setBaud(9600); </strong>

5. bool <strong>test()</strong></br>Test the communication with BlueBee 4.0. Returns true if successful.

  E.g.<strong> BlueBee.test(); </strong>

6. bool <strong>reset()</strong></br>Reset BlueBee 4.0. Returns true if successful.

  E.g.<strong> BlueBee.reset();</strong>

7. bool <strong>digitalWrite(uint8_t pin, uint8_t state)</strong></br> set output of BlueBee 4.0 I/O. Returns true if successful.

  E.g.<strong> BlueBee.digitalWrite(2, HIGH); </strong>
  
8. uint8_t <strong>digitalRead(uint8_t pin, uint8_t state)</strong></br> Returns BlueBee 4.0 I/O status, HIGH or LOW.

  E.g.<strong> BlueBee.digitalRead(2); </strong>
  
9. String <strong>firmwareVersion()</strong></br> Returns BlueBee 4.0 firmware version in string form.

10. bool <strong>setBLEName(String name)</strong></br> Set BLE name for BlueBee 4.0. Returns true if successful.

    E.g.<strong> BlueBee.setBLEName("Bluetooth"); </strong>

11. bool <strong>setEDRName(String name)</strong></br> Set EDR name for BlueBee 4.0. Returns true if successful.

    E.g.<strong> BlueBee.setEDRName("Bluetooth"); </strong>

12. String <strong>BLEName()</strong></br> Returns BlueBee 4.0 BLE name in string form.

13. String <strong>EDRName()</strong></br> Returns BlueBee 4.0 EDR name in string form.

14. String <strong>BLEMacAddress()</strong></br> Returns BlueBee 4.0 BLE mac address in string form.

15. String <strong>EDRMacAddress()</strong></br> Returns BlueBee 4.0 EDR mac address in string form.

16. bool <strong>setMode(uint8_t)</strong></br> Set mode for BlueBee 4.0. 0 - normal, 1 - remote. Returns true if successful.

    E.g.<strong> BlueBee.setMode(1); </strong> - set BlueBee 4.0 to remote mode.

17. uint8_t <strong>getMode()</strong></br> Get mode info from BlueBee 4.0. Returns 0 for normal mode and 1 for remote mode.

18. bool <strong>setRole(uint8_t)</strong></br> Set role for BlueBee 4.0 in BLE model. SLAVE or MASTER. Returns true if successful.

    E.g.<strong> BlueBee.setRole(MASTER); </strong> - set BlueBee 4.0 to master device.

19. uint8_t <strong>getRole()</strong></br> Get role info from BlueBee 4.0 in BLE mode. Returns 0 for SLAVE and 1 for MASTER.

20. bool <strong>setDualMode(bool)</strong></br> Set BlueBee 4.0 to dual mode. TRUE - dual mode, FALSE - single mode. Returns true if successful.

21. bool <strong>isDualMode()</strong></br> Check if BlueBee 4.0 is in dual mode. Returns TRUE if dual mode, FALSE if single mode.

22. int <strong>getRSSI()</strong></br> Get RSSI value of the connected device to BlueBee 4.0 (only works if BlueBee 4.0 is connected to other device).

23. bool <strong>searchForNewDevice()</strong></br> Search for new device to connect when BlueBee 4.0 is in master role. Returns true if successful.

24. void <strong>print(data)</strong></br> Send data to connected device. data can be integer, string, const char*, same as Serial library.

    E.g.<strong> BlueBee.print("Hello World"); </strong> - Send "Hello World" to connected device.
    
25. int <strong>available()</strong></br> Check if there is received data from connected device. Returns number of data bytes received.

26. int <strong>read()</strong></br> Read data from connected device.

    E.g.<strong> char c = BlueBee.read(); </strong>

# Additonal info:
In <strong>extras</strong> folder, </br>
- BTTool.apk - android phone apps for communicating with BlueBee  4.0
- bluetoothdual_en.pdf - User manual for the HM12 module, consists of full AT command list
