int count=0;
void setup() 
{
Serial.begin(9600);
pinMode(8,INPUT);
pinMode(9,INPUT);
}

void loop() {  

     if(digitalRead(8)==0)
     {
      delay(1000);
      if(digitalRead(9)==0)  { count++; }
     }
     
     else if(digitalRead(9)==0)    
     {
      delay(1000);
      if(digitalRead(8)==0)  { count--; }
     }
     Serial.println(count);
if(count>=1)
digitalWrite(11,HIGH);
else
digitalWrite(11,LOW);
}
