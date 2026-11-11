#ifndef COMMANDSTART_H
#define COMMANDSTART_H
#include "Command.h"
#include <QDebug>

class CommandStart : public Command
{

public:
  CommandStart();
  CommandStart(int CMDType, int count);
  CommandStart(const CommandStart& other);
  ~CommandStart() override;
  ;
  void init(int cmdType, int count);
  void toDebug(QDebug dbg) override;
  int getCount() const;

private:
  int m_count;
};

#endif // COMMANDSTART_H
