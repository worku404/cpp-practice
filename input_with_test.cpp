#include <cassert> 
#include <iostream>  
#include <sstream>  



#include "input_with_test.h"
[[nodiscard]]
bool get_number(std::istream& input, double& number)
{
    input >> number;
    if (input) {
        std::cout << "correct!\n";
        return true;
    }
    return false;
}

void some_experiments()
{
    double number{};
    bool ok = get_number(std::cin, number);
    std::cout << ok << '\n';
}

void test_code() {
     double value{};
    std::stringstream some_input{ "1" };
     const bool ok=get_number(some_input, value);
     assert (ok);
     assert(value == 1);

    double unused{};
    std::stringstream some_input{ "q" };
    const bool ok = get_number(some_input, unused);

    assert(!ok);
    //assert(unused == 1);

}




