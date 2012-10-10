
int brightness;


void setup() {
  pinMode(9, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}



void loop() {
  brightness = analogRead(A0);
  Serial.println(brightness);
//  brightness = map(brightness,0,1023,0,255);
  brightness = random(0,255);
  analogWrite(9,brightness);
  delay(random(50,200));
  
}


