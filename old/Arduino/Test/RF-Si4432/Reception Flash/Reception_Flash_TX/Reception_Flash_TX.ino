#include "si4432.h"

Si4432 radio(7, 6, 10);

const uint8_t send_length = 5;
byte send_data[send_length] = {'h', 'e', 'l', 'l', 'o'};

const uint8_t expected_response_length = 16;
byte expected_response[expected_response_length] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p'};

uint8_t received_data_length;
byte received_data[64];

#define LED 9

void setup()
{
  Serial.begin(9600);
  delay(300);

  radio.init();
  radio.setBaudRate(70);
  radio.setFrequency(433);
}

void loop()
{
  radio.sendPacket(send_length, send_data, true, 1000, &received_data_length, received_data);
  byte received_data_trimmed[received_data_length];
  strncpy(received_data_trimmed, received_data, received_data_length);

  Serial.print("Received Length: "); Serial.println(received_data_length);
  for (int i = 0; i < received_data_length; i++)
  {
    Serial.print(received_data_trimmed[i]);
  }
  Serial.println("***************\n");

  if (strcmp(received_data_trimmed, expected_response) == 0)
  {
    digitalWrite(LED, HIGH);
    delay(100);
    digitalWrite(LED, LOW);
  }

  delay(1000);
}
