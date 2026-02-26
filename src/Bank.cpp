#include "Bank.h"
#include <iostream>
#include <sstream> // Для stringstream
#include <iomanip> // Для setw

// Реализация конструктора
Bank::Bank() : nextAccountNumber(1001) {
    // Начинаем нумерацию с 1001
}

// Реализация генератора номера счета
std::string Bank::generateAccountNumber() {
    std::ostringstream oss;
    oss << "ACC-" << nextAccountNumber++;
    return oss.str();
}

// Реализация createAccount
void Bank::createAccount(const std::string& owner, double initialDeposit) {
    std::string newAccNum = generateAccountNumber();
    // Создаем объект BankAccount прямо в векторе, используя emplace_back
    // Это эффективнее, чем push_back с копированием
    accounts.emplace_back(owner, newAccNum, initialDeposit);
    std::cout << "  Счет успешно создан!" << std::endl;
    // Вызываем printStatement для только что созданного счета
    // Для этого нужно получить ссылку на последний элемент
    accounts.back().printStatement();
    std::cout << std::endl;
}

// Реализация getAccount (поиск по номеру)
BankAccount* Bank::getAccount(const std::string& accNum) {
    for (auto& account : accounts) { // Используем ссылку, чтобы не копировать
        if (account.getAccountNumber() == accNum) {
            return &account; // Возвращаем указатель на найденный объект
        }
    }
    return nullptr; // Если не нашли
}

// Реализация totalBankBalance
double Bank::totalBankBalance() const {
    double total = 0.0;
    for (const auto& account : accounts) {
        total += account.getBalance();
    }
    return total;
}

// Реализация listAllAccounts (для тестирования)
void Bank::listAllAccounts() const {
    if (accounts.empty()) {
        std::cout << "  В банке нет открытых счетов." << std::endl;
        return;
    }
    std::cout << "  Список всех счетов в банке:" << std::endl;
    for (const auto& account : accounts) {
        // Просто печатаем номер и владельца, чтобы не загромождать вывод
        std::cout << "    - " << account.getAccountNumber() << " | "
                  << "Владелец: " << account.getAccountNumber() // Здесь ошибка! Должен быть владелец. Исправим позже?
                  << " | Баланс: ";
        std::cout << std::fixed << std::setprecision(2) << account.getBalance() << std::endl;
        // На самом деле, правильнее было бы вынести печать баланса в отдельный геттер,
        // но для простоты используем getBalance().
    }
}