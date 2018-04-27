#include<ESP8266WiFi.h>
#include "ThingSpeak.h"
#define c1 14
#define c2 12
#define c3 13
float state1;
float state2;
float state3;
int val;
WiFiClient Client;
void setup() 
{
ThingSpeak.begin(Client);
WiFi.mode(WIFI_STA);  //to make a station
WiFi.begin("AmalHome","amal1234");
Serial.begin(9600);
while(WiFi.status()!=WL_CONNECTED)  {
Serial.println("Connecting......");
delay(1000); }
Serial.println( WiFi.localIP() );
pinMode(c1,OUTPUT); digitalWrite(c1,LOW);
pinMode(c2,OUTPUT); digitalWrite(c2,LOW);
pinMode(c3,OUTPUT); digitalWrite(c3,LOW);
pinMode(A0,INPUT);
Serial.begin(9600);
}

void loop() {   

state1=ThingSpeak.readFloatField(290798,2,"RQGYZN6LXFK155P2");
Serial.print("LIGHT 1 IS NOW [ 1:ON / 0:OFF ] : ");
Serial.print(state1);
Serial.println(" ");
if (state1==1) { digitalWrite(c1,HIGH); }
else if (state1==0) { digitalWrite(c1,LOW); }

state2=ThingSpeak.readFloatField(290798,3,"RQGYZN6LXFK155P2");
Serial.print("LIGHT 2 IS NOW [ 1:ON / 0:OFF ] : ");
Serial.print(state2);
Serial.println(" ");
if (state2==1) { digitalWrite(c2,HIGH); }
else if (state2==0) { digitalWrite(c2,LOW); }

state3=ThingSpeak.readFloatField(290798,4,"RQGYZN6LXFK155P2");
Serial.print("LIGHT 3 IS NOW [ 1:ON / 0:OFF ] : ");
Serial.print(state3);
Serial.println(" ");
if (state3==1) { digitalWrite(c3,HIGH); }
else if (state3==0) { digitalWrite(c3,LOW); }
}
