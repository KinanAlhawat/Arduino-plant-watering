#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  Serial.begin(1200);
  pinMode(12, OUTPUT);
  
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Feuchtigkeit:");
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


  
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  lcd.print(val1);
  lcd.print(" ");
  lcd.setCursor(4, 1);
  lcd.print("%");
}
