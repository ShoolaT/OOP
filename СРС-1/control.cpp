#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <Windows.h>
#include <thread>

using namespace std;

enum class DepositCategory {
    ORDINARY,
    VIP,
    BUSINESS
};

class Depositor {
private:
    string accountNumber;
    DepositCategory depositCategory;
    string passportData;
    double currentAmount;
    time_t lastOperationDate;

public:
    Depositor(string accNum, DepositCategory depCat, string passData, double currAmt) :
        accountNumber(accNum), depositCategory(depCat), passportData(passData), currentAmount(currAmt) {
        time(&lastOperationDate); // Устанавливаем текущую дату и время как дату последней операции
    }

    // Метод для приема суммы
    void deposit(double amount) {
        currentAmount += amount;
        time(&lastOperationDate);
        cout << "Сумма " << amount << " успешно зачислена на счет." << endl;
    }

    // Метод для выдачи суммы
    void withdraw(double amount) {
        if (amount <= currentAmount) {
            currentAmount -= amount;
            time(&lastOperationDate);

            char buffer[80];
            ctime_s(buffer, sizeof(buffer), &lastOperationDate);
            cout << "Дата последней операции: " << buffer;
            cout << "Сумма " << amount << " успешно выдана со счета. Время: " << buffer <<endl;
        }
        else {
            cout << "Ошибка: недостаточно средств на счете." << endl;
        }
    }

    //начисления процентов 
    void applyInterest(double rate) {
        double interest = currentAmount * rate / 100.0;
        currentAmount += interest;
        time(&lastOperationDate);

        char buffer[80];
        ctime_s(buffer, sizeof(buffer), &lastOperationDate);
        cout << "Проценты в размере " << interest << " успешно начислены. Время: " << buffer << endl;
    }

    // Метод для вывода информации о вкладчике
    void printInfo() {
        cout << "Номер счета: " << accountNumber << endl;
        cout << "Категория вклада: ";
        switch (depositCategory) {
        case DepositCategory::VIP:
            cout << "VIP" << endl;
            break;
        case DepositCategory::BUSINESS:
            cout << "Бизнес" << endl;
            break;
        default:
            cout << "Обычный" << endl;
            break;
        }
        cout << "Паспортные данные: " << passportData << endl;
        cout << "Текущая сумма вклада: " << currentAmount << endl;

        char buffer[80];
        ctime_s(buffer, sizeof(buffer), &lastOperationDate);
        cout << "Дата последней операции: " << buffer;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Создаем объекты вкладчиков 
    Depositor depositor1("123789", DepositCategory::ORDINARY, "1234567890", 5000.0);
    Depositor depositor2("984321", DepositCategory::VIP, "0987654321", 10000.0);

    cout << "Информация о вкладчике 1:" << endl;
    depositor1.printInfo();
    cout << endl;
    cout << "Информация о вкладчике 2:" << endl;
    depositor2.printInfo();
    cout << endl << endl;

    depositor1.deposit(1000.0);
    std::this_thread::sleep_for(std::chrono::seconds(10));
    depositor2.withdraw(2000.0);
    std::this_thread::sleep_for(std::chrono::seconds(12));
    depositor1.applyInterest(5.0);

    cout << "Информация о вкладчике 1:" << endl;
    depositor1.printInfo();
    cout << endl;
    cout << "Информация о вкладчике 2:" << endl;
    depositor2.printInfo();

    return 0;
}
