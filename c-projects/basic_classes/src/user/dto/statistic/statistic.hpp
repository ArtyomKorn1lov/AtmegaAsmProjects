#ifndef STATISTIC_HPP
#define STATISTIC_HPP
#include <Arduino.h>

class Statistic
{
private:
    // Количество проданных единиц
    int salesVolume;
    // Цена за единицу
    int price;
    // Количество сделок
    int dealCount;
    // Количество лидов
    int leadCount;
    // Себестоимость
    int constPrice;
    // Сторонние затраты
    int otherExpenses;

public:
    Statistic(
        int salesVolume,
        int price,
        int dealCount,
        int leadCount,
        int constPrice,
        int otherExpenses
    );
    ~Statistic();
    // Выручка
    int revenue();
    // Средний чек
    int averageBill(int revenueValue = NULL);
    // Конверсия
    double conversion();
    // Заработок
    int income(int revenueValue = NULL);
    // Рентабельность
    double profitability(int incomeValue = NULL, int revenueValue = NULL);
    // Ценность лида
    int ltv(int incomeValue = NULL);
};

#endif