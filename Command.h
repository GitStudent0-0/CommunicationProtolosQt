#ifndef COMMAND_H
#define COMMAND_H
#include <QDebug>
enum CMDType
{
  START = 1,
  MESSAGE,
  STOP
};
class Command
{
  Q_GADGET
  Q_ENUM(CMDType);

public:
  Command();
  Command(int CMDType);
  Command(const Command& other);
  ~Command() {};
  void init(int cmdType);
  void toDebug(QDebug dbg);
  CMDType getCMDType() const;

protected:
  CMDType m_CMDType;
};
#endif // COMMAND_H
