#ifndef __DAN_LOGGERMANAGER_H
#define __DAN_LOGGERMANAGER_H

#include "./Logger.hpp"
#include <map>
#include <memory>
#include <mutex>
#include <string>
namespace dan {

// 单例模式管理器
class LoggerManager {
public:
  typedef std::shared_ptr<LoggerManager> ptr;
  LoggerManager() {}
  ~LoggerManager() {}
  /**
   * @return LoggerManager* 返回单例
   */
  static LoggerManager *getInstance();

  static void deleteInstance();
  /**
   * @return Logger* 返回根日志器
   */
  Logger *getRoot();
  /**
   * @param name 日志器名
   * @return Logger*
   */
  Logger *getLogger(const std::string &name);

private:
  LoggerManager(const LoggerManager &) = delete;
  LoggerManager &operator=(const LoggerManager &) = delete;

  // 自动释放_loggerManager
  class GC {
  public:
    ~GC() {
      if (LoggerManager::_loggerManager) {
        LoggerManager::deleteInstance();
      }
    }
  };

  std::mutex _mutex;
  static GC gc;
  static LoggerManager *_loggerManager;
  Logger *_root = NULL;
  std::map<std::string, Logger *> _loggers;
};

} // namespace dan
#endif //  __DAN_LOGGERMANAGER_H