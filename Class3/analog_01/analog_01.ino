/* 
Let's read some analog values.
 */

int d;

void setup() {
  pinMode(A0, INPUT);
  pinMode(12,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  d = analogRead(A0);
  Serial.println(millis());
  digitalWrite(12,HIGH);
  delay(d);
  digitalWrite(12,LOW);
  delay(d);
}


