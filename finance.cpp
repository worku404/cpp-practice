#include <iostream>
#include<format>
#include <string>
const int SIZE = 5;
struct Stock {
	std::string name;
	double earning;
	double p_to_e_ratio;
};

Stock getData();
double price(const double& earning, const double& ratio);
int main() {
	Stock stocks[SIZE];

	for (int i = 0; i < SIZE; i++) {
		stocks[i] = getData();
		double p = price(stocks[i].earning, stocks[i].p_to_e_ratio);
		std::cout << std::format("The anticipated price for a share of {} is {}.\n", stocks[i].name, p);
	}

	return 0;
}

Stock getData() {
	Stock s;
	std::cout << "Enter Stock name: ";
	std::getline(std::cin >> std::ws, s.name);
	std::cout << "Enter earning: ";
	std::cin >> s.earning;
	std::cout << "Enter price per earning: ";
	std::cin >> s.p_to_e_ratio;
	return s;
}

double price(const double& earning, const double& ratio) {
	return earning * ratio;
}