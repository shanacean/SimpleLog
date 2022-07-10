#ifndef __DAN_APPENDER_H
#define __DAN_APPENDER_H

#include "LogFormatter.hpp"
#include <mutex>
#include <string>

namespace dan {

// 日志输出地
class Appender {
public:
  virtual ~Appender() {}

  /**
   * @param msg 日志输出信息
   */
  virtual void append(LogEvent::ptr event) = 0;
  void setFormatter(LogFormatter::ptr formatter) { _formatter = formatter; }

protected:
  std::mutex _mutex;
  LogFormatter::ptr _formatter; // 日志格式
};

} // namespace dan

#endif //  __DAN_APPENDER_H