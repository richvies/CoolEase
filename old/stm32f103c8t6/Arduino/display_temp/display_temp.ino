#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ClosedCube_Si7051.h>

ClosedCube_Si7051 si7051;

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET     4
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {

  si7051.begin(0x40);

  
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
  display.setTextColor(WHITE);
  display.setTextSize(3);
}

void loop() {
  
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print(si7051.readTemperature());
  display.display();

  delay(1000);

}
