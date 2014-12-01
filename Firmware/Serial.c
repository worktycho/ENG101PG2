
#include "Serial.h"

void setupUART() {
  // Based on benn thomsens example code
  P1SEL |= BIT1 | BIT2;
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
// Example usage: UARTSendChar('a');
 
while(!(IFG2 & UCA0TXIFG)); // Wait for TX buffer to be ready for new data
UCA0TXBUF = character; //Write the character at the location specified by the pointer and increment pointer
}
 
