@pragma once
#include <cstddef>
#include <string>
// This is the first Declaration that will be shared by all other files
// it defined how to represent success , failer how do carrey error message
// how do carry the error possition..
struct Status{
    bool success;
    std::string message;
    std::size_t err_position;
};
Status make_ok();
Status make_error(const std::string& message, size_t err_position);
inline bool is_ok(const Status& status) {
    return status.success;
}
