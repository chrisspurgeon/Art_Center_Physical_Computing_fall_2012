void blinker(int x) {
  Serial.println("In blinker");
  Serial.println(x);

  digitalWrite(ledPin, HIGH);  
  delay(x);          
  digitalWrite(ledPin, LOW);   
  delay(x);                  

}
