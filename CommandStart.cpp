#include "CommandStart.h"
CommandStart::CommandStart() {}
CommandStart::CommandStart(int cmdType, int id, int count)
  : m_CMDType(static_cast<CMDType>(cmdType))
  , m_id(id)
  , m_count(count)
{}

CommandStart::CommandStart(CommandStart& other)
{
  m_CMDType = other.m_CMDType;
  m_id = other.m_id;
  m_count = other.m_count;
}

void CommandStart::setCMDType(CMDType _CMDType) { m_CMDType = _CMDType; }
void CommandStart::setId(int _id) { m_id = _id; }
void CommandStart::setCount(int _count) { m_count = _count; }

CMDType CommandStart::getCMDType() const { return m_CMDType; }
int CommandStart::getId() const { return m_id; }
int CommandStart::getCount() const { return m_count; }

void CommandStart::toDebug(QDebug dbg)
{
  dbg << "Command type: " << m_CMDType << "ID: " << m_id << "Count: " << m_count;
}