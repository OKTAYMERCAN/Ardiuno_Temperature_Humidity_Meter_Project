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
  #include <DHT.h>

//Constants
  #define DHTPIN 2     //DHT sensor (data) pin 
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

// Software SPI (slower updates, more flexible pin options):
// pin 7 - Serial clock out (SCLK)
// pin 6 - Serial data out (DIN)
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3); // RST-3, CE-4, D0-5, DIN-6, CLK-7

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


// Heat index compute and set variable section
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);
  
  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);
  
//Print temp and humidity values to serial monitor
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print(" %, Temp: ");
  Serial.print(temp);
  Serial.print(" Celsius, ");
  Serial.print("Heat index: ");
  Serial.println(hic);
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

// Heat index
  display.println("Hissedilen:");
  display.println(hic);           // Default is Celsius. For fahrenheit, change "hic" value to "hif".
  display.println();

// Text
  display.print("OKTAY MERCAN");
  display.display();      // This code is neccecary don't delete, otherwise your secren stuck on logo
}
