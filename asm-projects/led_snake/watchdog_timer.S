#define __SFR_OFFSET 0x00
#include "avr/io.h"

.text
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
    clr r16
    sts TCCR1A, r16
    mov r16, r17
    sts OCR1AH, r16
    mov r16, r18
    sts OCR1AL, r16
    ldi r16, (1 << WGM12) | (1 << CS12) | (1 << CS10)
    sts TCCR1B, r16
    clr r17
    clr r18
    clr r16
    ret

/*  
Ожидание срабатывания таймера
*/
waitTimer:
    clr r16
    in r16, TIFR1
    sbrs r16, OCF1A
    rjmp waitTimer
    ldi r16, (1 << OCF1A)
    out TIFR1, r16
    clr r16
    ret