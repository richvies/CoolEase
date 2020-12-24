#include <SIM800.h>

unsigned long bauds = 19200;

void setup() {

  Serial.begin(bauds);
  while (!Serial) {}
  SIM.begin(bauds);
  delay(100);

  SIM.setTimeout(3000);
  SIM.cmdBenchmark(true);
  SIM.test();

}

void loop() {
  SIM.directSerialMonitor();
}
