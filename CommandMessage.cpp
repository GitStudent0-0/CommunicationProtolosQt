#include "CommandMessage.h"
CommandMessage::CommandMessage() {}
CommandMessage::CommandMessage(int cmdType, int count, const QVector<double>& data)
  : m_CMDType(static_cast<CMDType>(cmdType))
  , m_count(count)
  , m_data(data)
{}

CommandMessage::CommandMessage(CommandMessage& other)
{
  m_CMDType = other.m_CMDType;
  m_count = other.m_count;
}

CommandMessage::CommandMessage(const CommandMessage& other)
{
  m_CMDType = other.m_CMDType;
  m_count = other.m_count;
}

QVector<double> CommandMessage::getData() const { return m_data; }

void CommandMessage::toDebug(QDebug dbg)
{
  dbg << "Command type: " << m_CMDType << "Count: " << m_count << "Data: " << m_data;
}