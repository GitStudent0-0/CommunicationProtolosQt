#ifndef JSONENCODER_H
#define JSONENCODER_H
#include "CommandStart.h"
#include <QJsonDocument>
#include <QJsonObject>
class JsonEncoder
{

public:
  JsonEncoder() {};
  ~JsonEncoder() {};
  QByteArray writeJson(const CommandStart& command);
};

#endif // JSONENCODER_H
