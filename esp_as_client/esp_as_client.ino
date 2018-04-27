#include<ESP8266WiFi.h>
WiFiClient Client;
void setup() 
{
  Serial.begin(9600);
  WiFi.mode(WIFI_AP);//to make an acyive point
  WiFi.softAP("DORA","theexplorer");
  
  Serial.println( WiFi.softAPIP());
  pinMode(13,INPUT);
  pinMode(12,INPUT);
  Serial.println("hello");
}
void loop() 
{
  char buttonState1,buttonState2;
  buttonState1 = digitalRead(13);
  buttonState2 = digitalRead(12);

  if (buttonState1==LOW) 
  {
    Serial.println("HIIIIIII");
    if(Client.connect("192.168.4.2",80)==1)
    { 
    Serial.println("connected");
     Client.print("/ledon \r");
    Client.stop();
    delay(1000);
    }}
  else if (buttonState2==LOW) 
  {
    Serial.println("HUUUUUUUUUI");
      if(Client.connect("192.168.4.2",80)==1)
    {
    Serial.println("NOTconnected");
    Client.print("/ledoff \r");
    Client.stop();
    delay(1000);}}
}
