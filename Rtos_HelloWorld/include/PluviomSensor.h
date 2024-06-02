#ifndef PLUVIOMSENSOR_H
#define PLUVIOMSENSOR_H

#include <Arduino.h>

#define INTERVALO_5_MINUTOS 300000
extern int basculaCount;
extern float mmChuva;

void initPluviomSensor();
void getPluviomData();
void startPluviomTimer();

#endif // PLUVIOMSENSOR_H