void setup() {
  Serial.begin(1200);
  pinMode(4, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(4, HIGH);
  digitalWrite(13, HIGH);
  int val;
  int val1;
  val = analogRead(A0);
  delay(100);

  val1 = map (val, 596, 283, 0, 100);
  Serial.println(val1);
  
  if (val1 <= 50){
    digitalWrite(12, HIGH);
  }else if (val1 >= 50){
    digitalWrite(12, LOW);
  //  hi
  }
  
}
