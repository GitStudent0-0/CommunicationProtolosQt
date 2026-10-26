#ifndef JSONENCODER_H
#define JSONENCODER_H
#include "Command.h"
#include "CommandMessage.h"
#include "CommandStart.h"
#include <QDomElement>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QXmlStreamWriter>
#include <QtXml>
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
