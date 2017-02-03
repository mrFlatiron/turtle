#ifndef ENCODER_H
#define ENCODER_H
#include <QString>
#include <string.h>
#include "const.h"


class Encoder
{
public:
    Encoder();
    int encode(const QString &msg, char *data, const int dataSize, QString& errorMsg);
    int decode(QString &msg, const char *data);
};

#endif // ENCODER_H
