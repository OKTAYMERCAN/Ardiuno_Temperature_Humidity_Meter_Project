/*********************************************************************
This is an example sketch for our Monochrome Nokia 5110 LCD Displays

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/338

These displays use SPI to communicate, 4 or 5 pins are required to
interface

Adafruit invests time and resources providing this open source code,
please support Adafruit and open-source hardware by purchasing
products from Adafruit!

Written by Limor Fried/Ladyada  for Adafruit Industries.
BSD license, check license.txt for more information
All text above, and the splash screen must be included in any redistribution


LCD5110_ViewFont 
Copyright (C)2015 Rinky-Dink Electronics, Henning Karlsen. All right reserved
web: http://www.RinkyDinkElectronics.com/
*********************************************************************/

//-------------------------------------
//|Combined and edited by OKTAY MERCAN|
//-------------------------------------

// This program requires Nokia 5110 LCD module and DHT22(AM2302) Sensor.

//Library
  #include <SPI.h>
  #include <Adafruit_PCD8544.h>
  #include <Adafruit_Sensor.h>
  #include <DHT.h>;

//Constants
  #define DHTPIN 7     // what pin we're connected to
  #define DHTTYPE DHT22   // DHT 22  (AM2302)
  #define NUMFLAKES 10
  #define XPOS 0
  #define YPOS 1
  #define DELTAY 2
  #define LOGO16_GLCD_HEIGHT 16
  #define LOGO16_GLCD_WIDTH  16

//Variables
  int chk;
  float hum;  //Stores humidity value
  float temp; //Stores temperature value

Adafruit_PCD8544 display = Adafruit_PCD8544(8, 9, 10, 12, 11);
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino

void setup()   {
  Serial.begin(9600);
  dht.begin();
  display.begin();              // init done
  display.setContrast(50);      // you can change the contrast around to adapt the display for the best viewing!
  display.display();            // show splashscreen
  display.clearDisplay();       // clears the screen and buffer

}

void loop() {
  display.clearDisplay();   // clears the screen and buffer
    
//DHT22 (AM2302) Sensor code
  delay(2000);
  //Read data and store it to variables hum and temp
  hum = dht.readHumidity();
  temp= dht.readTemperature();
  //Print temp and humidity values to serial monitor
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print(" %, Temp: ");
  Serial.print(temp);
  Serial.println(" Celsius");
  delay(10000); //Delay

// Temp
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.print("SICAKLIK:");
  display.println(temp);

//Humid
  display.print("NEM     :");
  display.println(hum);
  display.println();
  display.print("OKTAY MERCAN");
  display.display();
}
