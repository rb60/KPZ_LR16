#include "cipher.h"
#include <QFile>

ICipherStrategy *Cipher::getStrategy() const
{
    return strategy;
}

void Cipher::setStrategy(ICipherStrategy *newStrategy)
{
    strategy = newStrategy;
}

Cipher::Cipher() {}

void Cipher::encrypt(QString path)
{
    if(strategy == nullptr)
        return;

    QFile file(path);
    if(!file.open(QIODeviceBase::ReadOnly))
        return;
    QString text;
    text = QString::fromUtf8(file.readAll());
    file.close();

    text = strategy->encrypt(text);

    if(!file.open(QIODeviceBase::WriteOnly | QIODeviceBase::Truncate))
        return;
    file.write(text.toUtf8());
    file.close();

}

void Cipher::decrypt(QString path)
{
    if(strategy == nullptr)
        return;

    QFile file(path);
    if(!file.open(QIODeviceBase::ReadOnly))
        return;
    QString text;
    text = QString::fromUtf8(file.readAll());
    file.close();

    text = strategy->decrypt(text);

    if(!file.open(QIODeviceBase::WriteOnly | QIODeviceBase::Truncate))
        return;
    file.write(text.toUtf8());
    file.close();
}
