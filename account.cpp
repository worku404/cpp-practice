#include <iostream>
#include <string>

const int MAX_ACC = 100;

// Structure for Bank Account
struct Account {
	int accNumber;
	std::string name;
	float balance;
};

// functions
void create_account(Account acc[], int* count);
void display_account(Account acc[], int count);
void deposit(Account acc[], int count);
void withdraw(Account acc[], int count);
void check_balance(Account acc[], int count);

//main funtion
int main() {
	Account acc[MAX_ACC];
	int count = 0;
	int choice;

	do {
		std::cout << "\n======= Banking System =========\n"
			<<"1, Create Account\n"
			<<"2, Diplay Accounts\n"
			<<"3, Deposit\n"
			<<"4, Withdraw\n"
			<<"Check Balance\n"
			<<"0, exit\n"
			<<"> ";
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			create_account(acc, &count);
			break;
		case 2:
			display_account(acc, count);
			break;
		case 3:
			deposit(acc, count);
			break;
		case 4:
			withdraw(acc, count);
			break;
		case 5:
			check_balance(acc, count);
			break;
		case 0:
			std::cout << "Goodbay!\n";
			break;
		default:
			std::cout << "Invalid choice\n";
			break;
		}
	} while (choice != 0);

	return 0;
}

//Create account
void create_account(Account acc[], int* count) {
	if (*count >= MAX_ACC) {
		std::cout << "Cannot add more accounts\n";
		return;
	}
	std::cout << "Enter Account Number: ";
	std::cin >> acc[*count].accNumber;

	std::cout << "Enter Name: ";
	std::cin.ignore();
	std::getline(std::cin, acc[*count].name);

	std::cout << "Enter Initial Balance: ";
	std::cin >> acc[*count].balance;

	(*count)++;
	std::cout << "Account created successfully!\n";
}

// diplay all accounts
void display_accounts(Account acc[], int count) {
	if (count == 0) {
		std::cout << "No accounts available!\n";
		return;
	}

	std::cout << "\n========= Account List ==========\n";
	for (int i = 0; i < count; i++) {
		std::cout << "Account No: " << acc[i].accNumber << "\n"
			<< "Name: " << acc[i].name << "\n"
			<< "Balance: " << acc[i].balance << "\n"
			<< "-----------------------------\n";
	}
}

