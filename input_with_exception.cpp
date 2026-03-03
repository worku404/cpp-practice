#include <iostream>
#include <exception>

double get_number(std::istream& input_stream)
{
	double num{};
	input_stream >> num;

	if (input_stream)
	{
		return num;
	}

	throw std::exception{};
}