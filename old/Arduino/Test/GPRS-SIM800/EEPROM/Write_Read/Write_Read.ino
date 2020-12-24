#include <EEPROM.h>

void setup() {

  Serial.begin(9600);
  writeLongEEPROM(0);

  /*for (int i = 0; i < 100; i++)
  {
    Serial.println(i);
    unsigned long value = readLongEEPROM();
    Serial.print("Start "); Serial.println(value);
    value += 1000000;
    writeLongEEPROM(value);
    Serial.print("End "); Serial.println(value);
    Serial.println();
  }*/
  printEEPROM();
}

void loop() {
}

void writeLongEEPROM(unsigned long value)
{
  for (int i = 0; i < 4; i++)
  {
    byte tmp = value >> (i * 8);
    EEPROM.write(i, tmp);
  }
}

unsigned long readLongEEPROM()
{
  unsigned long value = 0;
  for (int i = 0; i < 4; i++)
  {
    unsigned long tmp = EEPROM.read(i);
    value += tmp << (i * 8);
  }
  return value;
}

void printEEPROM()
{
  for (int i = 0; i < 4; i++)
  {
    Serial.print(EEPROM.read(i), HEX);
  }
  Serial.println();
}
