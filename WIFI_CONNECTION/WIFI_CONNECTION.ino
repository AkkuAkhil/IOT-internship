#include<ESP8266WiFi.h>
void setup() {
Serial.begin(9600);
WiFi.mode(WIFI_STA);  //to make a station
WiFi.begin("Akku","incorrect");
Serial.begin(9600);
while(WiFi.status()!=WL_CONNECTED)  {
  Serial.println("Connecting......");
  delay(1000); 
}
Serial.println( WiFi.localIP() );
}

void loop() {
}
