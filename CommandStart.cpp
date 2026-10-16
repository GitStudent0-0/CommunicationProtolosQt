#include "CommandStart.h"
CommandStart::CommandStart() {}
CommandStart::CommandStart(int cmdType, int id, int count)
  : m_CMDType(static_cast<Command>(cmdType))
  , m_id(id)
  , m_count(count)
{}

void CommandStart::readJson(const QJsonObject &json)
{
    if (json.contains("CMDType") && json["CMDType"].isDouble())
        m_CMDType = Command(json["CMDType"].toInt());
    if (json.contains("id") && json["id"].isDouble())
      m_id = json["id"].toInt();
    if (json.contains("count") && json["count"].isDouble())
      m_count = json["count"].toInt();
}
void CommandStart::writeJson(QJsonObject& json) const
{
  json["CMDType"] = m_CMDType;
  json["id"] = m_id;
  json["count"] = m_count;
}

void CommandStart::toDebug(QDebug dbg)
{
  dbg << "Command type: " << m_CMDType << "ID: " << m_id << "Count: " << m_count;
}