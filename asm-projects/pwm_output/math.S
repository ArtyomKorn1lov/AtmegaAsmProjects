#define __SFR_OFFSET 0x00
#include "avr/io.h"

// Математические операции

.global div_dividend_adr
.global div_divider_adr
.global div_result_adr
.global mod_result_adr
.global executeDiv

// Количество бит в 1 байтовом числе
.equ byteDigitBitCount, 8

.section .data
div_dividend_adr: .space 1
div_divider_adr: .space 1
div_result_adr: .space 1
mod_result_adr: .space 1

.section .text

// Извлекаем n-ый бит из делимого, записываем в r22
extractBitFromDividend:
    mov r23, r16
    mov r24, r21
extractBitLoop:
    cpi r24, 0
    breq extractBitDone
    lsr r23
    dec r24
    rjmp extractBitLoop
extractBitDone:
    andi r23, 1
    mov r22, r23
    ret

executeDiv:
    // Делимое
    lds r16, div_dividend_adr
    // Делитель
    lds r17, div_divider_adr
    // Частное
    clr r18
    // Остаток
    clr r19
    // Счётчик для цикла
    clr r20
    // Сюда будет извлекаться номер текущего бита делимого
    ldi r21, byteDigitBitCount
    // Активный бит из делимого
    clr r22
divLoop:
    lsl r18

    dec r21
    rcall extractBitFromDividend
    lsl r19
    or r19, r22

    cp r19, r17
    brlo divDone

    sub r19, r17
    inc r18
divDone:
    inc r20
    cpi r20, byteDigitBitCount
    brlo divLoop
    sts div_result_adr, r18
    sts mod_result_adr, r19
    ret