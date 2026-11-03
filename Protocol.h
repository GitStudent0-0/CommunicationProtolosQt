#ifndef PROTOCOL_H
#define PROTOCOL_H
#include "Command.h"

enum DataFormat
{
  JSON = 1,
  XML
};

class Protocol
{
  Q_GADGET
  Q_ENUM(DataFormat);

public:
  Protocol() {};
  virtual ~Protocol() = default;
  static Protocol* create(DataFormat protocol);
  virtual Command* read(const QByteArray& data) = 0;
  virtual QByteArray write(Command* cmd) = 0;
};

#endif // PROTOCOL_H
