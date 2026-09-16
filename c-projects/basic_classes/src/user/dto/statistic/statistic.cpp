#include "statistic.hpp"

Statistic::Statistic(
    int salesVolume,
    int price,
    int dealCount,
    int leadCount,
    int constPrice,
    int otherExpenses)
    : salesVolume(salesVolume),
      price(price),
      dealCount(dealCount),
      leadCount(leadCount),
      constPrice(constPrice),
      otherExpenses(otherExpenses)
{
}

Statistic::~Statistic()
{
}

int Statistic::revenue()
{
    return salesVolume * price;
}

int Statistic::averageBill(int revenueValue = NULL)
{
    if (revenueValue == NULL)
    {
        revenueValue = revenue();
    }
    return revenueValue / dealCount;
}

double Statistic::conversion()
{
    return (double)dealCount / (double)leadCount * 100;
}

int Statistic::income(int revenueValue = NULL)
{
    if (revenueValue == NULL)
    {
        revenueValue = revenue();
    }
    return revenueValue - constPrice - otherExpenses;
}

double Statistic::profitability(int incomeValue = NULL, int revenueValue = NULL)
{
    if (incomeValue == NULL)
    {
        incomeValue = income();
    }
    if (revenueValue == NULL)
    {
        revenueValue = revenue();
    }
    return (double)incomeValue / (double)revenueValue;
}

int Statistic::ltv(int incomeValue = NULL)
{
    if (incomeValue == NULL)
    {
        incomeValue = income();
    }
    return incomeValue / leadCount;
}