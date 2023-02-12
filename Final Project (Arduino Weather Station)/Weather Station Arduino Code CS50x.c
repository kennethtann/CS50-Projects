//Kenneth Tan for CS50x Final Project

#include <DHT.h>;
#include <LiquidCrystal_I2C.h>
#include <Wire.h>



LiquidCrystal_I2C lcd(0x27,16,2); 
  
#define DHTPIN 8     //the pin the dht is connected to
#define DHTTYPE DHT22   //dht11 or dht22, depending on which one you are using
DHT dht(DHTPIN, DHTTYPE);


float h;  //humidity value
float t; //temperature value



void setup()
{
    Serial.begin(9600);
    Serial.println("Weather Station for CS50x");
    dht.begin();
    lcd.init(); //lcd initialization
    lcd.backlight(); //turn on backlight
}



void loop()
{
    h = dht.readHumidity();
    t = dht.readTemperature();
    
    //Serial Monitor config
    Serial.print("Humidity: ");
    Serial.print(h, 1); //1 represents number of decimal pts
    Serial.print(" %, Temp: ");
    Serial.print(t, 1); //1 represents number of decimal pts
    Serial.println(" ° Celsius");
        

    //LCD Config
    lcd.setCursor(0, 0);
    lcd.println(" Weather Station "); //Edit text here
    
    lcd.setCursor(0, 1);
    lcd.print("T:");
    lcd.print(t, 1); //1 represents number of decimal pts
    lcd.print(char(223));
    lcd.print("C");


     
    lcd.setCursor(9, 1);
    lcd.print("H:");
    lcd.print(h, 1); //1 represents number of decimal pts
    lcd.print("%");
    
  delay(500); //Delay 0.5s
}

//Kenneth Tan for CS50x Final Project

