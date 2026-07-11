#define __SFR_OFFSET 0x00
#include "avr/io.h"

// Программа реализующая вывод значения однобайтовой переменной в монитор порта, через протокол UART

.global uart_exchange_speed_adr
.global value_for_serial_print_adrs
.global setupSerialPrint
.global serialPrintChar
.global serialPrintDigit
.global serialPrintNumber

// Делители для извлечения цифр из 1-байтового числа
.equ digitFirstDivider, 100
.equ digitSecondDivider, 10
.equ digitLastDivider, 1
// ! Делители для извлечения цифр из 1-байтового числа
// Ascii код нуля
.equ zeroAsciiCode, 48


.section .data
// Адрес в памяти, в котором находится числовое значение для установки скорости обмена данными в UART
// Пример:
// Если скорость обмена 9600 бод, то значение скорости вычиляется U(обмена) = m(частота работы процессора в герцах, 16 Мг)/(16 * 9600) - 1 = 103
uart_exchange_speed_adr: .space 2
// Адрес памяти, в котором находится значение, которое нужно вывести
value_for_serial_print_adrs: .space 1

.section .text

// Настройка обмена UART
setupSerialPrint:
    // Установка значения скорости обмена в регистр UART UBRR0
    lds r16, uart_exchange_speed_adr
    sts UBRR0L, r16
    lds r16, uart_exchange_speed_adr + 1
    sts UBRR0H, r16

    // Установка флага разрешения передачи в регистр UCSR0B
    ldi r16, (1 << TXEN0)
    sts UCSR0B, r16

    // Установка размера кадра для UART в регистр UCSR0C, т. е. число 11 для битов UCSZ01 и UCSZ00, это значит что размер кадра 1 байт
    ldi r16, (1 << UCSZ01) | (1 << UCSZ00)
    sts UCSR0C, r16
    ret

// Вывод в мониторе порта 1 байтового значения с помощью UART
serialPrintChar:
    // Получение текущего состояния отправки значения из регистра UCSR0A
    lds r16, UCSR0A
    // Если бит в регистре, соотвествующий биту UDRE0, не установлен в UCSR0A, повторяем цикл
    sbrs r16, UDRE0
    rjmp serialPrintChar
    lds r16, value_for_serial_print_adrs
    // В регистр UDR0 устанавливается однобайтовое значение
    sts UDR0, r16
    ret

// Печать цифры от 0 до 9
serialPrintDigit:
    lds r16, value_for_serial_print_adrs
    // Чтобы корректно вывести число, нужно через таблицу ASCII прибавить код нуля к числу, тогда будет осущствлён сдвиг до нужной цифры
    subi r16, -zeroAsciiCode
    sts value_for_serial_print_adrs, r16
    rcall serialPrintChar
    ret

// Печать однобайтового числа (от 0 до 255)
serialPrintNumber:
    // Целочисленное деление на 100, получаемую цифру печатаем
    lds r16, value_for_serial_print_adrs
    ldi r17, digitFirstDivider
    sts div_dividend_adr, r16
    sts div_divider_adr, r17
    rcall executeDiv
    lds r16, div_result_adr
    sts value_for_serial_print_adrs, r16
    rcall serialPrintDigit

    // Целочисленное деление на 10, получаемую цифру печатаем
    lds r16, mod_result_adr
    ldi r17, digitSecondDivider
    sts div_dividend_adr, r16
    sts div_divider_adr, r17
    rcall executeDiv
    lds r16, div_result_adr
    sts value_for_serial_print_adrs, r16
    rcall serialPrintDigit

    // Целочисленное деление на 1, получаемую цифру печатаем
    lds r16, mod_result_adr
    ldi r17, digitLastDivider
    sts div_dividend_adr, r16
    sts div_divider_adr, r17
    rcall executeDiv
    lds r16, div_result_adr
    sts value_for_serial_print_adrs, r16
    rcall serialPrintDigit

    ret