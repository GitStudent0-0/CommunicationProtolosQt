#ifndef JSONDECODER_H
#define JSONDECODER_H
#include "Command.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

class JsonDecoder
{
public:
  JsonDecoder() {};
  ~JsonDecoder() {};
  static Command* getCmd(const QByteArray& data, QJsonParseError& parseError);
};

#endif // JSONDECODER_H
