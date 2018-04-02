
#include<p18f2520.h>
#pragma config OSC = INTIO7
#pragma config PBADEN = OFF, WDT = OFF, LVP = OFF, DEBUG = ON

unsigned char led_test; 

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
	if(INTCONbits.INT0IF)			
	{						
		INTCONbits.INT0IF = 0;	
    	PORTBbits.RB5 = ~PORTBbits.RB5;
	}
}



void main(void) {

	OSCCONbits.IRCF0 = 0 ;
    OSCCONbits.IRCF1 = 1 ;
	OSCCONbits.IRCF2 = 1 ;
	TRISAbits.RA6 = 0;
	TRISBbits.RB0=1;	
	TRISBbits.RB5=0;	
	INTCON2bits.INTEDG0 = 0;
	INTCONbits.INT0IE = 1;
	INTCONbits.PEIE = 1;
	INTCONbits.GIE = 1;
	while(1) {
	
	}		

}
	