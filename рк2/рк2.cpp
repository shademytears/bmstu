//============================================================================
// Name        : рк2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;


class BankAccount {
private:
    string number;
    string ownerName;
    double balance;

public:

    BankAccount(string accnum, string name, double initialBalance) {
        number = accnum;
        ownerName = name;
        balance = initialBalance;
    }


    void deposit(double amount) {
        balance += amount;
        cout << "Пополнено: " << amount << " баланс: " << balance << " руб." << endl;
    }


    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "снято: " << amount << " баланс: " << balance << " руб." << endl;
        }
        else {
            cout << "ошибка: недостаточно средств" << endl;
        }
    }


    void display() {
        cout << "счет: " << number << endl;
        cout << "владелец: " << ownerName << endl;
        cout << "баланс: " << balance << " руб." << endl;
    }
};


class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:

    SavingsAccount(string accnum, string name, double initialBalance, double rate)
        : BankAccount(accnum, name, initialBalance) {
        interestRate = rate;
    }


    void applyInterest() {
        double currentBalance;

        cout << "начисление процентов по ставке " << interestRate << "%" << endl;

    }

    void display() {
        BankAccount::display();
        cout << "процентная ставка: " << interestRate << "%" << endl;
    }
};

int main() {
    cout << "банковская система" << endl;

    cout << "обычный банковский счет:" << endl;
    BankAccount account1("12345", "Вечялсав Вечялсаловович", 1000);
    account1.display();

    account1.deposit(500);
    account1.withdraw(200);
    account1.withdraw(2000);


    cout << "сберегательный счет:" << endl;
    SavingsAccount account2("54321", "Петр Петров", 5000, 5.5);
    account2.display();


    account2.deposit(1000);
    account2.withdraw(500);
    account2.applyInterest();

    return 0;
}
