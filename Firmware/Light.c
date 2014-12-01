
#include "Light.h"
#include "ADC.h"
#include "Serial.h"

#define LIGHT_SCALE 1
#define LIGHT_OFFSET 0

int readLight() {
  return sampleADC(INCH_LIGHT);
}
int calibrateLight(int voltage) {
  return (int)(voltage * LIGHT_SCALE) + LIGHT_OFFSET;
}
void outputLight(int light) {
  writeCharUART('L');
  writeCharUART(':');
  writeIntUART(light);
  writeCharUART('\n');
}
