
#include "msp430g2553.h"

#include "ADC.h"
#include "Light.h"
#include "Temp.h"
#include "pH.h"
#include "Serial.h"

#define BIT_VREF BIT4

void setupADCs() {
    ADC10CTL0=SREF_1 + REFON + REFOUT + ADC10ON + ADC10SHT_3 + ADC10IE ; //1.5V ref, Ref on, Enable Ref Output, 64 clocks for sample
    ADC10CTL1= ADC10ON | ADC10DIV_3;
    ADC10AE0 |= BIT_VREF + BIT_LIGHT + BIT_TEMP + BIT_PH;
}

volatile int ADCSampled;

int sampleADC(int adc) {
    ADC10CTL1 = adc;
    int ret = 0;
    ADCSampled = 0;
    ADC10CTL0 |= ENC + ADC10SC;// + ADC10IE;
    while (!ADCSampled) {
        __bis_SR_register(CPUOFF + GIE);
        ret = ADC10MEM;
    }
    return ret;
}

// ADC10 interrupt service routine
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR (void)
{        
    ADCSampled = 1;
    __bic_SR_register_on_exit(CPUOFF);// Return to active mode
    
}
 


