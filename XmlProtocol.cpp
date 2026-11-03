#include "XmlProtocol.h"
#include "Command.h"
#include "CommandMessage.h"
#include "CommandStart.h"

Command* XmlProtocol::read(const QByteArray& data)
{
  QXmlStreamReader xml(data);
  if (xml.readNextStartElement() && xml.name() == "Command")
  {
    if (xml.readNextStartElement() && xml.name() == "CMDType")
    {
      int type = xml.readElementText().toInt();
      switch (type)
      {
      case CMDType::START:
      {
        if (xml.readNextStartElement() && xml.name() == "count")
        {
          CommandStart* cmdStart = new CommandStart();
          cmdStart->init(type, xml.readElementText().toInt());
          return cmdStart;
        }
        break;
      }
      case CMDType::STOP:
      {
        Command* cmdStop = new Command();
        cmdStop->init(type);
        return cmdStop;
      }
      case CMDType::MESSAGE:
      {
        if (xml.readNextStartElement() && xml.name() == "count")
        {
          int count = xml.readElementText().toInt();
          if (xml.readNextStartElement() && xml.name() == "data")
          {
            QVector<double> data;
            while (xml.readNextStartElement())
            {
              if (xml.name() == "value")
                data.append(xml.readElementText().toDouble());
              else
                xml.skipCurrentElement();
            }
            CommandMessage* cmdMessage = new CommandMessage();
            cmdMessage->init(type, count, data);
            return cmdMessage;
          }
        }
        break;
      }
      }
    }
  }
  return nullptr;
}

QByteArray XmlProtocol::write(Command* command)
{
  QByteArray bytes;
  QXmlStreamWriter xml(&bytes);
  xml.writeStartElement("Command");
  xml.writeStartElement("CMDType");
  xml.writeCharacters(QString::number(command->getCMDType()));
  xml.writeEndElement();
  switch (command->getCMDType())
  {
  case CMDType::START:
  {
    CommandStart* cmdStart = dynamic_cast<CommandStart*>(command);
    xml.writeStartElement("count");
    xml.writeCharacters(QString::number(cmdStart->getCount()));
    xml.writeEndElement();
    break;
  }
  case CMDType::STOP:
  {
    break;
  }
  case CMDType::MESSAGE:
  {
    CommandMessage* cmdMessage = dynamic_cast<CommandMessage*>(command);
    xml.writeStartElement("count");
    xml.writeCharacters(QString::number(cmdMessage->getCount()));
    xml.writeEndElement();
    xml.writeStartElement("data");
    for (const double& val : cmdMessage->getData())
    {
      xml.writeStartElement("value");
      xml.writeCharacters(QString::number(val));
      xml.writeEndElement();
    }
    xml.writeEndElement();
    break;
  }
  }
  xml.writeEndElement();
  return bytes;
}