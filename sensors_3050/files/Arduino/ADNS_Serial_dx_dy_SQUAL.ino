#include "ADNS3050.h"
#include <SPI.h>

byte x = 0;
byte y = 0;
int sumx =0;
int sumy = 0;
int squal = 0;

byte x2 = 0;
byte y2 = 0;
byte x22 = 0;
byte y22 = 0;
int sumx2 =0;
int sumy2 = 0;
int squal2 = 0;

void setup()
{
  startup();
  startup2();
}

void loop() 
{


// //Serial.println(Read(NAV_CTRL2),BIN);
//  Serial.println(Read(AUTO_LED_CONTROL),BIN);
//  delay(100);
//  Serial.println(Read(LED_CTRL),BIN);
//  delay(100);
  
///*
// Read data from the first sensor
Write(NAV_CTRL2, 0x80); // Register to change the awake mode 0 enabled / 1 disabled on the bit 7 (1000000)
//delay(1);

x= Read(0x03);
y = Read(0x04);
squal = Read(0x05);

int x1= convTwosComp(x);
int y1 = convTwosComp(y);

int Squal = convTwosComp(squal);
sumx = sumx + x1;
sumy = sumy + y1;


// Read data from the second sensor
x2= Read2(0x03);
y2 = Read2(0x04);
squal2 = Read2(0x05);

int x22= convTwosComp(x2);
int y22 = convTwosComp(y2);

int Squal2 = convTwosComp(squal);
sumx2 = sumx2 + x22;
sumy2 = sumy2 + y22;

Serial.print("x1 ");
Serial.print(sumx);
Serial.print(convTwosComp(x));
Serial.print(" ");
Serial.print("y1 ");
Serial.print(sumy);
Serial.print(" ");
Serial.print("SQUAL1 ");
Serial.print(Squal);
//Serial.println(convTwosComp(y));
Serial.print("x1 ");
Serial.print(sumx2);
Serial.print(convTwosComp(x));
Serial.print(" ");
Serial.print("y1 ");
Serial.print(sumy2);
Serial.print(" ");
Serial.print("SQUAL1 ");
Serial.println(Squal2);
//*/
}
