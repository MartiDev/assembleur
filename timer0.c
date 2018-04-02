
#include<p18f2520.h>
#pragma config OSC = INTIO7
#pragma config PBADEN = OFF, WDT = OFF, LVP = OFF, DEBUG = ON

unsigned char led_test; 
volatile char  clignot;

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
	if(INTCONbits.TMR0IF)			
	{						
		INTCONbits.TMR0IF = 0;	
    	PORTBbits.RB5 = ~PORTBbits.RB5;
		TMR0H = 0xC2; 
		TMR0L = 0xF6;	
	}
}



void main(void) {

	OSCCONbits.IRCF0 = 0 ;
    OSCCONbits.IRCF1 = 1 ;
	OSCCONbits.IRCF2 = 1 ;
	TRISAbits.RA6 = 0;
	TRISBbits.RB0=1;	
	TRISBbits.RB5=0;
	T0CONbits.T08BIT = 0;
	T0CONbits.T0CS = 0;
	T0CONbits.T0PS2 = 1;
	T0CONbits.T0PS1 = 0;
	T0CONbits.T0PS0 = 1;
	T0CONbits.PSA = 0;
	TMR0H = 0xC2; 
	TMR0L = 0xF6;
	T0CONbits.TMR0ON = 1;
	INTCONbits.TMR0IE = 1;
	INTCONbits.PEIE = 1;
	INTCONbits.GIE = 1;
	while(1) {
	}
}		


	