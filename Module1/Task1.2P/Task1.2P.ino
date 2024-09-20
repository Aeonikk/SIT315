int baseTemp = 30;
float tempC = 0;
float voltage = 0;

void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  startTimer();
}

void loop()
{}

void startTimer()
{
  noInterrupts();
  
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  
  //set prescalar to 1024
  TCCR1B |= (1 << CS10);
  TCCR1B |= (1 << CS12);
  //enable CTC
  TCCR1B |= (1 << WGM12);
  //compare to timer for interrupt, 500ms
  OCR1A = 31250;
  //enables comparison of TCNT1 and OCR1A values for interrupt
  TIMSK1 |= (1 << OCIE1A);
  
  interrupts();
}

ISR(TIMER1_COMPA_vect)
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