
#include<p18f2520.h>
#pragma config OSC = INTIO67
#pragma config PBADEN = OFF, WDT = OFF, LVP = OFF, DEBUG = ON

void main(void) {

	OSCCONbits.IRCF0 = 0 ;
        OSCCONbits.IRCF1 = 1 ;
	OSCCONbits.IRCF2 = 1 ;
	TRISAbits.RA6 = 0;
	TRISBbits.RB0=1;	
	TRISBbits.RB5=0;
	TRISCbits.RC1 = 0;
	TRISCbits.RC2 = 0;
	T2CONbits.T2CKPS0 = 1;
	T2CONbits.T2CKPS1 = 0;
	PR2 = 124;
	CCPR1L = 0x19;
	CCPR2L = 0x19;
	CCP1CONbits.DC1B0 = 0;
	CCP1CONbits.DC1B1 = 0;
	CCP2CONbits.DC2B0 = 0;
	CCP2CONbits.DC2B1 = 0;
	CCP1CONbits.CCP1M3 = 1;
	CCP1CONbits.CCP1M2 = 1;
	CCP2CONbits.CCP2M3 = 1;
	CCP2CONbits.CCP2M2 = 1;
	T2CONbits.TMR2ON = 1;
	while(1) {
	}
}		


	