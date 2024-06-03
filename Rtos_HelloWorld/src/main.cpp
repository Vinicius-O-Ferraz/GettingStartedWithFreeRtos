#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include "BMESensor.h"
#include "AnemomSensor.h"
#include "PluviomSensor.h"

void setup()
{
    Serial.begin(115200);

    initBMESensor();
    initAnemomSensor();
    initPluviomSensor();
}

void loop()
{
    updateBMESensorData();
    getBMESensorData();

    updateWindSpeedData();
    getWindSpeedData();

    updateWindDirectionData();
    getWindDirectionData();

    startPluviomTimer();
    getPluviomData();

    delay(1000);
}
