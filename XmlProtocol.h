#ifndef XMLPROTOCOL_H
#define XMLPROTOCOL_H
#include "Command.h"
#include "Protocol.h"
#include <QXmlStreamReader>

class XmlProtocol : public Protocol
{
public:
  XmlProtocol();
  ~XmlProtocol() override;
  Command* read(const QByteArray& data) override;
  QByteArray write(Command* command) override;
};

#endif // XMLPROTOCOL_H
