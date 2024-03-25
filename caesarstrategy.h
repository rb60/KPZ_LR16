#ifndef CAESARSTRATEGY_H
#define CAESARSTRATEGY_H

#include "icipherstrategy.h"

class CaesarStrategy : public ICipherStrategy
{
public:
    CaesarStrategy();


public:
    QString encrypt(QString text) override;
    QString decrypt(QString text) override;
};

#endif // CAESARSTRATEGY_H
