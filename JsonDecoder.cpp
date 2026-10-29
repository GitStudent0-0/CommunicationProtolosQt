#include "JsonDecoder.h"
#include "Command.h"
#include "CommandMessage.h"
#include "CommandStart.h"

Command* JsonDecoder::getCmd(const QByteArray& data, QJsonParseError& parseError)
{
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
