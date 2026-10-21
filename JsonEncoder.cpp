#include "JsonEncoder.h"

QByteArray JsonEncoder::writeJson(const CommandStart& command)
{
  QJsonObject json;
  json["CMDType"] = command.getCMDType();
  json["count"] = command.getCount();
  QJsonDocument doc(json);
  QByteArray bytes = doc.toJson(QJsonDocument::Compact);
  return bytes;
}