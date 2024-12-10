#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
/*variables to hold the clock time*/
unsigned char sec, min,hour;
/*External INT0 Interrupt Service Routine*/
ISR(INT0_vect)
{
	sec=0;
    min=0;
    hour=0;
}
void int0_contr(void)
{
	DDRD &=~(1<<2); /*set direction of pin2 at port D as input pin*/
	PORTD |=(1<<2); /*enable internal pull up resistor*/
    GICR |=(1<<6); /*enable external Interrupt on pin INT0*/
    MCUCR =(1<<ISC01); /*Trigger INT0 with the falling edge*/
}
ISR(INT1_vect)
{
	/* Pause the stop watch by disable the timer
	Clear the timer clock bits (CS10=0 CS12=0) to stop the timer clock*/
	TCCR1B &=(1<<CS10) &(1<<CS12);
}
void int1_contr(void)
{
	DDRD &=~(1<<3); /* Configure INT1/PD3 as input pin*/
    GICR |=(1<<7); /* Enable external interrupt pin INT1*/
    MCUCR |=(1<<ISC11) |(1<<ISC10); /* Trigger INT1 with the raising edge*/
}
ISR(INT2_vect)
{
	/* resume the stop watch by enable the timer through the clock bits*/
	TCCR1B |= (1<<WGM12) |(1<<CS10) |(1<<CS12);
}
void int2_contr(void)
{
	/* Configure INT2/PB2 as input pin*/
	DDRB &=~(1<<2);
	/* enable the internal pull up resistor*/
	PORTB |=(1<<2);
	/* enable the external interrupt*/
    GICR |=(1<<5);
	/* trigger INT2 with the falling edge*/
    MCUCSR &=~(1<<ISC2);
}
ISR(TIMER1_COMPA_vect)
{
	sec++;
     if(sec==60)
     {
        	sec=0;
        	min++;
     }
     if(min==60)
     {
     	min=0;
     	hour++;
     }
     if(hour==24)
     {
     	sec=0;
        min=0;
        hour=0;
      }
}
void TIMER1_COMP(void)
{
	TCNT1=0; /*Initial value*/
	OCR1A = 1000; /*Compare value*/
	/* Configure timer1 control registers
	 * 1. Non PWM mode FOC1A=1 and FOC1B=1
	 * 2. No need for OC1A & OC1B in this example so COM1A0=0 & COM1A1=0 & COM1B0=0 & COM1B1=0
	 * 3. CTC Mode and compare value in OCR1A WGM10=0 & WGM11=0 & WGM12=1 & WGM13=0
	 */
	TCCR1A = (1<<FOC1A) |(1<<FOC1B) ;
	/*
	 * 4. Clock = F_CPU/1024 CS10=1 CS11=0 CS12=1
	 */
	TCCR1B = (1<<WGM12) |(1<<CS10) |(1<<CS12);
	/*enable compare interrupt for channel A*/
    TIMSK = (1<<OCIE1A);
}
void display(void)
{
	PORTA =(PORTA&0xC0)|(0x01);
	PORTC = (PORTC&0xF0) | (sec%10);
	_delay_ms(2);
	PORTA =(PORTA&0xC0)|(0x02);
	PORTC = (PORTC&0xF0) | (sec/10);
	_delay_ms(2);
	PORTA =(PORTA&0xC0)|(0x04);
	PORTC = (PORTC&0xF0) | (min%10);
	_delay_ms(2);
	PORTA =(PORTA&0xC0)|(0x08);
	PORTC = (PORTC&0xF0) | (min/10);
	_delay_ms(2);
	PORTA =(PORTA&0xC0)|(0x10);
	PORTC = (PORTC&0xF0) | (hour%10);
	_delay_ms(2);
	PORTA =(PORTA&0xC0)|(0x20);
	PORTC = (PORTC&0xF0) | (hour/10);
	_delay_ms(2);
}
int main(void)
{
	DDRC |= 0x0F;
	DDRA |= 0x3F;
	PORTC =0;
	/* Enable global interrupts in MC*/
	SREG |=(1<<7);
	/* Activate interrupts*/
	int0_contr();
	int1_contr();
	int2_contr();
	/* Start timer1 to generate compare interrupt every 1000 MiliSeconds(1 Second)*/
	TIMER1_COMP();
	while(1)
	{
		display();
	}
}


