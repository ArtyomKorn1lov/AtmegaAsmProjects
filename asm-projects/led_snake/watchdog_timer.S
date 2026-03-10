#define __SFR_OFFSET 0x00
#include "avr/io.h"

.global setupTimer
.global waitTimer

/*
Входные параметры:
Таймер оперирует 2-байтовым числом, максимальное число для установки в таймер - 65535 ~4,19 секунды
Считывание данных осуществляется с R17 и R18
Инициализации аппаратного таймера, с помощью R16 будет определяться валидно ли значение счётчика
Справочная информация по времени задержки таймера:
- 1 сек. эквивалентна 15624, в hex 0x3D08 
- 3 сек. 46872, в hex 0xB718
старший байт помещаем в OCR1AH
младший байт помещаем в OCR1AL
*/
setupTimer:
    CLR R16
    STS TCCR1A, R16
    MOV R16, R17
    STS OCR1AH, R16
    MOV R16, R18
    STS OCR1AL, R16
    LDI R16, (1 << WGM12) | (1 << CS12) | (1 << CS10)
    STS TCCR1B, R16
    RET

/*  
Ожидание срабатывания таймера
*/
waitTimer:
    IN R16, TIFR1
    SBRS R16, OCF1A
    RJMP waitTimer
    LDI R16, (1 << OCF1A)
    OUT TIFR1, R16
    RET