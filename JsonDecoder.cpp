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
  if (json.contains("CMDType") && json["CMDType"].isDouble() &&
      json.contains("count") && json["count"].isDouble())
    command.init(json["CMDType"].toInt(), json["count"].toInt());
  return true;
}
