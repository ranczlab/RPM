#include <Wire.h>
#include <ADNS2610.h>
#include <CapacitiveSensor.h>

//Optical sensor pins
#define SCLK1 4                            // Serial clock pin on the Arduino
#define SDIO1 6                            // Serial data (I/O) pin on the 
#define SCLK2 8                            
#define SDIO2 10

// Instances of ADNS2610 object
ADNS2610 Optical1 = ADNS2610(SCLK1, SDIO1);
ADNS2610 Optical2 = ADNS2610(SCLK2, SDIO2);

// variables for the MCP4725 modules
#define DAC2 0x60
#define DAC3 0x61
#define DAC4 0x62
byte buffer [3];
int DAC_out_2 = 0;
int DAC_out_3 = 0;
int DAC_out_4 = 0;

// Variables Arduino internal DAC
int DAC_out_0 = 0;
int DAC_out_1 = 0;

//Valve constants and varibles
const byte VALVE = 11; // valve pin

unsigned long buttonPushedMillis; // when button was released
unsigned long valveTurnedOnAt; // when valve was turned on
unsigned long turnOnDelay = 0; // wait to turn on valve
unsigned long turnOffDelay = 140; // turn off valve after this time
bool valveReady = false; // flag for when button is let go
bool valveState = false; // for valve is on or not.

// Kinematic variables
signed long  X1 = 0;  
signed long  Y1 = 0;                     
signed long  X2 = 0;  
signed long  Y2 = 0;                   

float a = 0;
float Y11 = 0;
float X11 = 0;
float X22 = 0;
float Y22 = 0;
float x = 0;
float y = 0;
float DX = 0;
float DY = 0;

// Cosntants and conversion factors
const float pi = 3.14159265;
const float radius = 9.85;
float conversion_factor = 120; //120 mouse units/1cm
float rad_to_deg = 180/pi;
float cm_to_deg = 360/(2*pi*radius);

float angle = 0;
float DA = 0;

// Squal variables
int squal;
int squal2;

// Encoder variables

#define  A_PHASE 3 // green cable
#define  B_PHASE 5 // white cable

int flag_A = 0;  //Assign a value to the token bit
float encoder_angle = 0;
float r_1 = 138.4;//149.7;
float r_2 = 27/2;
float r_ratio = r_1/r_2;
float encoder_resol = 600;
float system_resol = encoder_resol*r_ratio;
float deg_pulse = 1/(system_resol/360);

// Serial 1 variables
byte serial1Read = 0;
int serialUSBRead = 0;

// lick sensor variables
CapacitiveSensor licksensor = CapacitiveSensor(12, 13);




void setup() 
{
  // Initialize serial communication with computer:
  Serial.begin(115200);
  Serial1.begin(115200);
  SerialUSB.begin(115200);
  
  // Initialize I2C communication with the devices (SDA SCL)
  Wire.begin();

  // Set the resolution to 12 bits
  analogWriteResolution(12);

  //Optical motion sensors setup
  Optical1.begin();
  Optical2.begin();

  // Valve setup
  pinMode(VALVE, OUTPUT);
  digitalWrite(VALVE, LOW);

  // External encoder setup
  pinMode(A_PHASE, INPUT_PULLUP);
  pinMode(B_PHASE, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt( A_PHASE), interrupt, RISING); //Interrupt trigger mode: RISING
  
}

void loop() 
{

///////////// VALVE CONTROL READING FROM THE NATIVE PORT ///////////////////
 
 if (SerialUSB.available() > 0) 
  {
    // read the incoming string and convert to int
    //from serial1 (RX1 TX1)
    //serial1Read = Serial1.read();
    // From Native DUE port
    serialUSBRead  = SerialUSB.parseInt();
    
     unsigned long currentMillis = millis(); 
      // check the button
     if (serialUSBRead  == 1) 
     {
      // update the time when button was pushed
      buttonPushedMillis = currentMillis;
      valveReady = true;
     }
      
     // make sure this code isn't checked until after button has been let go
     if (valveReady) 
     {
       //this is typical millis code here:
       if ((unsigned long)(currentMillis - buttonPushedMillis) >= turnOnDelay) 
       {
         // okay, enough time has passed since the button was let go.
         digitalWrite(VALVE, HIGH);
         // setup our next "state"
         valveState = true;
         // save when the valve turned on
         valveTurnedOnAt = currentMillis;
         // wait for next button press
         valveReady = false;
       }
     }
      
     // see if we are watching for the time to turn off valve
     if (valveState) 
     {
       // okay, led on, check for now long
       if ((unsigned long)(currentMillis - valveTurnedOnAt) >= turnOffDelay) 
       {
         valveState = false;
         digitalWrite(VALVE, LOW);
       }
     }
  }
//////////// OPTICAL SENSORS READING ///////////////

  //Reading the registers of the ADNS2010
  squal = Optical1.squal();
  squal2 = Optical2.squal();
  
  Y1 += Optical1.dx();
  Y11 = float(Y1*(1/conversion_factor));
  X1 += Optical1.dy();
  a = float(X1*(1/conversion_factor));

  Y2 += Optical2.dx();
  Y22 = float(Y2*(1/conversion_factor));
  X2 += Optical2.dy();
  X22 = float(X2*(1/conversion_factor));

  DX = Optical1.dx()*(1/conversion_factor);
  DY = Optical2.dx()*(1/conversion_factor);

  DA = cm_to_deg*(float(Optical1.dy()*(1/conversion_factor)));

  // x and y coordinates
  y = Y11;
  x = Y22;
  
  //Angle (yaw rotation) using conversion factors
  angle = a*cm_to_deg;

/////////ENCODER ANGLE/////////////////////////////////

  encoder_angle = flag_A*deg_pulse;

/////////MCP4725 DAC OUTPUT/////////////////////////////////
  
  DAC_out_2 = int(102.38*Optical1.dx() + 2047.5);
  DAC_out_3 = int(102.38*Optical2.dx() + 2047.5);
  
  sendI2C(DAC2,DAC_out_2);
  sendI2C(DAC3,DAC_out_3);

////// ARDUINO DAC OUTPUTS/////////////////////////////////
  
  DAC_out_0 = int(102.38*Optical1.dy() + 2047.5);
  DAC_out_1 = int(5.6875*encoder_angle + 2047.5);
  
  
  analogWrite(DAC0, DAC_out_0);
  analogWrite(DAC1, DAC_out_1);

////// Licking sensor Analog output /////////////////////
  
  long lickSensorValue = licksensor.capacitiveSensor(30);
  DAC_out_4 = lickSensorValue*4;
  sendI2C(DAC4,DAC_out_4);

//////****** SERIAL PRINT NATIVE PORT*****////////////////


//  SerialUSB.print("X: ");
//  SerialUSB.print(x);
//  SerialUSB.print(" ");
//  SerialUSB.print("Y: ");
//  SerialUSB.print(y);
//  SerialUSB.print(" ");
//  SerialUSB.print("ANGLE: "); 
//  SerialUSB.print(angle); 
//  SerialUSB.print(" ");
//  SerialUSB.print("Licksensor: "); 
//  SerialUSB.print(licksensor);
//  SerialUSB.print(" ");
//  SerialUSB.print("Encoder angle: "); 
//  SerialUSB.println(encoder_angle);

//Print register SQUAL to get a measurement of the surface quality (Best values of 120 on paper surface)

//  Serial.print("SQUAL1: "); 
//  Serial.print(squal);
//  Serial.print(" "); 
//  Serial.print("SQUAL2: "); 
//  Serial.print(squal2);
//  Serial.println();
  
}

void sendI2C(int busadress , unsigned int value)
{
   buffer[0] = 0b01000000; 
   buffer[1] = value >> 4;
   buffer[2] = value << 4;
   Wire.beginTransmission(busadress);
   Wire.write (buffer[0]);
   Wire.write (buffer[1]);
   Wire.write (buffer[2]);
   Wire.endTransmission();
}

void interrupt()// Interrupt function
{ char i;
  i = digitalRead( B_PHASE);
  if (i == 1)
    flag_A += 1;
  else
    flag_A -= 1; // Not shure if is correct!!
}
