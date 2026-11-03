#include "Protocol.h"
#include "JsonProtocol.h"
#include "XmlProtocol.h"

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