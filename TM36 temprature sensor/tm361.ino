// C++ code
//
void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop()
{
  float data =analogRead(A0)*(5000/1024.0);
  Serial.print((data-500)/10);
  Serial.println(" C");
}