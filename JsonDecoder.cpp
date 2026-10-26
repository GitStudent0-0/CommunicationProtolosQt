#include "JsonDecoder.h"

JsonDecoder::JsonDecoder()
  : m_logger(Logger::getInstance("JsonDecoder"))
{}

Command* JsonDecoder::getCmd(const QByteArray& data)
{
  QJsonParseError parseError;
  QJsonDocument jsonDoc = QJsonDocument::fromJson(data, &parseError);
  // if (parseError.error != QJsonParseError::NoError)
  //   LOG4CPLUS_ERROR(m_logger, "Error: " <<
  //   parseError.errorString().toStdString());
  QJsonObject json;
  if (jsonDoc.isObject())
    json = jsonDoc.object();
  switch (static_cast<CMDType>(json["CMDType"].toInt()))
  {
  case CMDType::START:
  {
    if (json.contains("CMDType") && json["CMDType"].isDouble() &&
        json.contains("count") && json["count"].isDouble())
    {
      CommandStart* cmdStart = new CommandStart();
      cmdStart->init(json["CMDType"].toInt(), json["count"].toInt());
      return cmdStart;
    }
    break;
  }
  case CMDType::STOP:
  {
    if (json.contains("CMDType") && json["CMDType"].isDouble())
    {
      Command* cmdStop = new Command();
      cmdStop->init(json["CMDType"].toInt());
      return cmdStop;
    }
    break;
  }
  case CMDType::MESSAGE:
  {
    if (json.contains("CMDType") && json["CMDType"].isDouble() &&
        json.contains("count") && json["count"].isDouble() &&
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
  default:
    return nullptr;
  }
}
