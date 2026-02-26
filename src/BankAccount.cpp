#include "BankAccount.h"
#include <iomanip> // для форматирования вывода (setprecision)

// Реализация конструктора
BankAccount::BankAccount(const std::string& owner, const std::string& accNum, double initialBalance)
    : ownerName(owner), accountNumber(accNum), balance(initialBalance) {
    // Тело конструктора может быть пустым, так как инициализация сделана через список инициализации
    if (balance < 0) {
        balance = 0; // Защита от отрицательного баланса при создании
    }
}

// Реализация метода deposit
void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        std::cout << "  Успешно внесено: " << amount << " на счет " << accountNumber << std::endl;
    } else {
        std::cout << "  Ошибка: Сумма внесения должна быть положительной." << std::endl;
    }
}

// Реализация метода withdraw
bool BankAccount::withdraw(double amount) {
    if (amount <= 0) {
        std::cout << "  Ошибка: Сумма снятия должна быть положительной." << std::endl;
        return false;
    }
    if (amount > balance) {
        std::cout << "  Ошибка: Недостаточно средств на счете " << accountNumber << ". Доступно: " << balance << std::endl;
        return false;
    }
    balance -= amount;
    std::cout << "  Успешно снято: " << amount << " cc счета " << accountNumber << std::endl;
    return true;
}

// Реализация getBalance
double BankAccount::getBalance() const {
    return balance;
}

// Реализация printStatement
void BankAccount::printStatement() const {
    std::cout << "  Владелец: " << ownerName << std::endl;
    std::cout << "  Номер счета: " << accountNumber << std::endl;
    // Фиксируем формат вывода для double (округляем до двух знаков после запятой)
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "  Баланс: " << balance << std::endl;
}

// Реализация getAccountNumber
std::string BankAccount::getAccountNumber() const {
    return accountNumber;
}

std::string BankAccount::getOwnerName() const {
    return ownerName;
}