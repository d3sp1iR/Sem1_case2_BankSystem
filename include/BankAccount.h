#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include <iostream>

class BankAccount {
private:
    // Поля класса (инкапсуляция)
    std::string accountNumber;
    std::string ownerName;
    double balance;

public:
    // Конструктор (может быть с параметрами по умолчанию)
    BankAccount(const std::string& owner = "Unknown", const std::string& accNum = "0000", double initialBalance = 0.0);

    // Методы для работы со счетом
    void deposit(double amount);
    bool withdraw(double amount); // Возвращает true, если снятие прошло успешно
    double getBalance() const; // const означает, что метод не меняет объект
    void printStatement() const;

    // Геттер для номера счета, чтобы можно было искать счета в банке
    std::string getAccountNumber() const;
    std::string getOwnerName() const;
};

#endif // BANKACCOUNT_H

//усё