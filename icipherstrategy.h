#ifndef ICIPHERSTRATEGY_H
#define ICIPHERSTRATEGY_H
#include <QString>

class ICipherStrategy
{
public:
    virtual QString encrypt(QString text) = 0;
    virtual QString decrypt(QString text) = 0;
};

#endif // ICIPHERSTRATEGY_H
