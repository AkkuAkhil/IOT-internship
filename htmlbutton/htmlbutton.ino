#include<ESP8266WiFi.h>
#include<String.h>
  int i=400,k=100;
WiFiServer MRBEAN(80);
void setup() {
  pinMode(14,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
Serial.begin(9600);
WiFi.mode(WIFI_STA);  //to make a station
WiFi.begin("JioFi3_2863C8","ypp24wca36");
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
buji.println("Content-Type:text/html");
buji.println("");
buji.println("<!DOCTYPE html>");
buji.println("<html>");
buji.println("<head>");
buji.println("<title>led</title>");
buji.println("</head>");
buji.println("<h1 style=\"color:red;\"><b> LED </h1></b>");
buji.println("<button style=\"background-color:yellow; border: 2px solid #4CAF50;\"><a href=\"/ledon\"> LED ON </a></button><br><br>");
buji.println("<button><a href=\"/ledoff\"> LED OFF </a></button><br><br>");
buji.println("<button><a href=\"/blink\"> LED BLINK </a></button><br><br>");
buji.println("</center> </body>");
buji.println("</html>");
}
