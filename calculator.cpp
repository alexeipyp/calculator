#include "calculator.h"

Calculator::Calculator()
{

}
//SetMethods
void Calculator::setFirstValue(double value)
{
    value_1 = value;
}
void Calculator::setSecondValue(double value)
{
    value_2 = value;
}

//GetMethods
double Calculator::getAdd()
{
    return value_1+value_2;
}
double Calculator::getSub()
{
    return value_1-value_2;
}
double Calculator::getMult()
{
    return value_1*value_2;
}
double Calculator::getDiv()
{
    return value_1/value_2;
}
double Calculator::getAbs()
{
    return std::abs(value_1);
}
