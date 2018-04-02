
#include<p18f2520.h>
#include<stdio.h>

#pragma config OSC = INTIO67
#pragma config PBADEN = OFF, WDT = OFF, LVP = OFF, DEBUG = ON

char result;

void main(void) {

	OSCCONbits.IRCF0 = 0 ;
        OSCCONbits.IRCF1 = 1 ;
	OSCCONbits.IRCF2 = 1 ;

	TRISCbits.RC3 = 1;
	TRISCbits.RC3 = 1;
	SSPCON1bits.SSPEN = 1;
	SSPCON1bits.SSPM3 = 1;
	SSPCON1bits.SSPM2 = 0;
	SSPCON1bits.SSPM1 = 0;
	SSPCON1bits.SSPM0 = 0;
	SSPSTATbits.SMP = 1;
	SSPADD = 9;

      
	SSPCON2bits.SEN = 1;
	while (! PIR1bits.SSPIF ) ;
        PIR1bits.SSPIF = 0;
	SSPBUF = 0x40;
	while (! PIR1bits.SSPIF ) ;
        PIR1bits.SSPIF = 0;
	while ( SSPCON2bits.ACKSTAT );
    
	SSPBUF = 0x55;
	while (! PIR1bits.SSPIF ) ;
        PIR1bits.SSPIF = 0;
	while ( SSPCON2bits.ACKSTAT );

     
	SSPCON2bits.PEN = 1;
        while (! PIR1bits.SSPIF ) ;
        PIR1bits.SSPIF = 0;

        SSPCON2bits.SEN = 1;
	while (! PIR1bits.SSPIF ) ;
        PIR1bits.SSPIF = 0;
	SSPBUF = 0xE0;
	while (! PIR1bits.SSPIF ) ;
        PIR1bits.SSPIF = 0;
	while ( SSPCON2bits.ACKSTAT );

	SSPBUF = 0x51;                //correspond à commande mesure sonar en cm
	while (! PIR1bits.SSPIF ) ;
        PIR1bits.SSPIF = 0;
	while ( SSPCON2bits.ACKSTAT );


	SSPCON2bits.PEN = 1;
        while (! PIR1bits.SSPIF ) ;
        PIR1bits.SSPIF = 0;

// attente 70 ms
        	
	SSPCON2bits.SEN=1;        // initiate START condition
	while (! PIR1bits.SSPIF ) ;
        PIR1bits.SSPIF = 0;

  	SSPBUF = 0xE0 +1;		// Envoi adresse
	while (! PIR1bits.SSPIF ) ;
        PIR1bits.SSPIF = 0;
	while(SSPCON2bits.ACKSTAT);	//Attente ACK slave

	 SSPCON2bits.RCEN=1;        // SSPBUF en reception
	while (! PIR1bits.SSPIF ) ;
        PIR1bits.SSPIF = 0;
	result = SSPBUF;		// Ecrit octet

	 SSPCON2bits.ACKDT=1;        // initiate NoACK
	 SSPCON2bits.ACKEN=1;
	 while(SSPCON2bits.ACKEN);	// Attendre fin ACKEN
        while (! PIR1bits.SSPIF ) ;
        PIR1bits.SSPIF = 0;

		
    	SSPCON2bits.PEN=1;                  // send STOP condition
    	while (! PIR1bits.SSPIF ) ;
        PIR1bits.SSPIF = 0;

        while ( 1 );

  
}
	
	
	