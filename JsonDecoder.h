#ifndef JSONDECODER_H
#define JSONDECODER_H
#include "Command.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QXmlStreamReader>
#include <QtXml>
#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
using namespace log4cplus;
class JsonDecoder
{

public:
  JsonDecoder();
  ~JsonDecoder() {};
  static Command* getCmd(const QByteArray& data);

private:
  Logger m_logger;
};

#endif // JSONDECODER_H
