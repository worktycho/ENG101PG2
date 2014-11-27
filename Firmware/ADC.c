
#include "msp430g2553.h"

#include "ADC.h"
#include "Light.h"

#define BIT_VREF BIT4

void setupADCs() {
    ADC10CTL0=SREF_1 + REFON + REFOUT + ADC10ON + ADC10SHT_3 + ADC10IE ; //1.5V ref, Ref on, Enable Ref Output, 64 clocks for sample
    ADC10CTL1=ADC10DIV_3;
    ADC10AE0 |= BIT_VREF + BIT_LIGHT;
}

volatile int ADCSampled;

int sampleADC(int adc) {
    // TODO: select adc
    int ret = 0;
    ADCSampled = 0;
    while (!ADCSampled) {
        ADC10CTL0 |= ENC + ADC10SC;
        __bis_SR_register(CPUOFF + GIE);
        ret = ADC10MEM;
    }
}

// ADC10 interrupt service routine
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR (void)
{
    __bic_SR_register_on_exit(CPUOFF);// Return to active mode
}
 


