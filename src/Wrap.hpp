#ifndef __DAN_WRAP_H
#define __DAN_WRAP_H

#include "Logger.hpp"
#include "LoggerManager.hpp"
#include "Utils.hpp"

// 获得root日志器
#define LOG_ROOT() dan::LoggerManager::getInstance()->getRoot()
// 释放单例
// #define LOG_DESTROY() dan::LoggerManager::deleteInstance()

// 宏简化日志输出
#define LOG_BASE(logger, level)                                                \
  if (level <= logger->getLevel())                                             \
  dan::Wrap(logger,                                                            \
            dan::LogEvent::ptr(new dan::LogEvent(                              \
                logger->getLoggerName(), level, time(0), getProcessId(),       \
                getThreadId(), __FILE__, __func__, __LINE__)))                 \
      .getLogEvent()                                                           \
      ->getMessage()

#define LOG_FATAL(logger) LOG_BASE(logger, dan::LogLevel::FATAL)
#define LOG_ERROR(logger) LOG_BASE(logger, dan::LogLevel::ERROR)
#define LOG_WARN(logger) LOG_BASE(logger, dan::LogLevel::WARN)
#define LOG_INFO(logger) LOG_BASE(logger, dan::LogLevel::INFO)
#define LOG_DEBUG(logger) LOG_BASE(logger, dan::LogLevel::DEBUG)
#define LOG_NOSET(logger) LOG_BASE(logger, dan::LogLevel::NOSET)

namespace dan {

class Wrap {
public:
  Wrap(Logger *logger, LogEvent::ptr event) : _logger(logger), _event(event) {}
  ~Wrap() { _logger->log(_event); }
  LogEvent::ptr getLogEvent() { return _event; }

private:
  Logger *_logger;
  LogEvent::ptr _event;
};

} // namespace dan
#endif //  __DAN_WRAP_H