void setup() {
  Serial3.begin(38400);
  Serial1.begin(38400);

  Serial.print("Ready");
}

void loop() {
  if (Serial3.available()) {      // If anything comes in Serial (USB),
    Serial1.write(Serial3.read());   // read it and send it out Serial1 (pins 0 & 1)
  }

  if (Serial1.available()) {     // If anything comes in Serial1 (pins 0 & 1)
    Serial3.write(Serial1.read());   // read it and send it out Serial (USB)
  }
}
