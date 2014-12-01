
#include "Light.h"
#include "ADC.h"

#define LIGHT_SCALE 1
#define LIGHT_OFFSET 0

int readLight() {
  return sampleADC(INCH_LIGHT);
}
float calibrateLight(int voltage) {
  return (voltage * LIGHT_SCALE) + LIGHT_OFFSET;
}
void outputLight(float light) {}
