
#ifndef LIGHT_H
#define LIGHT_H

#include "msp430G2553.h"

#define BIT_LIGHT BIT5
#define INCH_LIGHT INCH_3

int readLight();
float calibrateLight(int voltage);
void outputLight(float light);

#endif
