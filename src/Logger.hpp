#ifndef __DAN_LOGGER_H
#define __DAN_LOGGER_H

#include "Appender.hpp"
#include "LogEvent.hpp"
#include "LogLevel.hpp"
#include <list>
#include <memory>
#include <mutex>
#include <string>

namespace dan {

// 日志器
class Logger {
public:
  typedef std::shared_ptr<Logger> ptr;
  /**
   * @param name 日志器名称
   */
  Logger(const std::string &name = "", LogLevel level = LogLevel::DEBUG);
  /**
   * @return const std::string 获取日志器名
   */
  const std::string getLoggerName() { return _name; }

  void setLevel(LogLevel level) { _level = level; }

  LogLevel getLevel() { return _level; }

  void addAppender(Appender *appender) {
    std::lock_guard lock(_mutex);
    _appenders.emplace_back(appender);
  }

  void clearAppender(Appender *appender) {
    std::lock_guard lock(_mutex);
    _appenders.clear();
  }

  void log(LogEvent::ptr event);

  Logger(const Logger &) = delete;
  Logger &operator=(const Logger &) = delete;

private:
  std::mutex _mutex;
  std::string _name;                // 日志器名
  LogLevel _level;                  // 日志级别
  std::list<Appender *> _appenders; // 输出地
};

} // namespace dan
#endif //  __DAN_LOGGER_H