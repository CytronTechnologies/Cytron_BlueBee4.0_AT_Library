# Cytron_BlueBee4.0_AT_Library

This library provides users API to communicate with BlueBee 4.0 with Arduino.

List of APIs:

1. <strong>HM12(uint8_t rx_pin, uint8_t tx_pin) </strong></br>Users can set appropriate RX and TX pins from Arduino to start UART communication with BlueBee 4.0.

  E.g.<strong> HM12 BlueBee(2,3) </strong>
  - pin 2 from Arduino act as RX connecting to TX of BlueBee 4.0
  - pin 3 from Arduino act as TX connecting to RX of BlueBee 4.0
  
2. <strong>bool begin(unsigned long baudrate)</strong></br>Initialize the UART communication at specified baudrate. Default baudrate for BlueBee 4.0 is 115200. Returns true if successful.

  E.g.<strong> BlueBee.begin(115200) </strong>
  
3. <strong>void end()</strong></br>End the UART communication between Arduino and BlueBee 4.0.

  E.g.<strong> BlueBee.end() </strong>
  
4. <strong>bool setBaud(unsigned long baudrate)</strong></br>Set the UART baudrate of BlueBee 4.0. Returns true if successful.

  E.g.<strong> BlueBee.setBaud(9600) </strong>

5. <strong>bool test()</strong></br>Test the communication with BlueBee 4.0. Returns true if successful.

  E.g.<strong> BlueBee.test() </strong>

6. <strong>bool reset()</strong></br>Reset BlueBee 4.0. Returns true if successful.

  E.g.<strong> BlueBee.reset() </strong>
