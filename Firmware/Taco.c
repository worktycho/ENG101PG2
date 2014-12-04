
volatile int pulseCount;

void setupRotation() {
  pulseCount = 0;
  
  P2DIR &= ~BIT_ROTATION; //Set as input
  
  P2IE |= BIT_ROTATION;
  P2IES |= BIT_ROTATION;
}

#pragma vector=PORT2_VECTOR
__interrupt void PORT2_ISR (void)
{
  if (!(P2IEG & BIT_ROTATION)) return
  pulseCount++;
}
