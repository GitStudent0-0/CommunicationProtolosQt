#ifndef XMLDECODER_H
#define XMLDECODER_H
#include "Command.h"
#include <QBuffer>
#include <QXmlStreamReader>

class XmlDecoder
{
public:
  XmlDecoder() {};
  ~XmlDecoder() {};
  static Command* getCmd(const QByteArray& data);
};

#endif // XMLDECODER_H
