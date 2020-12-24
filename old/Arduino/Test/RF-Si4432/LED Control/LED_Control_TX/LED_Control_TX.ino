#include "si4432.h"

Si4432 radio(7, 6, 10);

#define LED 9
#define POT A0

void setup() 
{
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  pinMode(POT, INPUT);
  
  Serial.begin(9600);
  delay(300);

  radio.init();
  radio.setBaudRate(70);
  radio.setFrequency(433);

  Serial.println("TX Radio Params");
  radio.readAll();
  Serial.println("Setup Success\n");
}

void loop() 
{
  byte pot_value_send = (analogRead(POT) >> 2);
  radio.sendPacket(1, &pot_value_send);
  delay(1);
}
