#include "si4432.h"

Si4432 radio(7, 6, 10);

#define LED 9

void setup() 
{
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

  radio.init();
  radio.setBaudRate(70);
  radio.setFrequency(433);
  radio.startListening();
}

void loop() 
{
  bool pkg = radio.isPacketReceived();
  if (pkg)
  {
    byte pot_value_receive = 0;
    byte len = 0;
    radio.getPacketReceived(&len, &pot_value_receive);
    radio.startListening(); // restart the listening.
    analogWrite(LED, pot_value_receive);
  }
  else
  {
  }
}
