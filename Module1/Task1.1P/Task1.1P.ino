int baseTemp = 30;
float tempC = 0;
float voltage = 0;

void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  voltage = analogRead(A0)*(5.0/1023.0);
  tempC = (voltage-0.5)*100;
  
  Serial.print("Raw: "); Serial.print(analogRead(A0));
  Serial.print(". Volts: "); Serial.print(voltage);
  Serial.print(". Celsius: "); Serial.println(tempC);
  
  if (tempC > baseTemp){
  	digitalWrite(13, HIGH);
  }
  else{
  	digitalWrite(13, LOW);
  }
}