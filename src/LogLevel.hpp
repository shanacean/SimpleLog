#ifndef __DAN_LOGLEVEL_H
#define __DAN_LOGLEVEL_H

#include <string>
namespace dan {

enum LogLevel {
  FATAL,
  ERROR,
  WARN,
  INFO,
  DEBUG,
  NOSET,
};

/**
 * @param level 日志级别
 * @return const char*
 */
static std::string toString(LogLevel level) {
  switch (level) {
#define XX(name)                                                               \
  case LogLevel::name:                                                         \
    return #name;
    XX(FATAL)
    XX(ERROR)
    XX(WARN)
    XX(INFO)
    XX(DEBUG)
#undef XX
  default:
    return "NOSET";
  }
}

/**
 * @param str level对应字符串
 * @return LogLevel
 */
static LogLevel fromString(const std::string &str) {
#define XX(level, s)                                                           \
  if (str == #s) {                                                             \
    return LogLevel::level;                                                    \
  }
  XX(FATAL, FATAL)
  XX(ERROR, ERROR)
  XX(WARN, WARN)
  XX(INFO, INFO)
  XX(DEBUG, DEBUG)
#undef XX
  return LogLevel::NOSET;
}

} // namespace dan
#endif //  __DAN_LOGLEVEL_H