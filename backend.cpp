#include "backend.h"

BackEnd::BackEnd(QObject* parent)
    : QObject(parent)
    , mNumber1(1)
    , mNumber2(1)
{
}

int BackEnd::gcd()
{
    return mGcd;
}

int BackEnd::number1()
{
    return mNumber1;
}

void BackEnd::setNumber1(int num)
{
    if (mNumber1 == num)
    {
        return;
    }

    mNumber1 = num;

    emit number1Changed();
}

int BackEnd::number2()
{
    return mNumber2;
}

void BackEnd::setNumber2(int num)
{
    if (mNumber2 == num)
    {
        return;
    }

    mNumber2 = num;

    emit number2Changed();
}

int BackEnd::getGcdRecursive(int num1, int num2)
{
    if (num2 == 0)
    {
        return num1;
    }

    return getGcdRecursive(num2, num1 % num2);
}

void BackEnd::setGcd()
{
    mGcd = getGcdRecursive(mNumber1, mNumber2);
}
