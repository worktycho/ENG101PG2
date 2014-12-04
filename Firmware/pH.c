#include "pH.h"
#include "ADC.h"
#include "Serial.h"

#define PH_SCALE 1
#define PH_OFFSET 0

int readpH() {
  return sampleADC(INCH_PH);
}
int calibratepH(int voltage) {
  return (int)(voltage * PH_SCALE) + PH_OFFSET;
}
void outputpH(int pH) {
  writeCharUART('P');
  writeCharUART(':');
  writeIntUART(pH);
  writeCharUART('\n');
}
