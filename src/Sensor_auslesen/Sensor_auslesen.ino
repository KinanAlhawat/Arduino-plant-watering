void setup() {
  Serial.begin(1200);
  pinMode(12, OUTPUT);    //Pin 12 steuert das Relais
}

void loop() {
  int val;
  int val1;
  val = analogRead(A0);   //Analogpin A0 lest die Segnale des Sensors aus

  val1 = map (val, 596, 283, 0, 100);    //Mit der map() Funktion werwandeln wir die ausgelese Sinale zu Prozentzahlen
  Serial.println(val1);   
 // Serial.println(val);  //Falls man die Pumpe mit den normalen Werten statt mit Prozent-Angaben Steuern will
  
    if (val1 <= 20){       //Die Pumpe geht 20% Feuchtigkeit an
    digitalWrite(12, HIGH);
  }else if (val1 >= 20){   //Die Pumpe geht 20% Feuchtigkeit aus
    digitalWrite(12, LOW);
  }
  
}
