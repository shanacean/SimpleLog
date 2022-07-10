#include "../src/FileAppender.hpp"
#include "../src/Wrap.hpp"
#include <ctime>

using namespace dan;

int main(int argc, char *argv[]) {
  auto logger = LOG_ROOT();
  LogFormatter::ptr formatter(
      new LogFormatter("{%d} {%p} {%t} {%n} {%e} {%f} {%c} {%l} {%m}"));
  FileAppender *file_appender = new FileAppender();
  file_appender->setFormatter(formatter);
  logger->addAppender(file_appender);

  time_t start, end;
  start = time(NULL);
  while (true) {
    end = time(NULL);
    if (difftime(end, start) >= 1.0)
      break;
    LOG_ERROR(logger) << "log test";
  }

  delete file_appender;
  delete logger;
  return 0;
}