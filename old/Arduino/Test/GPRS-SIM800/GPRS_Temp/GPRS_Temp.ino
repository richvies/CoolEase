#include <SIM800.h>
#include <Wire.h>
#include <ClosedCube_Si7051.h>

ClosedCube_Si7051 si7051;

unsigned long bauds = 19200;
int count = 0;

void setup() {

  Serial.begin(bauds);

  SIM.begin(bauds);
  delay(100);
  SIM.setTimeout(5000);
  SIM.cmdBenchmark(false);
  SIM.test();

  si7051.begin(0x40);

}

void loop() {
  Serial.print("Transmit "); Serial.println(count); count++;
  int temp = si7051.readTemperature() * 1000;
  Serial.println(temp);
  upload(temp);
  delay(2000);
}


void upload(int temp)
{
  String URL_String = "\"URL\",\"www.circuitboardsamurai.com/upload.php?temperature=";
  URL_String.concat(temp); URL_String.concat("\"h");
  Serial.println(URL_String); Serial.println();
  char URL_Char[URL_String.length()];
  URL_String.toCharArray(URL_Char,URL_String.length());

  SIM.ipBearer(SET, "3,1,\"Contype\",\"GPRS\"");    // Configure profile 1 connection as "GPRS"
  SIM.ipBearer(SET, "3,1,\"APN\",\"data.rewicom.net\"");    // Set profile 1 access point name to "internet"
  SIM.ipBearer(SET, "1,1");                         // Open GPRS connection on profile 1
  SIM.ipBearer(SET, "2,1");                         // Display IP address of profile 1
  SIM.httpInit(EXE);                                // Initialize HTTP functionality
  SIM.httpParams(SET, "\"CID\",1");                 // Choose profile 1 as HTTP channel
  SIM.httpParams(SET, URL_Char);                    // Set URL
  SIM.httpParams(GET);                              // View HTTP Parameters
  SIM.httpAction(SET, "0");                         // Get the webpage
  while (!SIM.available()) {
    ; // Wait until the webpage has arrived
  }
  //SIM.httpRead(EXE);                                // Send the received webpage to Arduino
  SIM.httpEnd(EXE);                                 // Terminate HTTP functionality
  SIM.ipBearer(SET, "0,1");                         // Close GPRS connection on profile 1
}
