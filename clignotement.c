
#include<p18f2520.h>
#pragma config OSC = INTIO7
#pragma config PBADEN = OFF, WDT = OFF, LVP = OFF, DEBUG = ON

unsigned char led_test; 

void main(void) {
 unsigned long i,N;

	OSCCONbits.IRCF0 = 0 ;
    OSCCONbits.IRCF1 = 1 ;
	OSCCONbits.IRCF2 = 1 ;
	TRISAbits.RA6 = 0;
	TRISBbits.RB0=1;	
	TRISBbits.RB5=0;	
	while(1) {
		PORTBbits.RB5 = ~PORTBbits.RB5;
		if (PORTBbits.RB0 ) {
			N = 20000;
		}
		else {
			N = 40000;
		}

		for ( i=N; i!=0; i-- );
	}		

}
	