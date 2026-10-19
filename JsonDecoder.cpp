#include "JsonDecoder.h"

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
  if (json.contains("CMDType") && json["CMDType"].isDouble())
    command.setCMDType(CMDType(json["CMDType"].toInt()));
  if (json.contains("id") && json["id"].isDouble())
    command.setId(json["id"].toInt());
  if (json.contains("count") && json["count"].isDouble())
    command.setCount(json["count"].toInt());
  return true;
}
