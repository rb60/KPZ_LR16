#ifndef DISAPPEARSTRATEGY_H
#define DISAPPEARSTRATEGY_H

#include "icipherstrategy.h"

class DisappearStrategy : public ICipherStrategy
{
public:
    DisappearStrategy();

public:
    QString encrypt(QString text) override;
    QString decrypt(QString text) override;
};

#endif // DISAPPEARSTRATEGY_H
