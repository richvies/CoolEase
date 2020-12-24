#include <SPI.h>

#include "si4432.h"

Si4432 radio(7, 6, 10);

const uint8_t data_to_receive_length = 5;
byte data_to_receive[data_to_receive_length] = {'h', 'e', 'l', 'l', 'o'};

const uint8_t data_to_reply_length = 16;
byte data_to_reply[data_to_reply_length] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p'};

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
    radio.sendPacket(data_to_reply_length, data_to_reply);

    byte data_received[64];
    uint8_t data_received_length = 0;
    radio.getPacketReceived(&data_received_length, data_received);
    byte data_received_trimmed[data_received_length];
    memcpy(data_received_trimmed, data_received, data_received_length);

    if (memcmp(data_received_trimmed, data_to_receive, data_to_receive_length) == 0)
    {
      digitalWrite(LED, HIGH);
      delay(100);
      digitalWrite(LED, LOW);
    }

    radio.startListening();
  }
}
