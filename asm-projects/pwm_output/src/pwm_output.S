#define __SFR_OFFSET 0x00
#include "avr/io.h"

.equ delay_count, 30
// На 5-ый pin подаётся шим-сигнал
.equ port_d, (1 << 5)
.equ pwm_max_value, 255
.equ pwm_serial_divider, 5

.section .data
.org 0x0100
pwm_value_adr: .space 1
is_decrement_flag_adr: .space 1

.section .text
.global onSetup
.global onLoop

onDelay:
    ldi r16, delay_count
    sts miliseconds_adr, r16
    rcall setupTimer
    rcall waitMilisecondsTimer
    ret

onSetup:
    ldi r16, 103
    sts uart_exchange_speed_adr, r16
    ldi r16, 0
    sts uart_exchange_speed_adr + 1, r16
    rcall setupSerialPrint

    ldi r16, port_d
    out DDRD, r16
    // Настройка ШИМ через установку битов в регистры таймера 0 TCCR0A и TCCR0B
    ldi r16, (1 << COM0B1) | (1 << WGM01) | (1 << WGM00)
    out TCCR0A, r16
    ldi r16, (1 << CS01) | (1 << CS00)
    out TCCR0B, r16

    ldi r16, 0
    sts pwm_value_adr, r16
    sts is_decrement_flag_adr, r16
    ret

onLoop:
    lds r16, pwm_value_adr
    out OCR0B, r16

    sts div_dividend_adr, r16
    ldi r17, pwm_serial_divider
    sts div_divider_adr, r17
    rcall executeDiv
    lds r17, mod_result_adr

    cpi r17, 0
    breq startPrintValue
    rjmp endPrintValue
startPrintValue:
    lds r16, pwm_value_adr
    sts value_for_serial_print_adrs, r16
    rcall serialPrintNumber
    ldi r17, '\n'
    sts value_for_serial_print_adrs, r17
    rcall serialPrintChar
endPrintValue:
    lds r16, pwm_value_adr
    lds r17, is_decrement_flag_adr

    cpi r17, 1
    breq decrementPwmValue
incrementPwmValue:
    inc r16
    rjmp doneCalculatePwmValue
decrementPwmValue:
    dec r16
    rjmp doneCalculatePwmValue
doneCalculatePwmValue:
    sts pwm_value_adr, r16

    cpi r16, pwm_max_value
    breq setDecrementFlag
    cpi r16, 0
    breq setIncrementFlag
    rjmp doneSetFlag
setDecrementFlag:
    ldi r17, 1
    sts is_decrement_flag_adr, r17
    rjmp doneSetFlag
setIncrementFlag:
    ldi r17, 0
    sts is_decrement_flag_adr, r17
    rjmp doneSetFlag
doneSetFlag:
    rcall onDelay
    ret