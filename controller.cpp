#include "controller.h"
#include <istream>
#include <ostream>
#include <string>

Status run_once(const std::string& line, std::ostream& out) {
    (void)line;
    Status status = make_error("Controller pipeline not implemented yet", 0)
        out << "error: "<<status.message<<"\n";
    return status;
}

void repl(std::istream& in, std::ostream& out) {
    std::string line;
    while (std::getline(in, line)) {
        run_once(line, out);
    }
}
