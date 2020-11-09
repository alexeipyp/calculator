#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <cmath>

class Calculator
{
public:
    Calculator();

    double getAdd();
    double getSub();
    double getMult();
    double getDiv();
    double getAbs();

    void setFirstValue(double);
    void setSecondValue(double);

private:
    double value_1, value_2;
};

#endif // CALCULATOR_H
