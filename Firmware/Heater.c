
#include "msp430g2553.h"

#include "Heater.h"

int RequiredTemp = 0;

void configureHeater() {
  P2DIR |= HEATER_BIT;
  P2OUT &= ~HEATER_BIT;
}

void setRequiredTemp(int Temp) {
  RequiredTemp = Temp;
}

void setHeater(int Temp) {
  if (Temp < RequiredTemp) {
    P2OUT |= HEATER_BIT;
  } else {
    P2OUT &= ~HEATER_BIT;
  }
}

