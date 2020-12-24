#include "si4432.h"

Si4432 radio_TX(7, 6, 10);
Si4432 radio_RX(3, 2, 4);

#define LED 5
#define POT A0

void setup() 
{
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  pinMode(POT, INPUT);
  
  Serial.begin(115200);
  delay(300);

//-------------------------------------------------// 
//-------------------------------------------------// 

  radio_TX.init();
  radio_TX.setBaudRate(70);
  radio_TX.setFrequency(433);

  Serial.println("TX Radio Params");
  radio_TX.readAll();
  Serial.println("******************************\n\n");
  
//-------------------------------------------------// 
//-------------------------------------------------// 
  
  radio_RX.init();
  //radio_RX.setBaudRate(70);
  //radio_RX.setFrequency(433);

  //Serial.println("RX Radio Params");
  radio_RX.readAll();
  //Serial.println("******************************\n\n");  
  //radio_RX.startListening();

  Serial.println("Setup Success");
}

void loop() 
{
  /*byte pot_value_send = (analogRead(POT) >> 2);
  radio_TX.sendPacket(1, &pot_value_send);
  delay(1);

//-------------------------------------------------// 
//-------------------------------------------------// 

  bool pkg = radio_RX.isPacketReceived();
  if (pkg)
  {
    byte pot_value_receive = 0;
    byte len = 0;
    radio_RX.getPacketReceived(&len, &pot_value_receive);
    radio_RX.startListening(); // restart the listening.
    analogWrite(LED, pot_value_receive);
  }
  else
  {
  }*/
}
