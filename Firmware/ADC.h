
#ifndef ADC_H
#define ADC_H

#define CHECKPOINT P1OUT |= BIT0

void setupADCs();

int sampleADC(int adc);

#endif
