#include "CommandStart.h"
#include <QByteArray>
#include <QCoreApplication>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QRandomGenerator>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QJsonObject jsonIn;
    int random_id = QRandomGenerator::global()->bounded(0, 10);
    CommandStart data(1, random_id, 10);
    data.writeJson(jsonIn);

    QJsonDocument docIn(jsonIn);
    QByteArray bytesIn = docIn.toJson(QJsonDocument::Compact);

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

    QJsonParseError error;
    QJsonDocument docOut;
    docOut = QJsonDocument::fromJson(bytesOut, &error);
    if (error.error != QJsonParseError::NoError)
      qWarning() << "Error" << error.errorString();

    QJsonObject jsonOut = docOut.object();
    CommandStart data2;
    data2.readJson(jsonOut);
    data2.toDebug(qDebug());
    return QCoreApplication::exec();
}
