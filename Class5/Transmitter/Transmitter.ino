
int potPin = A0;
int lightPin = A1;

int potValue = 0;
int lightValue = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  potValue = analogRead(potPin);    
  lightValue = analogRead(lightPin);
  Serial.print(potValue);
  Serial.print(",");
  Serial.println(lightValue);

  delay(500);
}


