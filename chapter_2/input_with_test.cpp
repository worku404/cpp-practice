// input_with_tests.cpp
#include <cassert> // Required for the assert macro (used for basic testing)
#include <iostream> // Will likely be needed for input/output in future functions
#include <sstream> //This is to check input from the consule other that the keyboard
#include "input_with_test.h"
bool get_number(std::istream& input, double& number)
{
    input >> number;
    if (input) {
        return true;
    }
    return false;
}
void test_code() {
    // double value{};
    std::stringstream some_input{ "1" };
    // const bool ok=get_number(some_input, value);
    // assert (ok);
    // assert(value == 1);

    double unused{};
    const bool not_ok = get_number(some_input, unused);

    assert(not_ok);
    assert(unused == 1);

}




