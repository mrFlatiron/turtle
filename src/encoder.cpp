#include "include/encoder.h"

Encoder::Encoder()
{

}
int Encoder::encode(const QString &msg, char *data, const int dataSize, QString& errorMsg)
{
    QByteArray ba;
    ba = msg.toUtf8();
    const char *tempData = ba.constData();
    short length = strlen(tempData);
    if (dataSize < length + 3)
      {
        errorMsg = QString("The message is too long");
        return BUFFER_TOO_SMALL;
      }
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
    short length = *(short *)(data);
    int is_error = 0;
    is_error =  (length <= 0) ? 1 : 0;
    length = abs(length);

    if (length == 0 || length > MAX_MESSAGE_LENGTH)
      {
        msg = "Invalid message recieved. Somebody have ruined the server!";
        return BAD_FORMAT;
      }

    data = data + 2;
    msg = msg.fromUtf8(data, length);
    msg = msg.toHtmlEscaped();
    return is_error;
}
