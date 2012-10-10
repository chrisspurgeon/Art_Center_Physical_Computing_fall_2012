int brightness;

void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}
void loop() {
  brightness = analogRead(A0);
  if (brightness > 500) {
    // do something 
  } 
  else {
    brightness = map(analogRead(A0),0,500,0,3);
    Serial.println(brightness);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    if (brightness == 1) {
      digitalWrite(9,HIGH);
    }
    if (brightness == 2) {
      digitalWrite(9,HIGH);
      digitalWrite(10,HIGH);
    }
    if (brightness == 3) {
      digitalWrite(9,HIGH);
      digitalWrite(10,HIGH);
      digitalWrite(11,HIGH);
    }
  }

}

