#include <iostream>
#include <vector>

void vector_exp()
{
	std::vector<int> nums{ 1,2,3,4 };
	nums.push_back(123);
	nums.insert(nums.begin(), nums.begin()+2, 1, 321);
	for (const auto& num : nums)
	{
		std::cout << num << '\n';
	}
}

void vector_capacity()
{
	int x = 4;
	std::vector <double> nums{ 1,2,3 };

	while (x < 15) {

		std::cout << "Initial vector capacity " << nums.capacity() << ".\n";
		std::cout << "Initial vector size " << nums.size() << ".\n";

		nums.push_back(x);
		std::cout << "after adding " <<x<<" vector capacity " << nums.capacity() << ".\n";
		std::cout << "after adding vector size " << nums.size() << ".\n";

		++x;
	}
	//erase elements
	std::cout << "before erase" << nums.at(0) << '\n';
	nums.erase(nums.begin());
	std::cout << "after erase" << nums.at(0) <<'\n';
	nums.erase(nums.begin() + 1, nums.begin() + 2);
}

