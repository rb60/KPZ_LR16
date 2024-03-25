#include "disappearstrategy.h"

DisappearStrategy::DisappearStrategy() {}

QString DisappearStrategy::encrypt(QString text)
{
    QString result = "";
    char16_t u_char;
    for(int i = 0; i < text.size();i++)
    {
        u_char = text.at(i).unicode();
        for(int j = 0; j < 16; j++)
        {
            if((u_char & (1 << j)))
            {
                result.append('\t');
            }
            else
            {
                result.append(' ');
            }
        }
        result.append('\n');
    }
    return result;
}

QString DisappearStrategy::decrypt(QString text)
{
    QString result = "";
    char16_t u_char = 0;
    for(int i = 0; i < text.size(); i += 17)
    {
        for(int j = 0; j < 16 && i + j < text.size(); j++)
        {
            if(text.at(i + j) == '\t')
            {
                u_char = (u_char | (1 << j));
            }
        }
        result.append(QChar(u_char));
        u_char = 0;
    }
    return result;
}
