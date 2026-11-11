#ifndef COMMAND_H
#define COMMAND_H
#include <QDebug>
#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>

using namespace log4cplus;

enum CMDType
{
  START = 1,
  MESSAGE,
  STOP
};

class Command
{
  Q_GADGET
  Q_ENUM(CMDType);

public:
  Command();
  Command(int CMDType);
  Command(const Command& other);
  virtual ~Command();
  void init(int cmdType);
  virtual void toDebug(QDebug dbg);
  CMDType getCMDType() const;

protected:
  CMDType m_CMDType;
  Logger m_logger = Logger::getInstance("Command");
};
#endif // COMMAND_H
