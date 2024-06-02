#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include "BMESensor.h"
#include "AnemomSensor.h"
#include "PluviomSensor.h"

void setup()
{
    initBMESensor();
    initAnemomSensor();
    initPluviomSensor();

    updateBMESensorData();
    getBMESensorData();

    updateWindSpeedData();
    getWindSpeedData();

    startPluviomTimer();
    getPluviomData();
}

void loop()
{
    // Não utilizado quando FreeRTOS está em execução
}
