#define c3 11
#define ir1 8
float state3;
int brc=0,count=0,x=0,y=0,z=0,val;
void setup() 
{
Serial.begin(9600);
pinMode(c3,OUTPUT);digitalWrite(c3,LOW);
pinMode(ir1,INPUT);
Serial.begin(9600);
}

void loop() {  
Serial.println(digitalRead(ir1));
if(digitalRead(ir1)==0)    { z+=1; }
if(z%2==0)    {brc=1; }
else {brc=0; }
if(brc==1)       { digitalWrite(c3,HIGH); }
else if (brc==0) { digitalWrite(c3,LOW); }
delay(500);
}
