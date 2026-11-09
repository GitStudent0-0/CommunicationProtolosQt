#include "CommandMessage.h"

CommandMessage::CommandMessage() {}

CommandMessage::CommandMessage(int cmdType, int count, const QVector<double>& data)
{
  init(cmdType, count, data);
}

CommandMessage::CommandMessage(const CommandMessage& other)
  : Command(other)
{
  m_CMDType = other.m_CMDType;
  m_count = other.m_count;
}

void CommandMessage::init(int cmdType, int count, const QVector<double>& data)
{
  m_CMDType = static_cast<CMDType>(cmdType);
  m_count = count;
  m_data = data;
}

QVector<double> CommandMessage::getData() const { return m_data; }
int CommandMessage::getCount() const { return m_count; }

void CommandMessage::toDebug(QDebug dbg)
{
  dbg << "Command type: " << m_CMDType << "Count: " << m_count << "Data: " << m_data;
}