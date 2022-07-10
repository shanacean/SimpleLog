#ifndef __DAN_FILEAPPENDER_H
#define __DAN_FILEAPPENDER_H

#include "Appender.hpp"
#include <fstream>
#include <string>

namespace dan {

// 文件输出日志
class FileAppender : public Appender {
public:
  /**
   * @param path 文件路径
   */
  FileAppender(const std::string &path = "");
  FileAppender(const FileAppender &) = delete;
  virtual ~FileAppender();
  virtual void append(LogEvent::ptr event) noexcept override;

  FileAppender &operator=(const FileAppender &) = delete;

private:
  // 文件路径
  std::string _filepath;
  // 文件流
  std::ofstream _file;
};

} // namespace dan
#endif //  __DAN_FILEAPPENDER_H