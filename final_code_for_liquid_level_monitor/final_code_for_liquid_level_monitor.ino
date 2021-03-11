#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define TRIGGER    D1
#define ECHO       D2
#define led1       D6
#define led2       D7
#define led3       D8
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = " gMP2gy_u0dcWbNEYQb54dJ4jyVe2-2zR";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "POCO dj";
char pass[] = "dheer123";

WidgetLCD lcd(V1);

void setup()
{
  // Debug console

  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(TRIGGER,OUTPUT);
  pinMode(ECHO,INPUT);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);

  lcd.clear(); //Use it to clear the LCD Widget
  lcd.print(0, 0, "Distance in cm"); // use: (position X: 0-15, position Y: 0-1, "Message you want to print")
  // Please use timed events when LCD printintg in void loop to avoid sending too many commands
  // It will cause a FLOOD Error, and connection will be dropped
  
}

void loop()
{
  lcd.clear();
  lcd.print(0, 0, "Distance in cm"); // use: (position X: 0-15, position Y: 0-1, "Message you want to print")
  long duration, distance;
  digitalWrite(TRIGGER, LOW);  
  delayMicroseconds(2); 
  
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10); 
  
  digitalWrite(TRIGGER, LOW);
  duration = pulseIn(ECHO, HIGH);
  distance = (duration/2) / 29.1;
  
  Serial.print(distance);
  Serial.println("Centimeter:");
  lcd.print(7, 1, distance);
  delay(1000);
 
  if (distance>=12)
  {
    Serial.println("water level is low");
    Serial.print("distance=");
    Serial.println(distance);
   
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    Blynk.email("dheerajtej987@gmail.com", "ESP8266 Alert", "water level is low");
    Blynk.notify("ESP8266 Alert = water level is low");
    
  }
  else if(distance<=12&&distance>=8)
  {
    Serial.println("water level is medium");
    Serial.print("distance=");
    Serial.println(distance);
    digitalWrite(led2,HIGH);
    digitalWrite(led1,LOW);
    digitalWrite(led3,LOW);
    
  }
    
 else if(distance<=2)
 {
  Serial.println("water level is high");
    Serial.print("distance=");
    Serial.println(distance);
    digitalWrite(led3,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led1,LOW);
Blynk.email("dheerajtej987@gmail.com", "ESP8266 Alert", "over flow");
    Blynk.notify("ESP8266 Alert = overflow");
    
  }
 
else
{
  Serial.println("not specified");
}
  Blynk.run();
  delay(3500);

}
