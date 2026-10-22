#ifndef COMMANDMESSAGE_H
#define COMMANDMESSAGE_H
#include "Command.h"
#include <QVector>
class CommandMessage : public Command
{

public:
  CommandMessage();
  CommandMessage(int CMDType, int count, const QVector<double>& data);
  CommandMessage(const CommandMessage& other);
  ~CommandMessage() {};
  void init(int cmdType, int count, const QVector<double>& data);
  void toDebug(QDebug dbg);
  int getCount() const;
  QVector<double> getData() const;

private:
  int m_count;
  QVector<double> m_data;
};

#endif // COMMANDMESSAGE_H
