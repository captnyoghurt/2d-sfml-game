#include "RessourceException.h"

RessourceException::RessourceException(const std::string &description,
                                       const int &line, const std::string &file,
                                       const std::string &func,
                                       const std::string &filename,
                                       e_ExceptionLevel level) throw()
    : GameException(description, line, file, func, level) {
  append("Can't open file : " + filename);
}
