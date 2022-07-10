#ifndef __DAN_LOGFORMAT_H
#define __DAN_LOGFORMAT_H

#include "LogEvent.hpp"
#include <memory>
#include <string>

namespace dan {

class LogFormatter {
public:
  typedef std::shared_ptr<LogFormatter> ptr;
  LogFormatter(std::string fmt = "{%n} {%d} {%p} {%t} {%e} {%f} {%l} {%c} {%m}");
  std::string format(LogEvent::ptr event);

private:
  std::string _fmt;
};

} // namespace dan
#endif //  __DAN_LOGFORMAT_H