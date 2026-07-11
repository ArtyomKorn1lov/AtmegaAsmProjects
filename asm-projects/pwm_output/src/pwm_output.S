#define __SFR_OFFSET 0x00
#include "avr/io.h"

.equ delay_count, 2
.equ element_count, 6
// На 5-ый pin подаётся шим-сигнал
.equ port_d, (1 << 5)

.section .data
.org 0x0100
list_adr: .space element_count
counter_adr: .space 1

.section .text
.global onSetup
.global onLoop

onDelay:
    ldi r16, delay_count
    sts seconds_count_adr, r16
    rcall setupTimer
    rcall waitTimer
    ret

onSetup:
    ldi r16, 103
    sts uart_exchange_speed_adr, r16
    ldi r16, 0
    sts uart_exchange_speed_adr + 1, r16
    rcall setupSerialPrint

    ldi r16, port_d
    out DDRD, r16
    ldi r16, (1 << COM0B1) | (1 << WGM01) | (1 << WGM00)
    out TCCR0A, r16
    ldi r16, (1 << CS01) | (1 << CS00)
    out TCCR0B, r16
    ret

onLoop:
    ldi r16, 110
    out OCR0B, r16

    sts value_for_serial_print_adrs, r16
    rcall serialPrintNumber
    ldi r17, '\n'
    sts value_for_serial_print_adrs, r17
    rcall serialPrintChar
    
    rcall onDelay
    ret