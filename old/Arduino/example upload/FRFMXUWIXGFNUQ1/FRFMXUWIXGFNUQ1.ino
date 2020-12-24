#include <LTask.h>
#include <LWiFi.h>
#include <LWiFiClient.h>

#define WIFI_AP "Your wifi user name"
#define WIFI_PASSWORD "Your wifi password"
#define WIFI_AUTH LWIFI_WPA
#define SITE_URL2 "/Switch status link page.php?id=User name in table&pwd=Encrypted passwoed using MD5 HTTP/1.1"
#define SITE_URL3 "/Sensor link page.php?id=User name in table&pwd=Encrypted passwoed using MD5"
#define SITE_URL "Your web domanin name"

String Sensorpost = "";
String recstring = "";

int InPin0 = A0;
int InPin1 = A1;
int InPin2 = A2;
int Sen1=0;
int Sen2=0;
int Sen3=0;

LWiFiClient c;

void setup()
{
  LWiFi.begin();
  Serial.begin(115200);

  Serial.println("Connecting to AP");
  while (0 == LWiFi.connect(WIFI_AP, LWiFiLoginInfo(WIFI_AUTH, WIFI_PASSWORD)))
  {
    delay(1000);
  }

  // keep retrying until connected to website
  Serial.println("Connecting to WebSite");
  while (0 == c.connect(SITE_URL, 80))
  {
    Serial.println("Re-Connecting to WebSite");
    delay(1000);
  }

}

boolean disconnectedMsg = false;

void loop()
{
  // Retrive the output status in decimal want to convet it to binary and change the respective pin status
   if (c.connect(SITE_URL,80)) { 
     c.println("GET  " SITE_URL2);
     c.println("Host: " SITE_URL);     
     c.println("Connection: close");
     c.println();     
      while (!c.available())
     {
      delay(100);
     }
     recstring="";
  while (c)
  {
    int v = c.read();
    if (v != -1)
    {
      recstring = recstring+(char)v;
      //Serial.print((char)v);
    }
    else
    {
      //Serial.println("no more content, disconnect");
      c.stop();
      while (1)
      {
        delay(1);
      }
    }  
 } 
     Serial.print(recstring);
     if (recstring != "")
     {
       int firstletter = recstring.indexOf('Sensor-');
       int secondletter = recstring.indexOf(firstletter,'Value');
       String Result=recstring.substring(firstletter, secondletter);
     }
     dectobin();
}
delay(1000);
   Sen1 = analogRead(InPin0);
   Sen2 = analogRead(InPin1);
   Sen3 = analogRead(InPin2);   
   if (c.connect(SITE_URL,80)) {  
     Sensorpost=SITE_URL3;
     Sensorpost=Sensorpost + "&s1=";
     Sensorpost=Sensorpost + Sen1;
     Sensorpost=Sensorpost + "&s2=";
     Sensorpost=Sensorpost + Sen2;     
     Sensorpost=Sensorpost + "&s3=";
     Sensorpost=Sensorpost + Sen3;  
     Sensorpost=Sensorpost + " HTTP/1.1";
     c.println("GET  " + Sensorpost);
     c.println("Host: " SITE_URL);     
     c.println("Connection: close");
     c.println();     
      while (!c.available())
     {
      delay(100);
     }
   }
    delay(5000);
}


void dectobin()
{
}
