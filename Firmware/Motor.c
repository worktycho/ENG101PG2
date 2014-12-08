
#include "msp430g2553.h"

#define BIT_MOTOR BIT6

int RequiredSpeed = 0;

void configureMotor() {
  P1DIR |= BIT_MOTOR;
  P1SEL |= BIT_MOTOR;
  P1SEL2 &= ~BIT_MOTOR;
  
  /* Configure timer A as a PWM */
  TA0CTL = TASSEL_2 + MC_1 + ID_0; // SMCLK as input clock, count up to TA0CCR0, clock/1
  TA0CCR0 = 1000; // Set maximum count value to determine PWM frequency = SMCLK/ClockDivide/TACCR0 (1MHz/1/1000 = 1kHz)
  TA0CCR1 = 0; // Initialise counter compare value 1 to control Duty Cycle = TACCR1/TACCR0 (100/1000 = 10%)
  TA0CCTL1 = OUTMOD_7; // Set output to on when counter resets and off when counter equals TA0CCR1. Normal PWM.
}

void setRequiredMotor(int RPM) {
  RequiredSpeed = RPM;
}

void setMotor(int RPM) {
  if (RPM > RequiredSpeed) {
    TA0CCR1 -= 10;
  } else {
    TA0CCR1 += 10;
  }
}

