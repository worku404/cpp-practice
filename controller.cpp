#include "controller.h"
#include <ostream>

Status run_once(const std::string& line, std::ostream& out) {
    (void)line;
    Status status = make_error("Controller pipeline not implemented yet", 0)
        out << "error: "<<status.message<<"\n";
    return status;
}
