#ifndef CIPHER_H
#define CIPHER_H
#include "icipherstrategy.h"


class Cipher
{
private:
    ICipherStrategy* strategy;
public:
    Cipher();
    void encrypt(QString path);
    void decrypt(QString path);
    ICipherStrategy *getStrategy() const;
    void setStrategy(ICipherStrategy *newStrategy);
};

#endif // CIPHER_H
