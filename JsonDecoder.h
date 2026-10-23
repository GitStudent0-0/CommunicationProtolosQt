#ifndef JSONDECODER_H
#define JSONDECODER_H
#include "Command.h"
#include "CommandMessage.h"
#include "CommandStart.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
using namespace log4cplus;
class JsonDecoder
{

public:
  JsonDecoder() {};
  ~JsonDecoder() {};
  bool readJson(const QJsonObject& json, Command& command);
  bool readJson(const QJsonObject& json, CommandStart& command);
  bool readJson(const QJsonObject& json, CommandMessage& command);
  bool parseToRawObject(const QByteArray& data, QJsonObject& jsonObj);

private:
  Logger m_logger;
};

#endif // JSONDECODER_H
