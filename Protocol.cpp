#include "Protocol.h"
#include "JsonProtocol.h"
#include "XmlProtocol.h"

Protocol::Protocol()
{
  LOG4CPLUS_TRACE(m_logger, "Memory allocated m_protocol: " << this);
}

Protocol::~Protocol()
{
  LOG4CPLUS_TRACE(m_logger, "Memory freed m_protocol: " << this);
}

Protocol* Protocol::create(DataFormat protocol)
{
  switch (protocol)
  {
  case DataFormat::JSON:
    return new JsonProtocol();
  case DataFormat::XML:
    return new XmlProtocol();
  }
}