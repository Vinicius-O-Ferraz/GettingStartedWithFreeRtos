#include <Arduino.h>
#include "PluviomSensor.h"

#define PIN_SENSOR_P 2 // Pino digital 2

int basculaCount = 0; // Current value of reed switch
float mmChuva = 0;    // Rainfall in mm
unsigned long previousMillis = 0;

void addBasculaCount()
{
    basculaCount++;
}

void initPluviomSensor()
{
    pinMode(PIN_SENSOR_P, INPUT_PULLUP); // This activates the internal pull up resistor
    attachInterrupt(digitalPinToInterrupt(PIN_SENSOR_P), addBasculaCount, RISING);
}

void getPluviomData()
{
    mmChuva = basculaCount * 0.25;

    Serial.print("Medida de chuva (contagem): ");
    Serial.print(basculaCount); //*0.2794);
    Serial.print(" | ");
    Serial.print("Medida de chuva (calculado): ");
    Serial.print(mmChuva * 0.25);
    Serial.println(" mm");
}


void startPluviomTimer()
{
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= INTERVALO_5_MINUTOS)
    {
        previousMillis = currentMillis;
        getPluviomData();
    }
}
