#ifndef JSONENCODER_H
#define JSONENCODER_H
#include "Command.h"
#include "CommandMessage.h"
#include "CommandStart.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
class JsonEncoder
{

public:
  JsonEncoder() {};
  ~JsonEncoder() {};
  QByteArray writeJson(const Command& command);
  QByteArray writeJson(const CommandStart& command);
  QByteArray writeJson(const CommandMessage& command);
};

#endif // JSONENCODER_H
