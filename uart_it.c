
#include<p18f2520.h>
#pragma config OSC = INTIO7
#pragma config PBADEN = OFF, WDT = OFF, LVP = OFF, DEBUG = ON

rom char message[] = "Entrer vitesse:";

volatile unsigned char i=0;

void HighISR(void);

#pragma code HighVector=0x08
void IntHighVector(void)
{
    _asm goto HighISR _endasm
}
#pragma code

#pragma interrupt HighISR 
void HighISR(void)
{
	if(PIR1bits.TXIF)			
	{						
	
		PIR1bits.TXIF = 0;	
    	if ( message[i] == '\0' ) PIE1bits.TXIE = 0;
		else TXREG = message[i];
		i++;
	}
}


void main(void) {

	OSCCONbits.IRCF0 = 0 ;
    OSCCONbits.IRCF1 = 1 ;
	OSCCONbits.IRCF2 = 1 ;

	
	BAUDCONbits.BRG16 = 1;
	TXSTAbits.BRGH = 1;
	TXSTAbits.SYNC = 0;
	SPBRGH = 0;
	SPBRG = 103;

	TRISCbits.RC6 = 1;
	RCSTAbits.SPEN = 1;
	TXSTAbits.TXEN = 1;


	PIE1bits.TXIE = 1;
	INTCONbits.GIE = 1;
	PIR1bits.TXIF = 0;
	INTCONbits.PEIE = 1;
	while (1) ;
}
	