#ifndef __DAN_STDOUTAPPENDER_H
#define __DAN_STDOUTAPPENDER_H

#include "Appender.hpp"

namespace dan {

// 控制台输出日志
class StdoutAppender : public Appender {
public:
  StdoutAppender() = default;
  StdoutAppender(const StdoutAppender &) = delete;
  virtual ~StdoutAppender() {}
  void append(LogEvent::ptr event) noexcept override;

  StdoutAppender &operator=(const StdoutAppender &) = delete;
};

} // namespace dan
#endif //  __DAN_STDOUTAPPENDER_H