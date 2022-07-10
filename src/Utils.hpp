#include <algorithm>
#include <bits/types/time_t.h>
#include <ctime>
#include <sched.h>
#include <string>
#include <sys/syscall.h>
#include <unistd.h>

namespace dan {

// 获取当前进程id
static pid_t getProcessId() { return getpid(); }
// 获取当前线程id
static pid_t getThreadId() { return syscall(SYS_gettid); }

/**
 * @param time 当前时间戳
 * @return std::string
 */
static std::string getCurrentTime(time_t time) {
  char buf[80];
  ::tm t;
  ::localtime_r(&time, &t);
  std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &t);
  return std::string(buf);
}

static std::string generateFileName(time_t time) {
  char buf[80];
  ::tm t;
  ::localtime_r(&time, &t);
  std::strftime(buf, sizeof(buf), "%Y%m%d", &t);
  return std::string(buf);
}

} // namespace dan