#include "CommandStart.h"

CommandStart::CommandStart()
{
  LOG4CPLUS_TRACE(m_logger, "Memory allocated CommandStart: " << this);
}

CommandStart::CommandStart(int cmdType, int count)
  : CommandStart()
{
  init(cmdType, count);
}

CommandStart::CommandStart(const CommandStart& other)
  : Command(other)
{
  m_CMDType = other.m_CMDType;
  m_count = other.m_count;
}

CommandStart::~CommandStart()
{
  LOG4CPLUS_TRACE(m_logger, "Memory freed CommandStart: " << this);
}

void CommandStart::init(int cmdType, int count)
{
  m_CMDType = static_cast<CMDType>(cmdType);
  m_count = count;
}

int CommandStart::getCount() const { return m_count; }

void CommandStart::toDebug(QDebug dbg)
{
  dbg << "Command type: " << m_CMDType << "Count: " << m_count;
}