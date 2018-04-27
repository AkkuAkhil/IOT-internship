float status;

void setup() {
pinMode(A0,INPUT);
Serial.begin(9600);
}

void loop() {
status=analogRead(A0);
Serial.print(status/1024);
Serial.print(" V");
Serial.println(' ');

delay(500);
}
