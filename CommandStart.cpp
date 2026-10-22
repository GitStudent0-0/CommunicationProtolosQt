#include "CommandStart.h"
CommandStart::CommandStart() {}
CommandStart::CommandStart(int cmdType, int count) { init(cmdType, count); }

CommandStart::CommandStart(const CommandStart& other)
  : Command(other)
{
  m_CMDType = other.m_CMDType;
  m_count = other.m_count;
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