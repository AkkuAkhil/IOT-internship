#include<ESP8266WiFi.h>
#include "ThingSpeak.h"
float stat;
WiFiClient Client;
void setup() 
{
ThingSpeak.begin(Client);
WiFi.mode(WIFI_STA);  //to make a station
WiFi.begin("JioFi3_2863C8","ypp24wca36");
Serial.begin(9600);
while(WiFi.status()!=WL_CONNECTED)  {
Serial.println("Connecting......");
delay(1000); }
Serial.println( WiFi.localIP() );
pinMode(A0,INPUT);
Serial.begin(9600);
}

void loop() {  
//stat=analogRead(A0);
//Serial.println(stat);
stat=ThingSpeak.readFloatField(289599,1,"NVKAR5GYC89FG3K8");
Serial.println(stat);



}
