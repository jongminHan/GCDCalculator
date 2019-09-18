#pragma once
#include <QObject>
#include <QString>

class BackEnd : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int number1 READ number1 WRITE setNumber1 NOTIFY number1Changed)
    Q_PROPERTY(int number2 READ number2 WRITE setNumber2 NOTIFY number2Changed)
    Q_PROPERTY(int gcd READ gcd)

public:
    explicit BackEnd(QObject* parent = nullptr);
    ~BackEnd() = default;

    int gcd();

    int number1();
    void setNumber1(int num);

    int number2();
    void setNumber2(int num);


    Q_INVOKABLE void setGcd();

signals:
    void number1Changed();
    void number2Changed();

private:
    int getGcdRecursive(int num1, int num2);
    int mNumber1;
    int mNumber2;
    int mGcd;
};
