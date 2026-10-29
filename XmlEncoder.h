#ifndef XMLENCODER_H
#define XMLENCODER_H
#include "Command.h"
#include "CommandMessage.h"
#include "CommandStart.h"
#include <QBuffer>
#include <QXmlStreamWriter>

class XmlEncoder
{
public:
  XmlEncoder() {};
  ~XmlEncoder() {};
  static QByteArray writeXml(const Command& command);
  static QByteArray writeXml(const CommandStart& command);
  static QByteArray writeXml(const CommandMessage& command);
};

#endif // XMLENCODER_H
