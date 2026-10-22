#include "CommandStart.h"
#include "JsonDecoder.h"
#include "JsonEncoder.h"
#include <QByteArray>
#include <QCoreApplication>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <log4cplus/configurator.h>
#include <log4cplus/initializer.h>
int main(int argc, char *argv[])
{
  Initializer initializer;
  PropertyConfigurator::doConfigure("log4cplus.properties");
  QCoreApplication a(argc, argv);
  QJsonObject jsonIn;
  CommandStart data(1, 10);
  JsonEncoder encoder;
  QByteArray bytesIn = encoder.writeJson(data);

  QFile dataFile("/home/marina/CommunicationProtocols/dataJson.json");
  if (dataFile.open(QIODevice::WriteOnly))
  {
    dataFile.write(bytesIn);
    dataFile.close();
  }

    QByteArray bytesOut;
    if (dataFile.open(QIODevice::ReadOnly))
    {
      bytesOut = dataFile.readAll();
      dataFile.close();
    }
    CommandStart data2;
    JsonDecoder decoder;
    bool succes = decoder.readJson(bytesOut, data2);
    if (succes)
      data2.toDebug(qDebug());

    return QCoreApplication::exec();
}
