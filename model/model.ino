#include<ESP8266WiFi.h>
#include<String.h>
int i=400,k=100,brc=0,x=0,y=0,count=0;
WiFiServer MRBEAN(80);
void setup() {
  pinMode(14,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
Serial.begin(9600);
WiFi.mode(WIFI_STA);  //to make a station
WiFi.begin("AkHiL_AkKu","xmlphprails");
Serial.begin(9600);
while(WiFi.status()!=WL_CONNECTED)  {
  Serial.println("Connecting......");
  delay(1000); 
}                                                               
Serial.println( WiFi.localIP() );
MRBEAN.begin();
}

void loop() 
   {
    WiFiClient buji; 
    while((buji=MRBEAN.available())==0);
    {
     Serial.println("connected");
     Serial.println( buji.remoteIP() );
    }
     while(buji.connected()==1 && buji.available()==0) 
     {
      delay(1);
     }
     buji.println("HTTP/1.1 200 OK");
     String request=buji.readStringUntil('\r') ;
     delay(1);
/*
     if(digitalRead(12)==HIGH)    { x+=1; }
    if(x>=1)  {
      if(digitalRead(11)==HIGH)  { count+=1; }
      else { x=0; }
    }
    if(digitalRead(11)==HIGH)    { y+=1; }
    if(y>=1)  {
      if(digitalRead(12)==HIGH)  { count-=1; }
      else { y=0; }
    }
if(count>=1)
{*/
     if(request.indexOf("light1on") !=-1 )
     {  
          digitalWrite(13,HIGH); 
     }
     else if(request.indexOf("light1off") !=-1 )
     {  
          digitalWrite(13,LOW); 
     }
     
     else if(request.indexOf("ac1on") !=-1 )
     {  
          digitalWrite(14,HIGH); 
     }
     else if(request.indexOf("ac1off") !=-1 )
     {  
          digitalWrite(14,LOW); 
     }
/*
}
    if(digitalRead(10)==HIGH)    { brc+=1; }
    if(brc>=1)  {
*/
     if(request.indexOf("light2on") !=-1 )
     {  
          digitalWrite(13,HIGH); 
     }
     else if(request.indexOf("light2off") !=-1 )
     {  
          digitalWrite(13,LOW); 
     }
      buji.flush();//}
}

