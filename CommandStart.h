#ifndef COMMANDSTART_H
#define COMMANDSTART_H
#include <QDebug>
enum CMDType
{
  START = 1,
  MESSAGE,
  STOP
};
class CommandStart : public QObject
{
  Q_ENUM(CMDType);

public:
  CommandStart();
  CommandStart(int CMDType, int count);
  CommandStart(CommandStart& other);
  CommandStart(const CommandStart& other);
  ~CommandStart() {};
  void init(int cmdType, int count);
  void toDebug(QDebug dbg);
  CMDType getCMDType() const;
  int getCount() const;
  QVector<int> getData() const;

private:
  CMDType m_CMDType;
  int m_count;
};

#endif // COMMANDSTART_H
