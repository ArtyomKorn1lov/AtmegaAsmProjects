#define __SFR_OFFSET 0x00 // Это необходимо, так как по умолчанию все адреса регистров ввода-вывода определяются как адреса памяти (используются в инструкциях lds/sts). Чтобы использовать эти адреса в инструкциях in/out, из них нужно вычесть 0x20. 
#include "avr/io.h"

// В avr-gcc при создании констант не используется запись вида .equ const1 = 1, вместо этого .equ const1, 1
.equ delay_count, 1 // Время задержки в сек.
.equ port_b, 0x2B // Настройка вывода для регистра PORTB
.equ port_d, 0xD4 // Настройка вывода для регистра PORTD
.equ led_list_items_count, 8 // Количество элементов для списка пинов
.equ frequency_list_items_count, 16 // Количество элементов для списка частот, величина частоты > 255, 1 элемент равен 2 байта, тк ячейка памяти 1 байт, поэтому количество элементов 8*2=16
.equ port_b_count, led_list_items_count / 2 // Значение счётчика, где нужно выводить значение вместо PORTD на PORTB

// Указываем сегмент данных, с какого адреса он начинается, в avr-gcc нет `.dseg`, если работаем с сегментом данных указываем `.section .data`
.section .data
.org 0x0100
// В avr-gcc `.byte` работает не так как в старом компиляторе, она просто резервирует 1 байт в программе
// Для операции по n-ому резервированию байтов в памяти нужно применить директиву `.space` или `.skip`
led_list_adr: .space led_list_items_count
frequency_list_adr: .space frequency_list_items_count
counter_adr: .space 1

// Указываем сегмент программного кода, в avr-gcc не существует `.cseg`, вместо него используется директива `.text`
.section .text
.global onSetup
.global onLoop

// Задержка
onDelay:
    ldi r17, delay_count
    rcall setupTimer
    rcall waitTimer
    ret

// Пример: в r30 записываем 0x00, в r31 записываем 0x01, итого в виртуальном регистре Z = 0x0100
// Адрес начада списка для значений пинов в ОЗУ
setupLedListAdr:
    // В avr-gcc функции low и high заменены на lo8 и hi8
    ldi r30, lo8(led_list_adr)
    ldi r31, hi8(led_list_adr)
    ret

// Адрес начада списка для значений частоты в ОЗУ
setupFrequencyAdr:
    ldi r28, lo8(frequency_list_adr)
    ldi r29, hi8(frequency_list_adr)
    ret

// Запись значения списка с пинами в память с перемещением на следующий адрес (максимум 256 элементов)
pushValueInLedList:
    st Z+, r16
    ret

// Запись значения частоты (2-байтовое число) в память с перемещением на следующий адрес (максимум 128 элементов)
pushValueInFrequencyList:
    st Y+, r16
    st Y+, r17
    ret

// Сброс по адресу counter_adr до значения 0
resetCounter:
    ldi r16, 0
    sts counter_adr, r16
    ret

// Инициализация списка со значениями для пинов, списка со значениями звуковых частот и счётчика для перебора списков
onInit:
    // Запись чисел с конфигурацией портов в список
    // Сначало которые установятся в portD
    rcall setupLedListAdr
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

    // Запись чисел с частотой звукого сигнала в список
    rcall setupFrequencyAdr
    ldi r16, 0x01
    ldi r17, 0xDD
    rcall pushValueInFrequencyList
    ldi r16, 0x01
    ldi r17, 0xC2
    rcall pushValueInFrequencyList
    ldi r16, 0x01
    ldi r17, 0xA9
    rcall pushValueInFrequencyList
    ldi r16, 0x01
    ldi r17, 0x7B
    rcall pushValueInFrequencyList
    ldi r16, 0x01
    ldi r17, 0x65
    rcall pushValueInFrequencyList
    ldi r16, 0x01
    ldi r17, 0x3D
    rcall pushValueInFrequencyList
    ldi r16, 0x01
    ldi r17, 0x1B
    rcall pushValueInFrequencyList
    ldi r16, 0x00
    ldi r17, 0xFD
    rcall pushValueInFrequencyList

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
    // Запуск звукого сигнала на tone_pin
    ld r17, Y
    ldd r18, Y+1
    rcall startTone

    // Ожидание delay_count сек
    rcall onDelay

    // Остановка звукового сигнала на tone_pin
    rcall stopTone

    // Инкрементирование счётчика и инкрементирование указателя на элемент списка led_list
    lds r16, counter_adr
    inc r16
    sts counter_adr, r16
    inc r30
    adiw r28, 2

    // Если указатель не вышел за пределы размеров списка led_list, повторяем цикл, иначе выходим из цикла
    cpi r30, lo8(led_list_adr + led_list_items_count)
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

    // Инициализация пинов на выход
    ldi r16, port_b
    out DDRB, r16
    ldi r16, port_d
    out DDRD, r16

    // Инициализация значений led_list, frequency_list и counter
    rcall onInit
    ret

// Основная функция с бесконечным циклом программы
onLoop: 
    rcall setupLedListAdr
    rcall setupFrequencyAdr
    rcall showValueFromLedList
    jmp onLoop