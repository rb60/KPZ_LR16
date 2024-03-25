#include "caesarstrategy.h"

CaesarStrategy::CaesarStrategy() {}

QString CaesarStrategy::encrypt(QString text)
{
    QString result = "";
    QChar q_char;
    char16_t u_char;
    for(int i = 0; i < text.size();i++)
    {
        u_char = text.at(i).unicode();
        q_char = QChar::fromUcs2(u_char + 3);
        result.append(q_char);
    }
    return result;
}

QString CaesarStrategy::decrypt(QString text)
{
    QString result = "";
    QChar q_char;
    char16_t u_char;
    for(int i = 0; i < text.size();i++)
    {
        u_char = text.at(i).unicode();
        q_char = QChar::fromUcs2(u_char - 3);
        result.append(q_char);
    }
    return result;
}
