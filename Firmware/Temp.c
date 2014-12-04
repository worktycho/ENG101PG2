#include "Temp.h"
#include "ADC.h"
#include "Serial.h"

#define TEMP_SCALE 1
#define TEMP_OFFSET 0

int readTemp() {
  return sampleADC(INCH_TEMP);
}
int calibrateTemp(int voltage) {
  return (int)(voltage * TEMP_SCALE) + TEMP_OFFSET;
}
void outputTemp(int temp) {
  writeCharUART('T');
  writeCharUART(':');
  writeIntUART(temp);
  writeCharUART('\n');
}
