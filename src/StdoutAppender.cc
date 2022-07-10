#include "StdoutAppender.hpp"
#include <iostream>
namespace dan {

void StdoutAppender::append(LogEvent::ptr event) noexcept {
  std::cout << _formatter->format(event);
}

} // namespace dan
