#include <PMW3360.h>
#include <elapsedMillis.h>


#define SS  10   // Slave Select pin. Connect this to SS on the module.
elapsedMillis timer;

boolean surface_quality = 0;

#define Motion  0x02
#define Delta_X_L 0x03
#define Delta_X_H 0x04
#define Delta_Y_L 0x05
#define Delta_Y_H 0x06
#define SQUAL 0x07

PMW3360 sensor;

int sumx = 0;
int sumy = 0;
int squal;

void setup() {
  Serial.begin(9600);  
  while(!Serial);
  
  //sensor.begin(10, 1600); // to set CPI (Count per Inch), pass it as the second parameter
  if(sensor.begin(SS))  // 10 is the pin connected to SS of the module.
    Serial.println("Sensor initialization successed");
  else
    Serial.println("Sensor initialization failed");
  
  //sensor.setCPI(1600);    // or, you can set CPI later by calling setCPI();
}

void loop() 
{

  PMW3360_DATA data = sensor.readBurst();

  int xh = sensor.readReg(Delta_X_H);
  int xl = sensor.readReg(Delta_X_L);
  int xh_2 = xh<<8;
  int x = convTwosComp(xh|xl);
  
  sumx += x;

  int yh = sensor.readReg(Delta_Y_H);
  int yl = sensor.readReg(Delta_Y_L);
  int yh_2 = yh<<8;
  int y = convTwosComp(yh|yl);
  sumy += y;
  
  squal = convTwosComp(sensor.readReg(SQUAL));

  //  sumx += convTwosComp(sensor.readReg(Delta_X_L));
  
  if (timer > 20)
  {
  
    if (surface_quality == 1)
    {
      Serial.println(squal);
      timer = 0;
    }
    else
    {
      Serial.print(sumx);
      Serial.print("\t");
      Serial.println(sumy);
      timer = 0;
    }
  }
  
  //Serial.println(convTwosComp(sensor.readReg(0x03)));
//  if(data.isOnSurface && data.isMotion)
//  {
//    Serial.print(data.dx);
//    Serial.print("\t");
//    Serial.print(data.dy);
//    Serial.println();
//  }
  
  //delay(10);
}

int convTwosComp(int b)
{
  //Convert from 2's complement
  if(b & 0x80)
  {
    b = -1 * ((b ^ 0xff) + 1);
  }
  return b;
}  
