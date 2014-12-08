
#ifndef LIGHT_H
#define LIGHT_H

#include "msp430G2553.h"

#define BIT_LIGHT BIT7
#define INCH_LIGHT INCH_6

int readLight();
int calibrateLight(int voltage);
void outputLight(int light);

#endif
