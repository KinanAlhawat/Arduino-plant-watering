#include <LiquidCrystal.h>
#include <dht_nonblocking.h>
#define DHT_SENSOR_TYPE DHT_TYPE_11

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

static const int DHT_SENSOR_PIN = 2;
DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE );

void setup() {
  Serial.begin(1200);
  pinMode(13, OUTPUT);
  lcd.begin(16, 2);       // LCD Diagonale
  lcd.print("Feuchte :"); // Print a message to the LCD.
  lcd.setCursor(0, 1);
  lcd.print("Temp. :");
}

//////////////////////////////////////////////////////////////////////////

static bool measure_environment( float *temperature, float *humidity)
{
  static unsigned long measurement_timestamp = millis( );

  /* Measure once every four seconds. */
  if( millis( ) - measurement_timestamp > 3000ul )
  {
    if( dht_sensor.measure( temperature, humidity) == true )
    {
      measurement_timestamp = millis( );
      return( true );
    }
  }

  return( false );
}
//////////////////////////////////////////////////////////////////////////
static int measure_ground_humidity()
{
  static unsigned long measurement_timestamp = millis();
  int ground_humidity;
  /* Measure once every four seconds. */
  if( millis( ) - measurement_timestamp > 3000ul )
  {
    ground_humidity = analogRead(A0);   //Analogpin A0 lest die Segnale des Sensors aus

    ground_humidity = map (ground_humidity, 610, 283, 0, 100);    //Mit der map() Funktion werwandeln wir die ausgelese Sinale zu Prozentzahlen
    Serial.println(ground_humidity);

    measurement_timestamp = millis( );
    return( ground_humidity );
  }

  return( -1 );
}
//////////////////////////////////////////////////////////////////////////
static boolean pump()
{
  digitalWrite(13, HIGH);   
  delay(5000);                      
  digitalWrite(13, LOW);
  return(true);
}
//////////////////////////////////////////////////////////////////////////

void loop() {
  float temperature;
  float humidity;
  int ground_humidity;

  // (note: line 1 is the second row, since counting begins with 0):
  ground_humidity = measure_ground_humidity( );
  
  if(ground_humidity >= 0 ){
    lcd.setCursor(11, 0);
    lcd.print(ground_humidity);
    lcd.print(" ");
    lcd.setCursor(13, 0);
    lcd.print("%");
    if (ground_humidity <= 20){
      pump();
    }
 }
///////////////////////////////////////////////////////////////////////
  if( measure_environment( &temperature, &humidity ) == true )
  {
    Serial.print( "T = " );
    Serial.print( temperature, 1 );
    Serial.print( " deg. C, H = " );
    Serial.print( humidity, 1 );
    Serial.println( "%" );
    lcd.setCursor(13, 1);
    lcd.print("C");
    lcd.setCursor(8, 1);
    lcd.print( temperature, 1 );
  }
}
