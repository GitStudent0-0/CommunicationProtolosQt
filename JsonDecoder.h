#ifndef JSONDECODER_H
#define JSONDECODER_H
#include "CommandStart.h"
#include <QJsonDocument>
#include <QJsonObject>
class JsonDecoder
{

public:
  JsonDecoder() {};
  ~JsonDecoder() {};
  bool readJson(const QByteArray& data, CommandStart& command);
};

#endif // JSONDECODER_H
