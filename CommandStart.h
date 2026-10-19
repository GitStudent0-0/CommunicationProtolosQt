#ifndef COMMANDSTART_H
#define COMMANDSTART_H
#include <QDebug>
enum CMDType
{
  START,
  MESSAGE,
  STOP
};
class CommandStart : public QObject
{
  Q_OBJECT
  Q_ENUM(CMDType);

public:
  CommandStart();
  CommandStart(int CMDType, int id, int count);
  CommandStart(CommandStart& other);
  ~CommandStart() {};
  void toDebug(QDebug dbg);
  void setCMDType(CMDType _CMDType);
  void setId(int _id);
  void setCount(int _count);
  CMDType getCMDType() const;
  int getId() const;
  int getCount() const;

private:
  CMDType m_CMDType;
  int m_id;
  int m_count;
};

#endif // COMMANDSTART_H
