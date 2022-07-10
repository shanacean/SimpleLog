#include "Logger.hpp"

namespace dan {

Logger::Logger(const std::string &name, LogLevel level)
    : _name(std::move(name)), _level(level) {}

void Logger::log(LogEvent::ptr event) {
  if (event->getLogLevel() > _level)
    return;
  for (auto &app : _appenders) {
    app->append(event);
  }
}

} // namespace dan