void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(SWITCH_PIN, INPUT);
}

void loop()
{
  if (digitalRead(SWITCH_PIN) == HIGH) 
  {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else 
  { 
    digitalWrite(LED_BUILTIN, LOW);
  }  
}
