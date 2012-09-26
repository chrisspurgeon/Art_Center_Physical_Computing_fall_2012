/* Let's flash a light based on a
 analog read value, based on conecting a pot to 
 A0. We can add map() and constrain() to limit values.
 */

int delayValue = 100;


void setup() {
  pinMode(9, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}



// Note that as you use larger delay values, you're trapped 
// in the loop longer, so the device is less responsive.
void loop() {
  delayValue = map(analogRead(A0),0,1023,2,5000);
  Serial.println(delayValue);
  digitalWrite(9, HIGH);
  delay(delayValue);
  digitalWrite(9, LOW);
  delay(delayValue);
}


