#ifndef ANEMOMSENSOR_H
#define ANEMOMSENSOR_H

#include <Arduino.h>

extern int RPM;
extern float ms_windSpeed;
extern int windsock_dir;

void initAnemomSensor();
void updateWindSpeedData();
void getWindSpeedData();
void updateWindDirectionData();
void getWindDirectionData();

#endif // ANEMOMSENSOR_H
