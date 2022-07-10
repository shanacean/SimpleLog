#ifndef __DAN_LOGEVENT_H
#define __DAN_LOGEVENT_H

#include "LogLevel.hpp"
#include <cstdint>
#include <ctime>
#include <memory>
#include <sstream>
#include <string>
namespace dan {

class LogEvent {
public:
  typedef std::shared_ptr<LogEvent> ptr;
  LogEvent(const std::string &loggerName, LogLevel level, time_t timestamp,
           uint32_t pid, uint32_t tid, std::string file, std::string func,
           uint32_t line) noexcept;

  std::string getLoggerName() const { return _loggerName; }

  LogLevel getLogLevel() const { return _level; }

  uint32_t getProcessId() { return _processId; }

  uint32_t getThreadId() { return _threadId; }

  uint32_t getLine() const { return _line; }

  time_t getTimeStamp() const { return _timestamp; }

  std::string getFunc() const { return _func; }

  std::string getFile() const { return _file; }

  std::stringstream &getMessage() { return _message; }

private:
  std::string _loggerName;
  time_t _timestamp;
  LogLevel _level;
  uint32_t _processId;
  uint32_t _threadId;
  std::string _file;
  std::string _func;
  uint32_t _line;
  std::stringstream _message;
};

} // namespace dan
#endif //  __DAN_LOGEVENT_H