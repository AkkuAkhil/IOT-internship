

void setup() {
  pinMode(13, OUTPUT);
  pinMode(4, INPUT);
}

void loop() {
  char buttonState=LOW;
  buttonState = digitalRead(4);
  if (buttonState == HIGH) {
    digitalWrite(13, LOW);
  } else {
    digitalWrite(13, HIGH);
  }
}
