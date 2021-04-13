void setup() {
  Serial.begin(1200);
  pinMode(12, OUTPUT);
}

void loop() {
  int val;
  int val1;
  val = analogRead(A0);
  //Serial.println(val);
  delay(100);
  
  if (val <= 400){
    digitalWrite(12, HIGH);
  }else if (val >= 400){
    digitalWrite(12, LOW);
  }
  
  val1 = map (val, 596, 283, 0, 100);
  Serial.println(val1);
}
