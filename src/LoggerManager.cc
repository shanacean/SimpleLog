#include "./LoggerManager.hpp"
#include <algorithm>
#include <memory>
#include <mutex>
#include <new>

namespace dan {

LoggerManager *LoggerManager::_loggerManager = new LoggerManager();

LoggerManager *LoggerManager::getInstance() { return _loggerManager; }

LoggerManager::GC LoggerManager::gc;

void LoggerManager::deleteInstance() { delete _loggerManager; }

Logger *LoggerManager::getRoot() {
  if (!_root)
    _root = new Logger("root");
  return _root;
}

Logger *LoggerManager::getLogger(const std::string &name) {
  const std::lock_guard lock(_mutex);
  auto it = _loggers.find(name);
  if (it == _loggers.end()) {
    _loggers[name] = new Logger(name);
  }
  return _loggers[name];
}

} // namespace dan