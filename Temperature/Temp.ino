//Name: H.M.Laviru Githmal Herath
//Student ID: 2064801

#include <SimpleDHT.h>
#include <LiquidCrystal.h>
#include <SPI.h>

int pinDHT11 = 7;
SimpleDHT11 dht11(pinDHT11);

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

unsigned long start, finished, elapsed;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  Serial.begin(115200);
}

void loop() {
  // start working...
  Serial.println("=================================");
  Serial.println("Sample DHT11...");

  // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.print(SimpleDHTErrCode(err));
    Serial.print(","); Serial.println(SimpleDHTErrDuration(err)); delay(1000);
    return;
  }


  Serial.print((int)temperature); Serial.print(" *C, ");
  Serial.print((int)humidity); Serial.println(" H");

  // DHT11 sampling rate is 1HZ.
  delay(2000);


  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" *C ");


  if (temperature >= 26)
  {
    lcd.clear();
    DisplayResult();
    
  }
  else{
    start = millis();
    finished = millis();
    
    }
  
}


void DisplayResult()
{

  finished = millis(); // saves stop time to calculate the elapsed time
  // declare variables
  float h, m, s, ms;
  unsigned long elapsed=0;
  unsigned long over;
  // MATH time!!!
  elapsed = finished - start;
  h = int(elapsed / 3600000);
  over = elapsed % 3600000;
  m = int(over / 60000);
  over = over % 60000;
  s = int(over / 1000);
  ms = over % 1000;

  // display the results
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(h, 0); // display variable 'h' - the 0 after it is thenumber of algorithms after a comma (ex: lcd.print(h, 2); would print0,00
  lcd.print("h "); // and the letter 'h' after it
  lcd.print(m, 0);
  lcd.print("m ");
  lcd.print(s, 0);
  lcd.print("s ");
  if (h < 10)
  {
    lcd.print(ms, 0);
    lcd.print("ms ");
  }
}
