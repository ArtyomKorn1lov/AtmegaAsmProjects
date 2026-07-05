#define __SFR_OFFSET 0x00
#include "avr/io.h"

// Программа реализующая вывод значения однобайтовой переменной в монитор порта, через протокол UART

.global uart_exchange_speed_adr
.global char_for_serial_print_adrs
.global setupSerialPrint
.global serialPrintChar

.section .data
.org 0x0100
// Адрес в памяти, в котором находится числовое значение для установки скорости обмена данными в UART
// Пример:
// Если скорость обмена 9600 бод, то значение скорости вычиляется U(обмена) = m(частота работы процессора в герцах, 16 Мг)/(16 * 9600) - 1 = 103
uart_exchange_speed_adr: .space 2
// Адрес памяти, в котором находится значение, которое нужно вывести
char_for_serial_print_adrs: .space 1

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
    lds r16, char_for_serial_print_adrs
    // В регистр UDR0 устанавливается однобайтовое значение
    sts UDR0, r16
    ret