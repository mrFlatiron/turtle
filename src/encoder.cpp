#include "encoder.h"

Encoder::Encoder()
{

}
int Encoder::encode(const QString &msg, char *data, const int dataSize)
{
    const char *tempData = msg.toUtf8().constData();
    short length = strlen(tempData);
    if (dataSize < length + 3)
        return BUFFER_TOO_SMALL;
    memset(data, 0, dataSize);
    data[0] = ((char *)(&length))[0];
    data[1] = ((char *)(&length))[1];
    for (short i = 0; i < length; i++)
    {
        data[2 + i] = tempData[i];
    }
    return length + 2;
}
int Encoder::decode(QString &msg, const char *data)
{
    const short length = *(short *)(data);
    if (length < 0 || length > MAX_MESSAGE_LENGTH)
        return BAD_FORMAT;
    data = data + 2;
    msg = msg.fromUtf8(data, length);
    return 0;
}
