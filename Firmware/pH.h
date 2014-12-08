#ifndef PH_H
#define PH_H

#include "msp430G2553.h"

#define BIT_PH BIT3
#define INCH_PH INCH_3

int readpH();
int calibratepH(int voltage);
void outputpH(int pH);

#endif
