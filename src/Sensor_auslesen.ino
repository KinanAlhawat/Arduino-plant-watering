void setup() {
  Serial.begin(1200);
  pinMode(12, OUTPUT);
}

void loop() {
  int val;
  val = analogRead(A0);
  Serial.println(val);
  delay(100);
  
  if (val <= 400){
    digitalWrite(12, HIGH);
  }else if (val >= 400){
    digitalWrite(12, LOW);
  }
  
}
