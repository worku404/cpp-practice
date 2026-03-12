@pragma once
#include "utilities.h"
#include <string>
#include <iosfwd>

Status run_once(const std::string& line, std::ostream&  out);
void repl(std::istream& in, std::ostream& out);
