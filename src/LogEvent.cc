#include "LogEvent.hpp"

namespace dan {
LogEvent::LogEvent(const std::string &loggerName, LogLevel level,
                   time_t timestamp, uint32_t pid, uint32_t tid,
                   std::string file, std::string func, uint32_t line) noexcept
    : _loggerName(loggerName), _level(level), _timestamp(timestamp),
      _processId(pid), _threadId(tid), _file(file), _func(func), _line(line) {}
} // namespace dan