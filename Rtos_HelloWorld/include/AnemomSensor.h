#ifndef ANEMOMSENSOR_H
#define ANEMOMSENSOR_H

#include <Arduino.h>

extern float RPM;
extern float ms_windSpeed;
extern float windDirection;

void initAnemomSensor();
void updateWindSpeedData();
void getWindSpeedData();
void updateWindDirectionData();
void getWindDirectionData();

#endif // ANEMOMSENSOR_H
