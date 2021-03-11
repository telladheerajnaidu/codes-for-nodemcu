#include <Blynk.h>



#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHTesp.h>

#include "DHT.h"        // including the library of DHT11 temperature and humidity sensor
#define DHTTYPE DHT11      // DHT 11

#define dht_dpin 14
DHT dht(dht_dpin, DHTTYPE); 
SimpleTimer timer;
char auth[] = "gMP2gy_u0dcWbNEYQb54dJ4jyVe2-2zR";            // You should get Auth Token in the Blynk App.
char ssid[] = "POCO dj";    // Your WiFi credentials.
char pass[] = "dheer123";  // Set password to "" for open networks.
float h;                                   // Declare the variables 
float t;
void setup()
{
    Serial.begin(9600);// Debug console
    Blynk.begin(auth, ssid, pass);
    dht.begin();
    timer.setInterval(2000, sendUptime);
}

void sendUptime()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();          
    Serial.print("Current humidity = ");
    Serial.print(h);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(t); 
    Serial.println("C  ");
  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);
  
}

void loop()
{
  Blynk.run();
  timer.run();
}
