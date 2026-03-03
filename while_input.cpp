#include <iostream>
#include <limits>
#include <exception>
#include <string>

double get_number(std::istream& input)
{
	double num{};
	input >> num;
	if (input)
	{
		return num;
	}
	input.clear();
	input.ignore(
		std::numeric_limits<std::streamsize>::max(), '\n'
	);
	throw std::exception{};
}