
#include<p18f2520.h>
#pragma config OSC = INTIO7
#pragma config PBADEN = OFF, WDT = OFF, LVP = OFF, DEBUG = ON

unsigned char led_test; 

void main(void) {

	OSCCONbits.IRCF0 = 0 ;
    OSCCONbits.IRCF1 = 1 ;
	OSCCONbits.IRCF2 = 1 ;
	TRISAbits.RA6 = 0;
	TRISBbits.RB0=1;	
	TRISBbits.RB5=0;	
	while(1) {
		if (PORTBbits.RB0 ) {
			PORTBbits.RB5=1;
			led_test = 1;
		}
		else {
			PORTBbits.RB5=0;
			led_test = 0;
		}
	}		
}
	