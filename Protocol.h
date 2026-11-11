#ifndef PROTOCOL_H
#define PROTOCOL_H
#include "Command.h"
#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>

using namespace log4cplus;

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
  Protocol();
  virtual ~Protocol();
  static Protocol* create(DataFormat protocol);
  virtual Command* read(const QByteArray& data) = 0;
  virtual QByteArray write(Command* cmd) = 0;

protected:
  Logger m_logger = Logger::getInstance("Protocol");
};

#endif // PROTOCOL_H
