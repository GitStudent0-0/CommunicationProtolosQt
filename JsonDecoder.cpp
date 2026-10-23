#include "JsonDecoder.h"

bool JsonDecoder::readJson(const QJsonObject& json, Command& command)
{
  if (json.contains("CMDType") && json["CMDType"].isDouble())
  {
    command.init(json["CMDType"].toInt());
    return true;
  }
  return false;
}

bool JsonDecoder::readJson(const QJsonObject& json, CommandStart& command)
{
  if (json.contains("CMDType") && json["CMDType"].isDouble() &&
      json.contains("count") && json["count"].isDouble())
  {
    command.init(json["CMDType"].toInt(), json["count"].toInt());
    return true;
  }
  return false;
}

bool JsonDecoder::readJson(const QJsonObject& json, CommandMessage& command)
{
  if (json.contains("CMDType") && json["CMDType"].isDouble() &&
      json.contains("count") && json["count"].isDouble() && json.contains("data") &&
      json["data"].isArray())
  {
    const QJsonArray jsonArray = json["data"].toArray();
    QVector<double> data;
    for (const QJsonValue& val : qAsConst(jsonArray))
      data.append(val.toDouble());
    command.init(json["CMDType"].toInt(), json["count"].toInt(), data);
    return true;
  }
  return false;
}

bool JsonDecoder::parseToRawObject(const QByteArray& data, QJsonObject& jsonObj)
{
  QJsonParseError parseError;
  QJsonDocument jsonDoc = QJsonDocument::fromJson(data, &parseError);
  if (parseError.error != QJsonParseError::NoError)
  {
    LOG4CPLUS_ERROR(m_logger, "Error: " << parseError.errorString().toStdString());
    return false;
  }
  if (jsonDoc.isObject())
    jsonObj = jsonDoc.object();
  return true;
}