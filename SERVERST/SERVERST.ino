#include<ESP8266WiFi.h>
  int i=400,k=100;
WiFiServer MRBEAN(80);
void setup() {
  pinMode(14,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
Serial.begin(9600);
WiFi.mode(WIFI_STA);  //to make a station
WiFi.begin("Akku","incorrect");
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
     if(request.indexOf("ledon") !=-1 )
     {  
  digitalWrite(13,HIGH);
  delay(i);
  digitalWrite(5,HIGH);
  delay(i);
  digitalWrite(4,HIGH);
  delay(i);
  digitalWrite(14,HIGH);
  delay(i); }
     else if(request.indexOf("ledoff") !=-1 )
      {  
  digitalWrite(13,LOW);
  delay(i);
  digitalWrite(5,LOW);
  delay(i);
  digitalWrite(4,LOW);
  delay(i);
  digitalWrite(14,LOW);
  delay(i); }
  else if(request.indexOf("blink") !=-1 )
      { for(int j=0;j<25;j++) {
  digitalWrite(13,HIGH);
  delay(k);
  digitalWrite(5,HIGH);
  delay(k);
  digitalWrite(4,HIGH);
  delay(k);
  digitalWrite(14,HIGH);
  delay(k);
  
  digitalWrite(13,LOW);
  delay(k);
  digitalWrite(5,LOW);
  delay(k);
  digitalWrite(4,LOW);
  delay(k);
  digitalWrite(14,LOW);
  delay(k); 
      }}
      buji.flush();
}
