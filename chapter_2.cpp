// chapter_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "input_with_test.h"
#include <iostream>

int main()
{
    test_code();
    double number{};
	std::cout << "Please enter a number: ";

	const bool ok = get_number(std::cin, number);
    if (ok)
    {
		std::cout << "You entered: " << number << '\n';
    }
    else {
        std::cout << "something went wrong\n";
    }
    
    //std::cout << sum(2, 4);
}
