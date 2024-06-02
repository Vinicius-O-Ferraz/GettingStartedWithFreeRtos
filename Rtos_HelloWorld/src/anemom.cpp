#include <Arduino.h>
#include "AnemomSensor.h"

#define PIN_SENSOR 2    // Pino digital 2
#define PIN_WINDSOCK A0 // Pino analógico A0

const unsigned long PERIOD = 5000; // Tempo de medição (milissegundos)
const int RADIUS = 147;            // Raio do anemômetro em milímetros

int counter = 0;        // Contador de interacoes magneticas do sensor
int RPM = 0;            // Rotacoes por minuto
float ms_windSpeed = 0; // Velocidade do vento (m/s)

int windsock_dir = 0; // Direção do vento (graus)

void addcount()
{
    counter++;
}

void RPMcalc()
{
    RPM = ((counter) * 60) / (PERIOD / 1000);
}

void WindSpeed()
{
    ms_windSpeed = ((4 * PI * RADIUS * RPM) / 60) / 1000; // Velocidade do vento(m/s)
}

void initAnemomSensor()
{
    pinMode(PIN_SENSOR, INPUT);
    attachInterrupt(digitalPinToInterrupt(PIN_SENSOR), addcount, RISING);
}

void getWindSpeedData()
{
    // while (true)
    // {
    Serial.print("Counter: ");
    Serial.print(counter);
    Serial.print(";  RPM: ");
    Serial.print(RPM);
    Serial.print(";  Wind speed: ");
    Serial.print(ms_windSpeed);
    Serial.println(" [m/s]");

    delay(PERIOD);
    // }
}

void updateWindSpeedData()
{
    // while (true)
    // {
    delay(PERIOD); // Espera pelo intervalo de medição

    RPMcalc();
    WindSpeed();
    // Reseta contador
    counter = 0;
    // }
}

void updateWindDirectionData()
{
    int windsock = analogRead(PIN_WINDSOCK);

    switch (windsock)
    {
    case 251 ... 280:
        windsock_dir = 0;
        break;
    case 0 ... 25:
        windsock_dir = 45;
        break;
    case 26 ... 60:
        windsock_dir = 90;
        break;
    case 61 ... 95:
        windsock_dir = 135;
        break;
    case 96 ... 135:
        windsock_dir = 180;
        break;
    case 136 ... 170:
        windsock_dir = 225;
        break;
    case 171 ... 210:
        windsock_dir = 270;
        break;
    case 211 ... 250:
        windsock_dir = 315;
        break;
    }
    windsock_dir = 0;
}

void getWindDirectionData()
{
    Serial.print("Windsock direction: ");
    Serial.println(windsock_dir);
    Serial.println();
}
