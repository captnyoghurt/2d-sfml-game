#include "InitializationException.h"

InitializationException::InitializationException(const std::string &description,
                                                 const int &line,
                                                 const std::string &file,
                                                 const std::string &func,
                                                 e_ExceptionLevel level)
    : GameException(description, line, file, func, level) {
  append("Object not initiate");
}