#include "JsonProtocol.h"
#include "Command.h"
#include "CommandMessage.h"
#include "CommandStart.h"

JsonProtocol::JsonProtocol()
{
  LOG4CPLUS_TRACE(m_logger, "Memory allocated JsonProtocol: " << this);
}

JsonProtocol::~JsonProtocol()
{
  LOG4CPLUS_TRACE(m_logger, "Memory freed JsonProtocol: " << this);
}

Command* JsonProtocol::read(const QByteArray& data)
{
  QJsonParseError parseError;
  QJsonDocument jsonDoc = QJsonDocument::fromJson(data, &parseError);
  QJsonObject json;
  if (jsonDoc.isObject())
  {
    json = jsonDoc.object();
    switch (static_cast<CMDType>(json["CMDType"].toInt()))
    {
    case CMDType::START:
    {
      if (json.contains("count") && json["count"].isDouble())
      {
        CommandStart* cmdStart = new CommandStart();
        cmdStart->init(json["CMDType"].toInt(), json["count"].toInt());
        return cmdStart;
      }
      break;
    }
    case CMDType::STOP:
    {
      Command* cmdStop = new Command();
      cmdStop->init(json["CMDType"].toInt());
      return cmdStop;
      break;
    }
    case CMDType::MESSAGE:
    {
      if (json.contains("count") && json["count"].isDouble() &&
          json.contains("data") && json["data"].isArray())
      {
        CommandMessage* cmdMessage = new CommandMessage();
        const QJsonArray jsonArray = json["data"].toArray();
        QVector<double> data;
        for (const QJsonValue& val : qAsConst(jsonArray))
          data.append(val.toDouble());
        cmdMessage->init(json["CMDType"].toInt(), json["count"].toInt(), data);
        return cmdMessage;
      }
      break;
    }
    }
  }
  return nullptr;
}

QByteArray JsonProtocol::write(Command* command)
{
  QJsonObject json;
  QByteArray bytes;
  json["CMDType"] = static_cast<int>(command->getCMDType());
  switch (command->getCMDType())
  {
  case CMDType::START:
  {
    if (CommandStart* cmdStart = dynamic_cast<CommandStart*>(command))
      json["count"] = cmdStart->getCount();
    break;
  }
  case CMDType::STOP:
  {
    break;
  }
  case CMDType::MESSAGE:
  {
    if (CommandMessage* cmdMessage = dynamic_cast<CommandMessage*>(command))
    {
      json["count"] = cmdMessage->getCount();
      QJsonArray jsonArray;
      for (const double& val : cmdMessage->getData())
        jsonArray.append(val);
      json["data"] = jsonArray;
    }
    break;
  }
  }
  QJsonDocument doc(json);
  bytes = doc.toJson(QJsonDocument::Compact);
  return bytes;
}
