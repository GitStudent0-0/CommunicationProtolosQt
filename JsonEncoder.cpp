#include "JsonEncoder.h"

QByteArray JsonEncoder::writeJson(const Command& command)
{
  QJsonObject json;
  json["CMDType"] = command.getCMDType();
  QJsonDocument doc(json);
  QByteArray bytes = doc.toJson(QJsonDocument::Compact);
  return bytes;
}

QByteArray JsonEncoder::writeJson(const CommandStart& command)
{
  QJsonObject json;
  json["CMDType"] = command.getCMDType();
  json["count"] = command.getCount();
  QJsonDocument doc(json);
  QByteArray bytes = doc.toJson(QJsonDocument::Compact);
  return bytes;
}

QByteArray JsonEncoder::writeJson(const CommandMessage& command)
{
  QJsonObject json;
  json["CMDType"] = command.getCMDType();
  json["count"] = command.getCount();
  QJsonArray jsonArray;
  for (const double& val : command.getData())
    jsonArray.append(val);
  json["data"] = jsonArray;
  QJsonDocument doc(json);
  QByteArray bytes = doc.toJson(QJsonDocument::Compact);
  return bytes;
}