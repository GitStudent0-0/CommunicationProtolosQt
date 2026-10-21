#ifndef COMMANDMESSAGE_H
#define COMMANDMESSAGE_H
#include "CommandStart.h"
#include <QVector>
class CommandMessage : public CommandStart
{
  Q_OBJECT

public:
  CommandMessage();
  CommandMessage(int CMDType, int count, const QVector<double>& data);
  CommandMessage(CommandMessage& other);
  CommandMessage(const CommandMessage& other);
  ~CommandMessage() {};
  void toDebug(QDebug dbg);
  QVector<double> getData() const;

private:
  CMDType m_CMDType;
  int m_count;
  QVector<double> m_data;
};

#endif // COMMANDMESSAGE_H
