// Intelligent Air Care: Predictive Maintenance for Air Conditioners
// project by Bavadharini-G-S
// https://github.com/Bavadharini-G-S
// This code is used to test the working of the sensors and to display the sensor values in an OLED Display


#include <Wire.h>
#include <HX711.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "DHT.h"
#define DHTPIN 19               //Temperature & Humidity sensor
#define DHTTYPE DHT11           
#define MQ135 34                //Air quality sensor
#define SW420 35                //Vibration sensor
#define HX710B                  //Air pressure sensor
DHT dht(DHTPIN, DHTTYPE);

#define SCREEN_WIDTH 128        // OLED display width, in pixels
#define SCREEN_HEIGHT 64        // OLED display height, in pixels

int vibration=0;
float vibrationfinal;

const int LOADCELL_DOUT_PIN = 32;
const int LOADCELL_SCK_PIN = 33;

HX711 scale;
// Declaration for an SSD1306 display connected to I2C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);
  Serial.println(F("DHTxx test!"));
  dht.begin();
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);

  pinMode(MQ135, INPUT);

  pinMode(SW420, INPUT);
  
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);  

  display.clearDisplay();

  display.setTextSize(1.5);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
  display.println("Hello, world!");
  display.display(); 
}

void loop() {
  delay(2000);

  //Reading Humidity and Temperature Data - Sensor 1
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    h=0;
    t=0;
  }

  //Reading Air Quality Data - Sensor 2
  int airquality = analogRead(MQ135);

  //Reading Vibration Data - Sensor 3
  vibrationfinal=0;
  for (int i = 0; i <= 1023; i++) {
    vibration=digitalRead(SW420);
    vibrationfinal += vibration;
  }
  vibrationfinal = map(vibrationfinal, 0, 1023, 0, 100);

  //Reading Air Pressure Data - Sensor 4
  float pressure = (scale.read());
  pressure = pressure - 2450000;     // add offset
  pressure = pressure * (-0.000018); // add scale factor


  //Printing in Serial Moniter
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.println(" %");
  Serial.print(F("Temperature: "));
  Serial.print(t);
  Serial.println(F("°C "));
  Serial.print("Air Quality: ");
  Serial.print(airquality);
  Serial.println(" PPM");
  Serial.print("Vibration: ");
  Serial.print(vibrationfinal);
  Serial.println(" %");
  Serial.print("Air Pressure: ");
  Serial.print(pressure);
  Serial.println(" %");
  Serial.println();

  //Printing in OLED Display
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.print("Humidity: ");
  display.print(h);
  display.println(" %");
  display.print("Temperature: ");
  display.print(t);
  display.println(" C");
  display.print("Air Quality: ");
  display.print(airquality);
  display.println(" PPM");
  display.print("Vibration: ");
  display.print(vibrationfinal);
  display.println(" %");
  display.print("Air Pressure: ");
  display.print(pressure);
  display.println(" %");
  display.display(); 
}