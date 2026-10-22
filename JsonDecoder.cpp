#include "JsonDecoder.h"

bool JsonDecoder::readJson(const QByteArray& data, Command& command)
{
  QJsonParseError error;
  QJsonDocument doc = QJsonDocument::fromJson(data, &error);
  QJsonObject json = doc.object();
  if (error.error != QJsonParseError::NoError)
  {
    qWarning() << error.errorString();
    return false;
  }
  if (json.contains("CMDType") && json["CMDType"].isDouble())
    command.init(json["CMDType"].toInt());
  return true;
}

bool JsonDecoder::readJson(const QByteArray& data, CommandStart& command)
{
  QJsonParseError error;
  QJsonDocument doc = QJsonDocument::fromJson(data, &error);
  QJsonObject json = doc.object();
  if (error.error != QJsonParseError::NoError)
  {
    qWarning() << error.errorString();
    return false;
  }
  if (json.contains("CMDType") && json["CMDType"].isDouble() &&
      json.contains("count") && json["count"].isDouble())
    command.init(json["CMDType"].toInt(), json["count"].toInt());
  return true;
}

bool JsonDecoder::readJson(const QByteArray& data, CommandMessage& command)
{
  QJsonParseError error;
  QJsonDocument doc = QJsonDocument::fromJson(data, &error);
  QJsonObject json = doc.object();
  if (error.error != QJsonParseError::NoError)
  {
    qWarning() << error.errorString();
    return false;
  }
  if (json.contains("CMDType") && json["CMDType"].isDouble() &&
      json.contains("count") && json["count"].isDouble() && json.contains("data") &&
      json["data"].isArray())
  {
    const QJsonArray jsonArray = json["data"].toArray();
    QVector<double> data;
    for (const QJsonValue& val : qAsConst(jsonArray))
      data.append(val.toDouble());
    command.init(json["CMDType"].toInt(), json["count"].toInt(), data);
  }
  return true;
}
