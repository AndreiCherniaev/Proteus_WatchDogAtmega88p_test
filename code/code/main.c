//F_CPU=8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>

int main(void){
	_delay_ms(1000);
	DDRB|= (1<<PB0);
	PORTB|=(1<<PB0); //LED on
	
	wdt_enable(WDTO_2S);
	/* Reset WDT */
	//wdt_enable(WDTO_2S); //1)if you just enable again then watchdog will disabled forever
	//asm( "WDR"); //2)if you try reset watchdog once then watchdog will disabled forever
	//wdt_reset(); //3)if you try reset watchdog once then watchdog will disabled forever
	//4)even if you enable watchdog in fuse in Proteus you can disable it using 1) or 2) or 3)
	while(1){
		_delay_ms(1000);
	}
}
