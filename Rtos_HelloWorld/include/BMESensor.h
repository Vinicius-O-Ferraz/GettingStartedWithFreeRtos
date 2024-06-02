#ifndef BMESENSOR_H
#define BMESENSOR_H

#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

extern Adafruit_BME280 bme;
extern float temperature;
extern float pressure;
extern float altitude;
extern float humidity;

void initBMESensor();
void updateBMESensorData();
void getBMESensorData();

#endif // BME280SENSOR_H
