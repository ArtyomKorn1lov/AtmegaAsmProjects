#define __SFR_OFFSET 0x00
#include "avr/io.h"

.global onSetup
.global onLoop

onSetup:
    LDI R16, 0xD4
    OUT DDRD, R16
    LDI R16, 0x2B
    OUT DDRB, R16
    LDI R17, 0x3D
    LDI R18, 0x08
    RCALL setupTimer
    RET

onLoop:
    CLR R17
    CLR R18
    SBI PORTD, 2
    RCALL waitTimer
    CBI PORTD, 2
    SBI PORTD, 4
    RCALL waitTimer
    CBI PORTD, 4
    SBI PORTD, 6
    RCALL waitTimer
    CBI PORTD, 6
    SBI PORTD, 7
    RCALL waitTimer
    CBI PORTD, 7
    SBI PORTB, 0
    RCALL waitTimer
    CBI PORTB, 0
    SBI PORTB, 1
    RCALL waitTimer
    CBI PORTB, 1
    SBI PORTB, 3
    RCALL waitTimer
    CBI PORTB, 3
    SBI PORTB, 5
    RCALL waitTimer
    CBI PORTB, 5
    RET