#ifndef PH_H
#define PH_H

#include "msp430G2553.h"

#define BIT_PH BIT7
#define INCH_PH INCH_7

int readpH();
int calibratepH(int voltage);
void outputpH(int pH);

#endif
