#include<ESP8266WiFi.h>
#include "ThingSpeak.h"
float stat;
WiFiClient Client;
void setup() 
{
pinMode(13,INPUT);
ThingSpeak.begin(Client);
WiFi.mode(WIFI_STA);  //to make a station
WiFi.begin("AmalHome","amal1234");
Serial.begin(9600);
while(WiFi.status()!=WL_CONNECTED)  {
Serial.println("Connecting......");
delay(1000); }
Serial.println( WiFi.localIP() );
pinMode(A0,INPUT);
Serial.begin(9600);
}

void loop() {  
stat=analogRead(A0);
Serial.println(stat);
if(digitalRead(13)==HIGH)
        ThingSpeak.writeField(290798,2,1,"OHDQXX2Y6AV5EUT7");
else 
        ThingSpeak.writeField(290798,2,0,"OHDQXX2Y6AV5EUT7");
}
