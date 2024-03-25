#ifndef ATBASHSTRATEGY_H
#define ATBASHSTRATEGY_H

#include "icipherstrategy.h"

class AtbashStrategy : public ICipherStrategy
{
public:
    AtbashStrategy();

public:
    QString encrypt(QString text) override;
    QString decrypt(QString text) override;
};

#endif // ATBASHSTRATEGY_H
