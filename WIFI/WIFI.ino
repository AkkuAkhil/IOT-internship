#include<ESP8266WiFi.h>
void setup() {
WiFi.mode(WIFI_AP);
WiFi.softAP("DORA","theexplorer");
Serial.begin(9600);
Serial.println( WiFi.softAPIP() );
}

void loop() {
}
