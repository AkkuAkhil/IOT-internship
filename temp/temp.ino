int val;
void setup()
{
pinMode(A0,INPUT);
Serial.begin(9600);
}
void loop()
{
val = analogRead(A0);
float mv = ( val/1024.0)*5000; 
float cel = mv/10;
float farh = (cel*9)/5 + 32;
Serial.print("TEMPRATURE = ");
Serial.print(cel);
Serial.print("*C");
Serial.println();
delay(1000);
}
