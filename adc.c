
#include<p18f2520.h>
#pragma config OSC = INTIO7
#pragma config PBADEN = OFF, WDT = OFF, LVP = OFF, DEBUG = ON

unsigned char led_test; 

void main(void) {
unsigned char UBAT;

	OSCCONbits.IRCF0 = 0 ;
    OSCCONbits.IRCF1 = 1 ;
	OSCCONbits.IRCF2 = 1 ;
	
	TRISBbits.RB5 = 0;

	ADCON1bits.PCFG0 = 0;
	ADCON1bits.PCFG1 = 0;
	ADCON1bits.PCFG2 = 1;
	ADCON1bits.PCFG3 = 1;

	ADCON1bits.VCFG0 = 0;
	ADCON1bits.VCFG1 = 0;

	ADCON2bits.ADCS0 = 0;
	ADCON2bits.ADCS1 = 0;
	ADCON2bits.ADCS2 = 1;

	ADCON2bits.ACQT0 = 0;
	ADCON2bits.ACQT1 = 1;
	ADCON2bits.ACQT2 = 0;

	ADCON0bits.CHS0 = 0;
	ADCON0bits.CHS1 = 1;
	ADCON0bits.CHS2 = 0;
	ADCON0bits.CHS3 = 0;

	ADCON2bits.ADFM = 0;

	ADCON0bits.ADON = 1;
	while ( 1 ) {
		ADCON0bits.GO = 1;
		while ( ADCON0bits.DONE );
		UBAT = ADRESH;
		if ( UBAT < 159 ) PORTBbits.RB5 = 1;
		else PORTBbits.RB5 = 0;
	}
		
}
	