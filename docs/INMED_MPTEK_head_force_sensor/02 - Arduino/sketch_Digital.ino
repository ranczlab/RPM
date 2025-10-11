#include <SPI.h>

//Arduino Zero SPI pinout:
//SPI data lines available only on the ICSP connector
//slaveSelect is managed manually
//See https://content.arduino.cc/assets/Pinout-ZERO_latest.pdf 
//
//ICSP 1: CIPO/MISO
//ICSP 3: SCK
//ICSP 4: COPI/MOSI
//D0: SS/slaveSelect

//Set SS pin as D0
const uint8_t slaveSelect = 0;  //Can be relocated

void setup() {
  //Serial.begin(115200);
  SerialUSB.begin(115200);  //Using native USB port

  //wait for serial port to connect. Needed for native USB port only
  //while (!Serial) {
  while (!SerialUSB) {  //Using native USB port
  delay(10);
}

//Welcome message
//Serial.println("Digital sensor Test");
SerialUSB.println("Digital sensor Test");  //Using native USB port

//Set SS as output 
pinMode(slaveSelect, OUTPUT);

//Set SS high (disable)
digitalWrite(slaveSelect, HIGH);

//Initializes the SPI bus by setting SCK, MOSI to outputs, MISO to input pulling SCK and MOSI low.
SPI.begin();

//Delay
delay(100);
}

void loop() {
  //Variables
  uint16_t rawTemperature = 0;
  uint16_t rawForce = 0;
  uint8_t status = 0;  
  double calibratedTemperature = 0.0;
  double calibratedForce = 0.0;

  //Begin transaction
  //Initializes the SPI bus with:
  //500KHz clk freq (max 800KHz)
  //LSB is issued first as per datasheet but seems like Arduino reversed LSBFIRST and MSBFIRST ...
  //SPI Mode 0
  SPI.beginTransaction(SPISettings(500000, MSBFIRST, SPI_MODE0));

  //Read the raw data
  bool success = ReadSensorData(&rawTemperature, &rawForce, &status);

  //Calibrate the data
  calibratedTemperature = calibrateTemperature(rawTemperature);
  calibratedForce = calibrateForce(rawForce);

  //Display the data
  SerialUSB.print("status (0: Normal operation, valid data): ");
  SerialUSB.println(status);
  SerialUSB.print("Raw Force (digital count): ");
  SerialUSB.println(rawForce);
  SerialUSB.print("Calibrated Force (N): ");
  SerialUSB.println(calibratedForce);
  SerialUSB.print("Raw Temperature (digital count): ");
  SerialUSB.println(rawTemperature);
  SerialUSB.print("Calibrated Temperature (°C): ");
  SerialUSB.println(calibratedTemperature);
  SerialUSB.println();

  //End SPI transaction
  SPI.endTransaction();

  //Delay for readability
  delay(500);

  //Disable SPI
  //SPI.end();
}

bool ReadSensorData(uint16_t *rawTemperature, uint16_t *rawForce, uint8_t *status)
{
  uint8_t byte1 = 0;
  uint8_t byte2 = 0;
  uint8_t byte3 = 0;
  uint8_t byte4 = 0;

  //Set SS low to enable the sensor
  digitalWrite(slaveSelect, LOW);

  //Fetch 4 bytes of data from the sensor
  byte1 = SPI.transfer(0x00);
  byte2 = SPI.transfer(0x00);
  byte3 = SPI.transfer(0x00);
  byte4 = SPI.transfer(0x00);

  //Set SS high to disable the sensor
  digitalWrite(slaveSelect, HIGH);
  
  //Format the raw data
  *status = (byte1 & 0b11000000) >> 6;
  *rawForce = (byte1 & 0b00111111) << 8;
  *rawForce = *rawForce | byte2;
  *rawTemperature = byte3 << 3;
  *rawTemperature = *rawTemperature | (byte4 >> 5);

  return(true);
}

double calibrateForce(uint16_t rawForce)
{  
  double calibratedForce = 0.0;
  double rawF = (double)rawForce;

  //Formula from sensor datasheet
  calibratedForce = ((rawF - 3277.0) / (13107.0 - 3277.0)) * 5.0;

  return(calibratedForce);
}

double calibrateTemperature(uint16_t rawTemperature)
{
  double calibratedTemperature = 0.0;
  double rawT = (double)rawTemperature;

  //Formula from sensor datasheet
  calibratedTemperature = ((rawT / 2047.0) * 200.0) - 50.0;

  return(calibratedTemperature);
}