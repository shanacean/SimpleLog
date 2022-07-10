#include "../src/StdoutAppender.hpp"
#include "../src/Wrap.hpp"

using namespace dan;
int main(int argc, char *argv[]) {
  auto logger = LOG_ROOT();
  StdoutAppender *out_appender = new StdoutAppender();
  LogFormatter::ptr formatter(
      new LogFormatter("{%d} {%p} {%t} {%n} {%e} {%f} {%c} {%l} {%m}"));
  out_appender->setFormatter(formatter);
  logger->addAppender(out_appender);

  LOG_FATAL(logger) << "流式输出测试1";
  LOG_DEBUG(logger) << "流式输出测试2";
  LOG_ERROR(logger) << "流式输出测试3";

  delete out_appender;
  delete logger;
  return 0;
}