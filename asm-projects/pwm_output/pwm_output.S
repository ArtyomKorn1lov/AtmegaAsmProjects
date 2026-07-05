#define __SFR_OFFSET 0x00
#include "avr/io.h"

.equ delay_count, 2
.equ element_count, 6

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

    ldi r30, lo8(list_adr)
    ldi r31, hi8(list_adr)
    ldi r16, 'h'
    st Z+, r16
    ldi r16, 'e'
    st Z+, r16
    ldi r16, 'l'
    st Z+, r16
    ldi r16, 'l'
    st Z+, r16
    ldi r16, 'o'
    st Z+, r16
    ldi r16, '\n'
    st Z+, r16
    ret

printItems:
    ld r16, Z
    sts char_for_serial_print_adrs, r16
    rcall serialPrintChar
    lds r16, counter_adr
    inc r16
    sts counter_adr, r16
    inc r30
    cpi r30, lo8(list_adr + element_count)
    brlo printItems
    ret

onLoop:
    ldi r30, lo8(list_adr)
    ldi r31, hi8(list_adr)
    ldi r16, 0
    sts counter_adr, r16
    rcall printItems
    rcall onDelay
    ret