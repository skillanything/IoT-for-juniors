// C++ code
//
int LED= 12;
void setup()
{
  pinMode(A0, INPUT);
  pinMode(LED,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int data =analogRead(A0);
  if(data<350){
    digitalWrite(LED,HIGH);
  }else{
    digitalWrite(LED,LOW);
  }
}