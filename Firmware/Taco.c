
#include "Taco.h"
#include "msp430g2553.h"

volatile int pulseCount;
volatile int pulseCountsPerTimer;

void setupRotation() {
  pulseCount = 0;
  
  //setup counter interrupt
  P2DIR &= ~BIT_ROTATION; //Set as input
  
  P2IE |= BIT_ROTATION;
  P2IES |= BIT_ROTATION;
  
  //setup timer
  TA1CTL = TASSEL_2 + MC_1 + ID_1; // SMCLK as input clock, count up to TA0CCR0, clock/2
  TA1CCR0 = 50000; // Set maximum count value to determine count frequency = SMCLK/ClockDivide/TACCR0 (1MHz/2/40000 = 12.5Hz)
  TA1CCTL0 = OUTMOD_0 + CCIE; // Set out mode 0, enable CCR0 interrupt
}

int readRotation() {
  return pulseCountsPerTimer;
}

int calibrateRPM(int RawRotationCount) {
  return (int)(RawRotationCount * ROTATION_SCALE) + ROTATION_OFFSET;
}

void outputRPM(int RPM) {
  writeCharUART('R');
  writeCharUART(':');
  writeIntUART(RPM);
  writeCharUART('\n');
}

#pragma vector=PORT2_VECTOR
__interrupt void PORT2_ISR (void)
{
  if (!(P2IFG & BIT_ROTATION)) return
  pulseCount++;
}

#pragma vector=TIMER1_A0_VECTOR
__interrupt void Timer1_A0_ISR (void)
{
  pulseCountsPerTimer = pulseCount;
  pulseCount = 0;
}
