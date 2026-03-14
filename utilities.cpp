#include "utilities.h"

Status make_ok() {
    Status status;
    status.success = true;
    status.message = "";
    status.err_position = 0;
    return status;
}

Status make_error(const std::string& message, std::size_t err_position) {
    return Status{false, message, err_position}
}
