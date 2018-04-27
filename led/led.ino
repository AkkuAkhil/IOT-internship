void setup() {
  pinMode(14,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
}

void loop() {
  int i=400;
  digitalWrite(13,HIGH);
  delay(i);
  digitalWrite(5,HIGH);
  delay(i);
  digitalWrite(4,HIGH);
  delay(i);
  digitalWrite(14,HIGH);
  delay(i);
  
  digitalWrite(13,LOW);
  delay(i);
  digitalWrite(5,LOW);
  delay(i);
  digitalWrite(4,LOW);
  delay(i);
  digitalWrite(14,LOW);
  delay(i);
}
