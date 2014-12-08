
#include "msp430G2553.h"

#include "Light.h"
#include "pH.h"
#include "Temp.h"
#include "Motor.h"

#define CHECKPOINT P1OUT |= BIT0


void inputLoop() {
  while (1) {
    //WDTCTL = WDTCNTCL;

    int tempVoltage = readTemp();
    int tempValue = calibrateTemp(tempVoltage);
    outputTemp(tempValue);

    int lightVoltage = readLight();
    int lightValue = calibrateLight(lightVoltage);
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
}

int main() {

  WDTCTL = WDTPW + WDTHOLD; // WDT_MDLY_32;

  // Serial code is dependent on this value
  BCSCTL1 = CALBC1_1MHZ; // Set DCO to 1MHz
  DCOCTL = CALDCO_1MHZ; // Set DCO to 1MHz

  //Debug

  P1DIR |= BIT0;
  P1OUT &= ~BIT0;


  setupADCs();
  setupUART();

  setupRotation();

  configureMotor();
  configureHeater();

  inputLoop();
}


