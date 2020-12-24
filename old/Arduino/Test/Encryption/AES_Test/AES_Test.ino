#include <AESLib.h>

void setup() {
  
  uint8_t key[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  char data[] = "caaaaaaaaaaaaaab"; //16 chars == 16 bytes
  
  aes128_enc_single(key, data);
  Serial.print("encrypted: ");
  for(int i = 0; i < 16; i++)
  {
    Serial.print(data[i], DEC); Serial.print(" ");
  }
  
  aes128_dec_single(key, data);
  Serial.print("\ndecrypted:");
  Serial.println(data);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
