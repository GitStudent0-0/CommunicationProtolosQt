#include "XmlDecoder.h"
#include "Command.h"
#include "CommandMessage.h"
#include "CommandStart.h"

Command* XmlDecoder::getCmd(const QByteArray& data)
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
        break;
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
