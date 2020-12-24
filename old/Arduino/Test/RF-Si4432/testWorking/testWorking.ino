#include "si4432.h"

Si4432 radio(7, 0, 10);

void setup() 
{ 
  Serial.begin(115200);
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
}
