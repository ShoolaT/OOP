//#include <iostream>
//using namespace std;
//#include <process.h>
//const int LIMIT = 100;
//#include <string>
//#include <Windows.h>
//
//class safearray {
//private:
//    int arr[LIMIT];
//public:
//    void putel(int n, int elvalue) {
//        if (n < 0 || n >= LIMIT) {
//            cout << "\nОшибочный индекс";
//            exit(1);
//        }
//        arr[n] = elvalue;
//    }
//
//    int getel(int n) const {
//        if (n < 0 || n >= LIMIT) {
//            cout << "\nОшибочный индекс";
//            exit(1);
//        }
//        return arr[n];
//    }
//};
//
//int main(){
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    safearray sal; 
//
//    for (int j = 0; j < LIMIT; j++) {
//        sal.putel(j, j * 10);
//    }
//
//    for (int j = 0; j < LIMIT; j++) {
//        int temp = sal.getel(j);
//        cout << "Элемент " << j << " равен " << temp << endl;
//    }
//
//    return 0;
//}

//#include <iostream>
//#include <string>
//#include <Windows.h>
//using namespace std;
//
//const int LIMIT = 100;
//
//class ArrayIndexOutOfBoundsException : public exception {
//public:
//    const char* what() const throw() {
//        return "Array index out of bounds!";
//    }
//};
//
//class safearray {
//private:
//    int arr[LIMIT];
//public:
//    void putel(int n, int elvalue) {
//        if (n < 0 || n >= LIMIT) {
//            throw ArrayIndexOutOfBoundsException();
//        }
//        arr[n] = elvalue;
//    }
//
//    int getel(int n) const {
//        if (n < 0 || n >= LIMIT) {
//            throw ArrayIndexOutOfBoundsException();
//        }
//        return arr[n];
//    }
//};
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    safearray sal;
//
//    try {
//        for (int j = 0; j < LIMIT; j++) { //блок повторных попыток
//            sal.putel(j, j * 10);
//        }
//
//        for (int j = 0; j < LIMIT; j++) {
//            int temp = sal.getel(j);
//            cout << "Элемент " << j << " равен " << temp << endl;
//        }
//    }
//    catch (const ArrayIndexOutOfBoundsException& e) { //обработчик ошибок
//        cout << "Поймано исключение: " << e.what() << endl;
//    }
//
//    return 0;
//}



#include <iostream>
#include <string>
#include <locale>
#include <iomanip>
#include <stdexcept>

using namespace std;

class Kamaz;

class Tatra {
private:
    string name;
    double speed;
public:
    Tatra(string n, double s) : name(n), speed(s) {}
    void display() const {
        cout << "| " << setw(24) << left << ("Татра " + name) << "| " << setw(15) << left << speed << "|" << endl;
    }
    double getSpeed() const {
        return speed;
    }

    void testAccess(const Kamaz& kamaz);
};

class Kamaz {
private:
    string name;
    double speed;
public:
    Kamaz(string n, double s) : name(n), speed(s) {}
    void display() const {
        cout << "| " << setw(24) << left << ("Камаз " + name) << "| " << setw(15) << left << speed << "|" << endl;
    }
    double getSpeed() const {
        return speed;
    }

    friend void Tatra::testAccess(const Kamaz& kamaz);
};

void Tatra::testAccess(const Kamaz& kamaz) {
    throw runtime_error("Access to Kamaz's speed denied!"); // генерация исключанния
}

int main() {
    setlocale(LC_ALL, "Russian");

    const int size = 3;

    Kamaz kamaz[size] = {
        Kamaz("Равнина", 100),
        Kamaz("Гора", 110),
        Kamaz("Пустыня", 150)
    };

    Tatra tatra[size] = {
        Tatra("Равнина", 150),
        Tatra("Гора", 100),
        Tatra("Пустыня", 100)
    };

    try {
        tatra[0].testAccess(kamaz[0]);
    }
    catch (const runtime_error& e) {
        cout << "Поймано исключение: " << e.what() << endl;
    }

    return 0;
}
