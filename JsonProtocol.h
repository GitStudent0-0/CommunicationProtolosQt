#ifndef JSONPROTOCOL_H
#define JSONPROTOCOL_H
#include "Command.h"
#include "Protocol.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

class JsonProtocol : public Protocol
{
public:
  JsonProtocol() {};
  ~JsonProtocol() override = default;
  Command* read(const QByteArray& data) override;
  QByteArray write(Command* command) override;
};

#endif // JSONPROTOCOL_H
