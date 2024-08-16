#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP3XX.h>
#include <Adafruit_BME280.h>

Adafruit_BMP3XX bmp;
Adafruit_BME280 bme;

void setup() {
  Serial.begin(115200);
  
  if (!bmp.begin(0x76)) {
    Serial.println("Could not find a valid BMP3 sensor, check wiring!");
    while (1);
  }
  
  if (!bme.begin(0x76)) {  // BME280 I2C address
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
}

void loop() {
  if (!bmp.performReading()) {
    Serial.println("Failed to perform BMP3 reading :(");
    return;
  }

  Serial.print("SPL06 Temperature = ");
  Serial.print(bmp.temperature);
  Serial.println(" *C");

  Serial.print("SPL06 Pressure = ");
  Serial.print(bmp.pressure / 100.0);
  Serial.println(" hPa");

  Serial.print("BME280 Temperature = ");
  Serial.print(bme.readTemperature());
  Serial.println(" *C");

  Serial.print("BME280 Pressure = ");
  Serial.print(bme.readPressure() / 100.0);
  Serial.println(" hPa");

  Serial.print("BME280 Humidity = ");
  Serial.print(bme.readHumidity());
  Serial.println(" %");

  delay(2000);
}