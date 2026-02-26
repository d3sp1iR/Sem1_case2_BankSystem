#ifndef BANK_H
#define BANK_H

#include "BankAccount.h"
#include <vector>
#include <string>

class Bank {
private:
    std::vector<BankAccount> accounts; // Хранилище счетов
    int nextAccountNumber; // Простой способ генерации номеров

    // Вспомогательный метод для генерации уникального номера счета
    std::string generateAccountNumber();

public:
    Bank(); // Сам конструктор

    // Основные методы банка
    void createAccount(const std::string& owner, double initialDeposit = 0.0);
    BankAccount* getAccount(const std::string& accNum); // Возвращает указатель на счет или nullptr
    double totalBankBalance() const;
    void listAllAccounts() const; // Для наглядности
};

#endif // BANK_H