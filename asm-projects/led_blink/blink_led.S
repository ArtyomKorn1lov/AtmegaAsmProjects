#define __SFR_OFFSET 0x00
#include "avr/io.h"

.global start
.global led

start:
    SBI DDRB, 4
    RCALL setupTimer
    RET

led:
    CPI R24, 0x00
    BREQ ledOFF 
    SBI PORTB, 4 
    RCALL waitTimer
    RET

ledOFF:
    CBI PORTB, 4
    RCALL waitTimer
    RET