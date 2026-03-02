// input_experiment.cpp
#include <iostream>
#include <limits> // Required for std::numeric_limits

//int main() {
//    // Finds the maximum possible value for a double on the current system
//    const double largest = std::numeric_limits<double>::max()~~;
//    // Prompts the user, showing the maximum allowed number
//    std::cout << "Please enter a number up to " << largest << ".\n>";
//
//    double number{}; // Declares and initializes a double variable
//    std::cin >> number; // Attempts to extract a number from input
//
//    std::cout << number << '\n'; // Prints the number that was read
//
//    // Checks if there's any remaining input in the stream
//    // that isn't just a newline character (from pressing Enter)
//    if(!std::cin.eof() && std::cin.peek()!='\n') {
//        std::cout << "Unused input\n"; // Reports if extra characters were left
//    }
//
//    return 0;
//}