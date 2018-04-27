#include<ESP8266WiFi.h>
#include<String.h>
WiFiServer MRBEAN(80);
int f=0;
void setup()
{
  pinMode(D3,OUTPUT);
  pinMode(D4,OUTPUT);
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);  //to make a station
  //WiFi.begin("DZONE NETWORK","12345678d");
  WiFi.begin("AkHiL_AkKu","xmlphprails");
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
      f=1;
      Serial.println(f);
     }
    
     while(buji.connected()==1 && buji.available()==0) 
      {
       delay(1);
      }
     buji.println("HTTP/1.1 200 OK");
     String request=buji.readStringUntil('\r') ;
     delay(1);
     Serial.println(request);
     
     /* if(request.indexOf("firston") !=-1) { digitalWrite(D3,HIGH); }
      if(request.indexOf("firstoff") !=-1) { digitalWrite(D3,LOW); }
      if(request.indexOf("laston") !=-1) { digitalWrite(D4,HIGH); }
      if(request.indexOf("lastoff") !=-1) { digitalWrite(D4,LOW); } */
     
     if(request.indexOf("inagurate") !=-1 )
   {  
    digitalWrite(D4,HIGH);
   }
  else if(request.indexOf("firstup") !=-1 )
   {  
     while(request.indexOf("firstup") !=-1 )
       {
         digitalWrite(D3,HIGH);
       }
       
     digitalWrite(D3,LOW);
   }
  else if(request.indexOf("firstdown") !=-1 )
      { 
        digitalWrite(D3,LOW);
        while(request.indexOf("firstup") !=-1 )
          {
            digitalWrite(D4,HIGH);
          }
        digitalWrite(D4,LOW);
      }
     buji.flush();

  buji.println("Content-Type:text/html");
  buji.println("");
  buji.println("<!DOCTYPE html>");
  buji.println("<html>");
  buji.println("<head>");
  buji.println("<title>led</title>");
  buji.println("</head>");
  buji.println("<body><center><h1 style=\"color:red;\"><b> IEEE AKSC </h1></b>");
  buji.println("<button style=\"background-color:yellow; border: 2px solid #4CAF50;\"><a href=\"/ledon\"> LED ON </a></button><br><br>");
  buji.println("<button><a href=\"/inagurate\"> INUGRATE </a></button><br><br>");
  buji.println("<button><a href=\"/firstup\"> UP </a></button><br><br>");
  buji.println("<button><a href=\"firstdown/\">DOWN </a></button><br><br>");
  buji.println("</center> </body>");
  buji.println("</html>");
     }
