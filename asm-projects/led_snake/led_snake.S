#define __SFR_OFFSET 0x00 // Это необходимо, так как по умолчанию все адреса регистров ввода-вывода определяются как адреса памяти (используются в инструкциях lds/sts). Чтобы использовать эти адреса в инструкциях in/out, из них нужно вычесть 0x20. 
#include "avr/io.h"

// В avr-gcc при создании констант не используется запись вида .equ const1 = 1, вместо этого .equ const1, 1
.equ start_timer_duration, 0x3D
.equ end_timer_duration, 0x08
.equ port_b, 0x2B
.equ port_d, 0xD4
.equ port_b_count, 4

// Указываем сегмент данных, с какого адреса он начинается, в avr-gcc нет `.dseg`, если работаем с сегментом данных указываем `.section .data`
.section .data
.org 0x0100
// В avr-gcc `.byte` работает не так как в старом компиляторе, она просто резервирует 1 байт в программе
// Для операции по n-ому резервированию байтов в памяти нужно применить директиву `.space` или `.skip`
led_list_adr: .space 8
counter_adr: .space 1

// Указываем сегмент программного кода, в avr-gcc не существует `.cseg`, вместо него используется директива `.text`
.text
.global onSetup
.global onLoop

// В r30 записываем 0x00, в r31 записываем 0x01, итого в виртуальном регистре Z = 0x0100
// Адрес начада списка для значений пинов в ОЗУ
setupLedListAdr:
    // В avr-gcc функции low и high заменены на lo8 и hi8
    ldi r30, lo8(led_list_adr)
    ldi r31, hi8(led_list_adr)
    ret

// Инкапсуляция логики записи списка в память с перемещением на следующий адрес (максимум 256 элементов)
pushValueInLedList:
    st Z, r16
    inc r30
    ret

// Сброс по адресу counter_adr до значения 0
resetCounter:
    ldi r16, 0
    sts counter_adr, r16
    ret

// Инициализация списка со значениями для пинов
initLedList:
    rcall setupLedListAdr

    // Запись чисел в список
    // Сначало которые установятся в portD
    ldi r16, 0x04
    rcall pushValueInLedList
    ldi r16, 0x10
    rcall pushValueInLedList
    ldi r16, 0x40
    rcall pushValueInLedList
    ldi r16, 0x80
    rcall pushValueInLedList
    // Затем которые установятся в portB
    ldi r16, 0x01
    rcall pushValueInLedList
    ldi r16, 0x02
    rcall pushValueInLedList
    ldi r16, 0x08
    rcall pushValueInLedList
    ldi r16, 0x20
    rcall pushValueInLedList

    // Очистка регистра Z
    clr r30
    clr r31

    // Установка по адресу counter_adr значения счётчика списка
    rcall resetCounter
    ret

// Вывод значения в PORTB
outPortB:
    ld r16, Z
    out PORTB, r16
    ldi r16, 0x00
    out PORTD, r16
    ret

// Вывод значения в PORTD
outPortD:
    ld r16, Z
    out PORTD, r16 
    ldi r16, 0x00
    out PORTB, r16
    ret

// Цикл вывода элементов списка led_list в portD или portD в зависимости от значений списка
showValueFromLedList:
    // Получить значение счётчика из ОЗУ, сравнить его с константой, если счётчик >= port_b_count, значит значение выводится в portB, иначе значение выводится в portD
    lds r16, counter_adr
    cpi r16, port_b_count
    brsh callOutPortB
    rcall outPortD
    rjmp continueShowValueFromLedList
// Команда brsh не умеет сохранять в указатель стека место, откуда была вызвана функция, поэтому создадим функцию перенаправления для этого
callOutPortB:
    rcall outPortB
continueShowValueFromLedList:
    // Ожидание ~1 сек
    rcall waitTimer

    // Инкрементирование счётчика и инкрементирование указателя на элемент списка led_list
    lds r16, counter_adr
    inc r16
    sts counter_adr, r16
    inc r30

    // Если указатель не вышел за пределы размеров списка led_list, повторяем цикл, иначе выходим из цикла
    cpi r30, lo8(led_list_adr + 8)
    brlo showValueFromLedList

    // Сброс счётчика, для последующего выполнения операции
    rcall resetCounter
    ret

// Функция настройки портов и таймера
onSetup:
    // Инициализация указателя стека, в текущей программе, т. к. это гибрид ассемблера и си, этого делать не нужно, в ином случае необходимо сделать, для демонстрации этот код тут останется
    /*
        ldi r16, lo8(RAMEND)
        out SPL, r16
        ldi r16, hi8(RAMEND)
        out SPH, r16
    */

    // Установка задержки при вызове таймера ~1 сек
    ldi r17, start_timer_duration
    ldi r18, end_timer_duration
    rcall setupTimer
    clr r17
    clr r18

    // Инициализация пинов на выход
    ldi r16, port_b
    out DDRB, r16
    ldi r16, port_d
    out DDRD, r16
    clr r16

    // Инициализация значений led_list_adr
    rcall initLedList
    ret

// Основная функция с бесконечным циклом программы
onLoop: 
    rcall setupLedListAdr
    rcall showValueFromLedList
    jmp onLoop