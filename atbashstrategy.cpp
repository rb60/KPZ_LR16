#include "atbashstrategy.h"

AtbashStrategy::AtbashStrategy() {}

QString AtbashStrategy::encrypt(QString text)
{
    int max = 0b1111111111111111;
    QString result = "";
    QChar q_char;
    char16_t u_char;
    for(int i = 0; i < text.size();i++)
    {
        u_char = text.at(i).unicode();
        q_char = QChar::fromUcs2(max - u_char);
        result.append(q_char);
    }
    return result;
}

QString AtbashStrategy::decrypt(QString text)
{
    return encrypt(text);
}
