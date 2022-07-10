#include "LogFormatter.hpp"
#include "Utils.hpp"
#include <iostream>
#include <string>

namespace dan {

LogFormatter::LogFormatter(std::string fmt) : _fmt(std::move(fmt)) {}

std::string LogFormatter::format(LogEvent::ptr event) {
  std::string res;
  size_t len = _fmt.length();
  for (size_t i = 0; i < len; i++) {
    if (_fmt[i] == '%' && i < len - 1) {
      switch (_fmt[i + 1]) {
      case 'n':
        res.append('[' + event->getLoggerName() + ']');
        break;
      case 'd':
        res.append('[' + getCurrentTime(event->getTimeStamp()) + ']');
        break;
      case 'e': 
		res.append('[' + toString(event->getLogLevel()) + ']');
        break;
      case 'p':
        res.append("[pid=" + std::to_string(getProcessId()) + ']');
        break;
      case 't':
        res.append("[tid=" + std::to_string(getThreadId()) + ']');
        break;
      case 'f':
        res.append("[path=" + event->getFile() + ']');
        break;
      case 'c':
        res.append("[func=" + event->getFunc() + ']');
        break;
      case 'l':
        res.append('[' + std::to_string(event->getLine()) + ']');
        break;
      case 'm':
        res.append(event->getMessage().str());
        break;
      default:
        res.push_back(_fmt[i + 1]);
      }
      ++i;
      continue;
    }
    if (_fmt[i] != '{' && _fmt[i] != '}')
      res.push_back(_fmt[i]);
  }
  res.push_back('\n');
  return res;
}

} // namespace dan
