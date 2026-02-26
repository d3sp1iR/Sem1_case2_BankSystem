#include <iostream>
#include <string>

// Подключаем заголовочные файлы наших классов
#include "BankAccount.h"
#include "Bank.h"

int main() {
    std::cout << "==========================================" << std::endl;
    std::cout << "     СИСТЕМА БАНКОВСКИХ СЧЕТОВ v1.0" << std::endl;
    std::cout << "==========================================" << std::endl;
    std::cout << std::endl;

    // 1. Создаем объект банка
    Bank myBank;

    // 2. Создаем несколько счетов
    std::cout << "--- Создание счетов ---" << std::endl;
    myBank.createAccount("Иван Петров", 5000.0);
    myBank.createAccount("Мария Соколова", 10000.0);
    myBank.createAccount("Петр Сидоров", 1500.50);

    // 3. Выводим общий баланс банка
    std::cout << "--- Общий баланс банка ---" << std::endl;
    std::cout << "Общий баланс всех счетов: " << myBank.totalBankBalance() << std::endl;
    std::cout << std::endl;

    // 4. Поиск счета и операции с ним
    std::cout << "--- Операции со счетом Ивана Петрова ---" << std::endl;
    // Здесь нужно будет вписать реальный номер счета после первого запуска
    BankAccount* ivanAccount = myBank.getAccount("ACC-1001"); // Предполагаем, что первый счет получит этот номер
    if (ivanAccount) {
        ivanAccount->printStatement();
        ivanAccount->deposit(2000.0);
        ivanAccount->withdraw(1000.0);
        ivanAccount->withdraw(10000.0); // Проверка на недостаток средств
        std::cout << "Текущий баланс Ивана: " << ivanAccount->getBalance() << std::endl;
    } else {
        std::cout << "Счет не найден!" << std::endl;
    }
    std::cout << std::endl;

    // 5. Проверяем, изменился ли общий баланс банка
    std::cout << "--- Обновленный общий баланс банка ---" << std::endl;
    std::cout << "Общий баланс всех счетов: " << myBank.totalBankBalance() << std::endl;
    std::cout << std::endl;

    // 6. Попытка найти несуществующий счет
    std::cout << "--- Поиск несуществующего счета ---" << std::endl;
    BankAccount* fakeAccount = myBank.getAccount("ACC-9999");
    if (!fakeAccount) {
        std::cout << "Ошибка: Счет ACC-9999 не найден (ожидаемое поведение)." << std::endl;
    }

    std::cout << std::endl;
    std::cout << "==========================================" << std::endl;
    std::cout << "     ТЕСТИРОВАНИЕ ЗАВЕРШЕНО" << std::endl;
    std::cout << "==========================================" << std::endl;

    return 0;
}