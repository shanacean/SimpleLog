#include "FileAppender.hpp"
#include "Utils.hpp"
#include <mutex>
#include <string.h>

namespace dan {

FileAppender::FileAppender(const std::string &path)
    : _filepath(std::move(path)) {
  if (_filepath.empty()) {
    _filepath = "log_" + generateFileName(time(NULL));
  }
  _file.open(_filepath.c_str(), std::ios_base::app);
}

FileAppender::~FileAppender() { _file.close(); }

void FileAppender::append(LogEvent::ptr event) noexcept {
  std::string msg = _formatter->format(event);
  std::lock_guard lock(_mutex);
  _file.write(msg.c_str(), msg.length());
  _file.flush();
}

} // namespace dan