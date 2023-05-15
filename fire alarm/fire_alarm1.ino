// C++ code
//
const int buzzer= 12;
const int tempsen=A0;
void setup()
{
  pinMode(buzzer,OUTPUT);
  pinMode(tempsen,INPUT);
  Serial.begin(9600);
  
}

void loop()
{
 float temp=(analogRead(tempsen)*(5000/1024.0)-500)/10;
  Serial.println(temp);
  if(temp>50){
    digitalWrite(buzzer,HIGH);
  }else{
    digitalWrite(buzzer,LOW);
  }
}