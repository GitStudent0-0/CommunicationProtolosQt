#include "XmlEncoder.h"

QByteArray XmlEncoder::writeXml(const Command& command)
{
  QByteArray bytes;
  QXmlStreamWriter xml(&bytes);
  xml.writeStartDocument();
  xml.writeStartElement("Command");
  xml.writeStartElement("CMDType");
  xml.writeCharacters(QString::number(command.getCMDType()));
  xml.writeEndElement();
  xml.writeEndElement();
  xml.writeEndDocument();
  return bytes;
}

QByteArray XmlEncoder::writeXml(const CommandStart& command)
{
  QByteArray bytes;
  QXmlStreamWriter xml(&bytes);
  xml.writeStartDocument();
  xml.writeStartElement("Command");
  xml.writeStartElement("CMDType");
  xml.writeCharacters(QString::number(command.getCMDType()));
  xml.writeEndElement();
  xml.writeStartElement("count");
  xml.writeCharacters(QString::number(command.getCount()));
  xml.writeEndElement();
  xml.writeEndElement();
  xml.writeEndDocument();
  return bytes;
}

QByteArray XmlEncoder::writeXml(const CommandMessage& command)
{
  QByteArray bytes;
  QXmlStreamWriter xml(&bytes);
  xml.writeStartDocument();
  xml.writeStartElement("Command");
  xml.writeStartElement("CMDType");
  xml.writeCharacters(QString::number(command.getCMDType()));
  xml.writeEndElement();
  xml.writeStartElement("count");
  xml.writeCharacters(QString::number(command.getCount()));
  xml.writeEndElement();
  xml.writeStartElement("data");
  for (const double& val : command.getData())
  {
    xml.writeStartElement("value");
    xml.writeCharacters(QString::number(val));
    xml.writeEndElement();
  }
  xml.writeEndElement();
  xml.writeEndElement();
  xml.writeEndDocument();
  return bytes;
}