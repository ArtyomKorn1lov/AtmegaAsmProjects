#define __SFR_OFFSET 0x00
#include "avr/io.h"

.global start
.global led

start:
    SBI DDRB, 4
    RCALL setupTimer
    RET

/*
Инициализации аппаратного таймера, с помощью R16 будет определяться валидно ли значение счётчика
Установленное значение таймера 3 сек., т. е.
1 сек. эквивалентна 15624
3 сек. 46872, в hex 0xB718
старший байт помещаем в OCR1AH
младший байт помещаем в OCR1AL
*/
setupTimer:
    CLR R16
    STS TCCR1A, R16
    LDI R16, 0xB7
    STS OCR1AH, R16
    LDI R16, 0x18
    STS OCR1AL, R16
    LDI R16, (1 << WGM12) | (1 << CS12) | (1 << CS10)
    STS TCCR1B, R16
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

/*
Запуск
*/
waitTimer:
    IN R16, TIFR1
    SBRS R16, OCF1A
    RJMP waitTimer
    LDI R16, (1 << OCF1A)
    OUT TIFR1, R16
    RET