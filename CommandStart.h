#ifndef COMMANDSTART_H
#define COMMANDSTART_H
#include <QJsonObject>
enum Command { START, MESSAGE, STOP };

class CommandStart : public QObject
{
    Q_OBJECT
    Q_ENUM(Command);

public:
    CommandStart();
    CommandStart(int CMDType, int id, int count);
    ~CommandStart() {};
    void readJson(const QJsonObject &json);
    void writeJson(QJsonObject &json) const;
    void toDebug(QDebug dbg);

  private:
    Command m_CMDType;
    int m_id;
    int m_count;
};

#endif // COMMANDSTART_H
