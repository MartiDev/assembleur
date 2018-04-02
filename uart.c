
#include<p18f2520.h>
#include<stdio.h>

#pragma config OSC = INTIO7
#pragma config PBADEN = OFF, WDT = OFF, LVP = OFF, DEBUG = ON

rom char message[] = "Entrer vitesse:";

void main(void) {
unsigned char i=0;

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
	printf( "un essai \n");
	while (1) {
		TXREG = message[i];
		while ( !PIR1bits.TXIF );
		if ( message[i++] == '\0' ) while (1);
	}
	
	

		
}
	