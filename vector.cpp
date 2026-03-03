#include <iostream>
#include <vector>

void vector_exp()
{
	std::vector<int> nums{ 1,2,3,4 };
	nums.push_back(123);
	nums.insert(2+nums.begin(), 321);
	for (const auto& num : nums)
	{
		std::cout << num << '\n';
	}
}