#include "Command.h"
Command::Command() {}
Command::Command(int cmdType) { init(cmdType); }

Command::Command(const Command& other) { m_CMDType = other.m_CMDType; }

void Command::init(int cmdType) { m_CMDType = static_cast<CMDType>(cmdType); }

CMDType Command::getCMDType() const { return m_CMDType; }

void Command::toDebug(QDebug dbg) { dbg << "Command type: " << m_CMDType; }