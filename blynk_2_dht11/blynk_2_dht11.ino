#define BLYNK_PRINT Serial


#include <SPI.h>
#include <Ethernet.h>
#include <BlynkSimpleEthernet.h>
#include <DHT.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "gMP2gy_u0dcWbNEYQb54dJ4jyVe2-2zR";

#define DHTPIN 2          // What digital pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11     // DHT 11
//#define DHTTYPE DHT22   // DHT 22, AM2302, AM2321
//#define DHTTYPE DHT21   // DHT 21, AM2301

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;
char auth[] = "gMP2gy_u0dcWbNEYQb54dJ4jyVe2-2zR";            // You should get Auth Token in the Blynk App.
                                           // Go to the Project Settings (nut icon).

char ssid[] = "POCO dj";    // Your WiFi credentials.
char pass[] = "dheer123";  // Set password to "" for open networks.
float t;                                   // Declare the variables 
float h;



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
  Serial.println("Humidity and temperature\n\n");
  Serial.print("Current humidity = ");
  Serial.print(h);
  Serial.print("%  ");
  Serial.print("temperature = ");
  Serial.print(t); 
  Blynk.virtualWrite(V6, t);
  Blynk.virtualWrite(V7, h);
  
}

void loop()
{
  Blynk.run();
  timer.run();
}
