#include <iostream>
#include <limits>
#include <string>

const int MAX_ACC = 100;

// Structure for Bank Account
struct Account {
    int accNumber;
    std::string name;
    float balance;
};

// helper functions
void clear_bad_input(std::istream& in);
std::string read_name(std::ostream& out, const std::string& desc, std::istream& in);
float read_num(std::ostream& out, const std::string& desc, std::istream& in);

// main functions
void create_account(Account acc[], int* count);
void display_accounts(Account acc[], int count);
void deposit(Account acc[], int count);
void withdraw(Account acc[], int count);
void check_balance(Account acc[], int count);

// main function
int main() {
    Account acc[MAX_ACC];
    int count = 0;
    int choice;

    do {
        std::cout << "\n======= Banking System =========\n"
            << "1. Create Account\n"
            << "2. Display Accounts\n"
            << "3. Deposit\n"
            << "4. Withdraw\n"
            << "5. Check Balance\n"
            << "0. Exit\n"
            << "> ";

        std::cin >> choice;

        if (!std::cin) {
            clear_bad_input(std::cin);
            continue;
        }

        switch (choice) {
        case 1:
            create_account(acc, &count);
            break;
        case 2:
            display_accounts(acc, count);
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
            std::cout << "Goodbye!\n";
            break;
        default:
            std::cout << "Invalid choice\n";
        }

    } while (choice != 0);

    return 0;
}

// clear bad input
void clear_bad_input(std::istream& in) {
    in.clear();
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input. Try again.\n";
}

// read name
std::string read_name(std::ostream& out, const std::string& desc, std::istream& in) {
    std::string name;

    while (true) {
        out << desc;
        std::getline(in >> std::ws, name);

        if (!name.empty()) {
            return name;
        }

        out << "Invalid name. Try again.\n";
    }
}

// read number
float read_num(std::ostream& out, const std::string& desc, std::istream& in) {
    float num;

    while (true) {
        out << desc;
        in >> num;

        if (in) {
            return num;
        }

        clear_bad_input(in);
    }
}

// Create account
void create_account(Account acc[], int* count) {
    if (*count >= MAX_ACC) {
        std::cout << "Cannot add more accounts\n";
        return;
    }

    int accNum = (int)read_num(std::cout, "Enter Account Number: ", std::cin);

    // check duplicate
    for (int i = 0; i < *count; i++) {
        if (acc[i].accNumber == accNum) {
            std::cout << "Account already exists!\n";
            return;
        }
    }

    acc[*count].accNumber = accNum;
    acc[*count].name = read_name(std::cout, "Enter Name: ", std::cin);
    acc[*count].balance = read_num(std::cout, "Enter Initial Balance: ", std::cin);

    (*count)++;
    std::cout << "Account created successfully!\n";
}

// display all accounts
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

// Deposit money
void deposit(Account acc[], int count) {
    int num = (int)read_num(std::cout, "Enter Account Number: ", std::cin);

    for (int i = 0; i < count; i++) {
        if (acc[i].accNumber == num) {

            float amount = read_num(std::cout, "Enter amount to deposit: ", std::cin);

            if (amount > 0) {
                acc[i].balance += amount;
                std::cout << "Deposit successful!\n";
            }
            else {
                std::cout << "Invalid amount\n";
            }
            return;
        }
    }
    std::cout << "Account not found!\n";
}

// Withdraw money
void withdraw(Account acc[], int count) {
    int num = (int)read_num(std::cout, "Enter Account Number: ", std::cin);

    for (int i = 0; i < count; i++) {
        if (acc[i].accNumber == num) {

            float amount = read_num(std::cout, "Enter amount to withdraw: ", std::cin);

            if (amount <= 0) {
                std::cout << "Invalid amount!\n";
            }
            else if (amount > acc[i].balance) {
                std::cout << "Insufficient balance!\n";
            }
            else {
                acc[i].balance -= amount;
                std::cout << "Withdrawal successful!\n";
            }
            return;
        }
    }
    std::cout << "Account not found\n";
}

// Check balance
void check_balance(Account acc[], int count) {
    int num = (int)read_num(std::cout, "Enter Account Number: ", std::cin);

    for (int i = 0; i < count; i++) {
        if (acc[i].accNumber == num) {
            std::cout << "Account Holder: " << acc[i].name << "\n"
                << "Balance: " << acc[i].balance << "\n";
            return;
        }
    }
    std::cout << "Account not found!\n";
}