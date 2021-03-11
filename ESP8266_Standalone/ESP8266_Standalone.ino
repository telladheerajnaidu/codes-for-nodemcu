/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP8266 chip.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right ESP8266 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "fHDtrab2IpLzM1a2E9Chs0TNwUtPEC6M";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Redmi";
char pass[] = "987654321";

void setup()
{
  // Debug console
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(BUILTIN_LED,OUTPUT);
}

void loop()
{
  Blynk.run();
  digitalWrite(BUILTIN_LED,LOW);
  delay(1000);
  digitalWrite(BUILTIN_LED,HIGH);
  delay(1000);
}
