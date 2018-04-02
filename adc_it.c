
#include<p18f2520.h>
#pragma config OSC = INTIO7
#pragma config PBADEN = OFF, WDT = OFF, LVP = OFF, DEBUG = ON

void HighISR(void);
volatile unsigned char UBAT = 255;

#pragma code HighVector=0x08
void IntHighVector(void)
{
    _asm goto HighISR _endasm
}
#pragma code

#pragma interrupt HighISR 
void HighISR(void)
{
   if(PIR1bits.ADIF)         
   {                  
      PIR1bits.ADIF = 0;   
       UBAT = ADRESH;
       ADCON0bits.GO = 1;
   }
}

void main(void) {


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
   
   PIR1bits.ADIF = 0;
   PIE1bits.ADIE = 1;
   INTCONbits.GIE = 1;
   INTCONbits.PEIE = 1;
   ADCON0bits.GO = 1;
   while ( 1 ) {
      
      if ( UBAT < 159 ) PORTBbits.RB5 = 1;
      else PORTBbits.RB5 = 0;
   }
      
}
   
