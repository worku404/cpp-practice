#include <iostream>
#include <math.h>
#include <format>
#include <string>

const int SIZE = 10;
//Q1
//////////////////////////////

struct Phone {
	int area_code, exchange, number;
};

Phone getPhone();
void display(const Phone&);

//////////////////////////////

//Q2
struct Person
{
	std::string name;
	Phone phone;
};

Person getPersonData();
void displayPerson(const Person&);

//Q3
struct ComplexNum {
	double realPart;
	double imaginaryPart;
};

ComplexNum addition(ComplexNum, ComplexNum);
ComplexNum subtract(ComplexNum n1, ComplexNum n2);
ComplexNum multiply(ComplexNum n1, ComplexNum n2);
ComplexNum divide(ComplexNum n1, ComplexNum n2);
inline void display(std::string op, ComplexNum n1, ComplexNum n2, ComplexNum r);
int main() {
	//Q1
	//Phone p1, p2;
	//p1 = { 211, 767, 8900 };
	//p2 = getPhone();

	//std::cout << "phone 1\n";
	//display(p1);

	//std::cout << "phone 2\n";
	//display(p2);

	////Q2
	//Person persons[SIZE];

	//for (int i = 0; i < SIZE; i++) {
	//	persons[i] = getPersonData();
	//}

	//for (Person p : persons) {
	//	displayPerson(p);
	//}

	ComplexNum n1;
	ComplexNum n2;
	n1.realPart = 3;
	n1.imaginaryPart = -4;

	n2.realPart = -5;
	n2.imaginaryPart = -10;
	ComplexNum result = addition(n1, n2);
	display("Addition of ", n1, n2, result);

	result = subtract(n1, n2);
	display("Subtraction of ", n1, n2, result);

	result = multiply(n1, n2);
	display("Multiplication of ", n1, n2, result);

	result = divide(n1, n2);
	display("Division of ", n1, n2, result);

	return 0;
}
//Q1
Phone getPhone() {
	Phone p;
	std::cout << "Enter area code: ";
	std::cin >> p.area_code;

	std::cout << "Enter Exchange: ";
	std::cin >> p.exchange;

	std::cout << "Enter Number: ";
	std::cin >> p.number;
	return p;
}

void display(const Phone& p) {
	std::cout << std::format("Phone number: ({}) {}-{}", p.area_code, p.exchange, p.number);
	std::cout << "\n";
}


//Q2
Person getPersonData() {
	Person p;
	std::cout << "Enter Your name: ";
	std::getline(std::cin >> std::ws, p.name);
	p.phone = getPhone();
	return p;
}

void displayPerson(const Person& p) {
		std::cout << std::format("Name: {}, ", p.name);
		display(p.phone);
}


//Q3
inline void display(const std::string& op, const ComplexNum& n1, const ComplexNum& n2, const ComplexNum& r) {
	std::cout << op << n1.realPart << (n1.imaginaryPart > 0 ? " +" : " ") << n1.imaginaryPart <<
		"i and " << n2.realPart << (n2.imaginaryPart > 0 ? " +" : " ") << n2.imaginaryPart << "i = ";

	std::cout << r.realPart << (r.imaginaryPart > 0 ? " +" : " ") <<r.imaginaryPart << 'i' << std::endl;
}
ComplexNum addition(const ComplexNum& n1, const ComplexNum& n2) {
	ComplexNum res;
	res.realPart = n1.realPart + n2.realPart;
	res.imaginaryPart = n1.imaginaryPart + n2.imaginaryPart;
	return res;
}

ComplexNum subtract(const ComplexNum& n1, const ComplexNum& n2) {
	ComplexNum res;
	res.realPart = n1.realPart - n2.realPart;
	res.imaginaryPart = n1.imaginaryPart - n2.imaginaryPart;
	return res;
}

// (a+bi) * (c+di) = (ac - bd) + (ad+bc)i
ComplexNum multiply(const ComplexNum& n1, const ComplexNum& n2) {
	ComplexNum res;
	res.realPart = (n1.realPart * n2.realPart) - (n1.imaginaryPart * n2.imaginaryPart);
	res.imaginaryPart = (n1.realPart * n2.imaginaryPart) + (n1.imaginaryPart * n2.realPart);
	return res;
}

// (a+bi) / (c+di) = (ac + bd) - (bc-ad)i / c2+d2
ComplexNum divide(const ComplexNum& n1, const ComplexNum& n2) {
	ComplexNum res;
	double denominator = std::pow(n2.realPart, 2) + std::pow(n2.imaginaryPart, 2);

	if (denominator == 0) {
		std::cout << "division by zero!";
		return;
	}

	double ac_bd = (n1.realPart * n2.realPart) + (n1.imaginaryPart * n2.imaginaryPart);
	double ad_bc = (n1.imaginaryPart * n2.realPart) - (n1.realPart * n2.imaginaryPart);
	res.realPart = ac_bd / denominator;
	res.imaginaryPart = ad_bc / denominator;
	return res;
}