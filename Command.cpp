#include "Command.h"

Command::Command()
{
  LOG4CPLUS_TRACE(m_logger, "Memory allocated Command: " << this);
}

Command::Command(int cmdType)
  : Command()
{
  init(cmdType);
}

Command::Command(const Command& other)
  : Command()
{
  m_CMDType = other.m_CMDType;
}
Command::~Command() { LOG4CPLUS_TRACE(m_logger, "Memory freed Command: " << this); }

void Command::init(int cmdType) { m_CMDType = static_cast<CMDType>(cmdType); }

CMDType Command::getCMDType() const { return m_CMDType; }

void Command::toDebug(QDebug dbg) { dbg << "Command type: " << m_CMDType; }