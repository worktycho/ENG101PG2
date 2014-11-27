
#include "msp430G2553.h"

#include "Light.h"

#define BIT_VREF BIT4
#define BIT_LIGHT BIT5
void setupADCs() {
    ADC10CTL0=SREF_1 + REFON + REFOUT + ADC10ON + ADC10SHT_3 + ADC10IE ; //1.5V ref, Ref on, Enable Ref Output, 64 clocks for sample
    ADC10CTL1=ADC10DIV_3;
    ADC10AE0 |= BIT_VREF + BIT_LIGHT;
}

int readTemp() {}
float calibrateTemp(int voltage) {}
void outputTemp(float temp) {}

void setHeater(float temp) {}

int readpH() {}
float calibratepH(int voltage) {}
void outputpH(float pH) {}

int readRotation() {}
int calibrateRPM(int RawRotationCount) {}
void outputRPM(int RPM) {}

void setMotor(int RPM) {}

void inputLoop() {
    int tempVoltage = readTemp();
    float tempValue = calibrateTemp(tempVoltage);
    outputTemp(tempValue);
    
    int lightVoltage = readLight();
    float lightValue = calibrateLight(lightVoltage);
    outputLight(lightValue);
    
    int pHVoltage = readpH();
    float pHValue = calibratepH(pHVoltage);
    outputpH(pHValue);
    
    int RawRotationCount = readRotation();
    int RPM = calibrateRPM(RawRotationCount);
    outputRPM(RPM);
    
    setMotor(RPM);
    setHeater(tempValue);
}

int main() {
  
    WDTCTL = WDTPW + WDTHOLD; // Stop WDT
    
    BCSCTL1 = CALBC1_1MHZ; // Set DCO to 1MHz
    DCOCTL = CALDCO_1MHZ; // Set DCO to 1MHz
    
    
    setupADCs();
    inputLoop();
}
