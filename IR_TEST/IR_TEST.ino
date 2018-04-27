int ipin=9;
void setup() 
{
pinMode(ipin,INPUT);//set infrared-out pin as input
Serial.begin(9600);
}

void loop() {  
Serial.println(digitalRead(ipin));  // 1:no obstacle and 0:obstacle
}
