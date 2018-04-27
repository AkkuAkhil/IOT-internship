#include<ESP8266WiFi.h>
#include "ThingSpeak.h"
#define c1 5
#define c2 4
#define c3 2
#define ir1 13
#define ir2 12
#define ir3 14
float state1;
float state2;
float state3;
int brc=0,count=0,x=0,y=0,z=0,val;
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
pinMode(c1,OUTPUT); digitalWrite(c1,LOW);
pinMode(c2,OUTPUT); digitalWrite(c2,LOW);
pinMode(c3,OUTPUT); digitalWrite(c3,LOW);
pinMode(A0,INPUT);
pinMode(ir1,INPUT);
pinMode(ir2,INPUT);
pinMode(ir3,INPUT);
Serial.begin(9600);
}

void loop() {  

//val = analogRead(A0);
//float cel =  ( ( val/1024.0)*5000  ) /10;
//ThingSpeak.writeField(290798,1,cel,"OHDQXX2Y6AV5EUT7");  
//
//     if(digitalRead(ir1)==0) 
//    {
//      delay(1000);
//      if(digitalRead(ir2)==0)  { count++; }
//    }
//    if(digitalRead(ir2)==0) 
//    {
//      delay(1000);
//      if(digitalRead(ir1)==0)  { count--; }
//    }
//if(count>=1)
//{
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
//    
//if(digitalRead(ir3)==0)    { z+=1; }
//if(z%2==0)    {brc=1; }
//else {brc=0; }
//    
//if(brc==1)  {      
state3=ThingSpeak.readFloatField(290798,4,"RQGYZN6LXFK155P2");
Serial.print("LIGHT 3 IS NOW [ 1:ON / 0:OFF ] : ");
Serial.print(state3);
Serial.println(" ");
if (state3==1) { digitalWrite(c3,HIGH); }
else if (state3==0) { digitalWrite(c3,LOW); }
}
