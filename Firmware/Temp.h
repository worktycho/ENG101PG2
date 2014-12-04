#ifndef TEMP_H
#define TEMP_H

#include "msp430G2553.h"

#define BIT_TEMP BIT2
#define INCH_TEMP INCH_0

int readLight();
int calibrateLight(int voltage);
void outputLight(int light);

#endif
