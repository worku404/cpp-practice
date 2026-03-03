#include <iostream>
#include <vector>
void vector_exp()
{
	std::vector nums{ 1,2,3,4 };
	for (const auto& num : nums)
	{
		std::cout << num;
	}
}