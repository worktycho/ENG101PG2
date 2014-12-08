
#include "msp430g2553.h"
#include "Serial.h"

void setupUART() {
  // Based on benn thomsens example code
  P1SEL = BIT1 + BIT2;
  P1SEL2 |= BIT1 | BIT2;
  UCA0CTL1 |= UCSSEL_2;
  UCA0BR0 = 104; 
  UCA0BR1 = 0;
  UCA0MCTL = UCBRS0;
  UCA0CTL1 &= ~UCSWRST;
  IE2 |= UCA0RXIE; 
}

void writeCharUART(unsigned char character){
  // Send a single byte using the hardware UART 0
  while(!(IFG2 & UCA0TXIFG)); // Wait for TX buffer to be ready for new data
  UCA0TXBUF = character; //Write the character at the location specified by the pointer and increment pointer
}


void writeIntUART(int value) {
  int position = 1;
  while ((value / position) >= 10) position *= 10;
  while (position > 0) {
    int column = value / position;
    if (column > 9) writeCharUART('@');
    if (column < 0) writeCharUART('$');
    writeCharUART('0' + column);
    value -= column * position;
    position /= 10;
  }
}


