#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp;
File dataFile;

#define DATA_FILE_NAME "data.txt"

// Found here: http://w1.weather.gov/data/obhistory/KSBM.html
// This value needs to be updated daily to local forcast for an accurate reading
#define REF_ALT 1018.5

// Comment out for prod
#define DEBUG

void setup() {
  #ifdef DEBUG
    Serial.begin(9600);
    Serial.println("Starting altitude logging");
  #endif

  // BMP280
   if (!bmp.begin()) {
    #ifdef DEBUG
      Serial.println("Could not find a valid BMP280 sensor, check wiring!");
    #endif
    while (1);
  }

  // SD
  if (!SD.begin(4)) {
    #ifdef DEBUG
      Serial.println("SD initialization failed!");
    #endif
    return;
  }
  delay(1000);
}

void loop() {
//  #ifdef DEBUG
//    Serial.print("Temperature = ");
//    Serial.print(bmp.readTemperature());
//    Serial.println(" *C");
//    
//    Serial.print("Pressure = ");
//    Serial.print(bmp.readPressure());
//    Serial.println(" Pa");
//
//    Serial.print("Approx altitude = ");
//    Serial.print(bmp.readAltitude(REF_ALT));
//    Serial.println(" m");
//    
//    Serial.println();
//    Serial.println();
//  #endif
  writeData();
}

/**
 * Write temp, pressure, and alt to SD card
 * Temperature in C, Pressure in Pa, Altitude in m
 */
void writeData() {
  dataFile = SD.open(DATA_FILE_NAME, FILE_WRITE);
  if (dataFile) {
    dataFile.print(millis());
    dataFile.print(" t: ");
    dataFile.print(bmp.readTemperature());
    dataFile.print(" p: ");
    dataFile.print(bmp.readPressure());
    dataFile.print(" a: ");
    dataFile.println(bmp.readAltitude(REF_ALT));
    dataFile.close();
  } else {
    #ifdef DEBUG
      Serial.print("Data write failed at '");
      Serial.print(millis());
      Serial.println("'");
    #endif
  }
}
