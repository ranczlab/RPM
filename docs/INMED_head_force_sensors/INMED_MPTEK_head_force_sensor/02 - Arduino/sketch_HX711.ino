#include "Adafruit_HX711.h"

// Define the pins for the HX711 communication
const uint8_t DATA_PIN_1 = 2;  // Can use any pins!
const uint8_t CLOCK_PIN_1 = 3; // Can use any pins!
const uint8_t DATA_PIN_2 = 4;  // Can use any pins!
const uint8_t CLOCK_PIN_2 = 5; // Can use any pins!

Adafruit_HX711 hx711_1(DATA_PIN_1, CLOCK_PIN_1);
Adafruit_HX711 hx711_2(DATA_PIN_2, CLOCK_PIN_2);

void setup() {
  Serial.begin(115200);

  // wait for serial port to connect. Needed for native USB port only
  while (!Serial) {
    delay(10);
  }

  Serial.println("HX711 Test");

  // Initialize the HX711
  hx711_1.begin();
  hx711_2.begin();

  // read and toss 3 values each
  Serial.println("Tareing....");
  for (uint8_t t=0; t<3; t++) {
    hx711_1.tareA(hx711_1.readChannelRaw(CHAN_A_GAIN_128));
    hx711_1.tareA(hx711_1.readChannelRaw(CHAN_A_GAIN_128));
    hx711_1.tareB(hx711_1.readChannelRaw(CHAN_B_GAIN_32));
    hx711_1.tareB(hx711_1.readChannelRaw(CHAN_B_GAIN_32));
    hx711_2.tareA(hx711_2.readChannelRaw(CHAN_A_GAIN_128));
    hx711_2.tareA(hx711_2.readChannelRaw(CHAN_A_GAIN_128));
    hx711_2.tareB(hx711_2.readChannelRaw(CHAN_B_GAIN_32));
    hx711_2.tareB(hx711_2.readChannelRaw(CHAN_B_GAIN_32));
  }
} 

void loop() {
  // Read from Channel A with Gain 128, can also try CHAN_A_GAIN_64 or CHAN_B_GAIN_32
  // since the read is blocking this will not be more than 10 or 80 SPS (L or H switch)
  int32_t weightA128_1 = hx711_1.readChannelBlocking(CHAN_A_GAIN_128);
  Serial.print("Circuit 1 Channel A (Gain 128): ");
  Serial.println(weightA128_1);
  
  int32_t weightA128_2 = hx711_2.readChannelBlocking(CHAN_A_GAIN_128);
  Serial.print("Circuit 2 Channel A (Gain 128): ");
  Serial.println(weightA128_2);

  // Read from Channel B with Gain 32
  int32_t weightB32_1 = hx711_1.readChannelBlocking(CHAN_B_GAIN_32);
  Serial.print("Circuit 1 Channel B (Gain 32): ");
  Serial.println(weightB32_1);
  
  int32_t weightB32_2 = hx711_2.readChannelBlocking(CHAN_B_GAIN_32);
  Serial.print("Circuit 2 Channel B (Gain 32): ");
  Serial.println(weightB32_2);
}
