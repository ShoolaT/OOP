//#include <iostream>
//#include <string>
//#include <locale>
//#include <iomanip>
//
//using namespace std;
//
//class Kamaz {
//private:
//    string name;
//    double speed;
//public:
//    Kamaz(string n, double s) : name(n), speed(s) {}
//    void display() const {
//        cout << "| " << setw(24) << left << ("Камаз " + name) << "| " << setw(15) << left << speed << "|" << endl;
//    }
//    double getSpeed() const {
//        return speed;
//    }
//};
//
//class Tatra {
//private:
//    string name;
//    double speed;
//public:
//    Tatra(string n, double s) : name(n), speed(s) {}
//    void display() const {
//        cout << "| " << setw(24) << left << ("Татра " + name) << "| " << setw(15) << left << speed << "|" << endl;
//    }
//    double getSpeed() const {
//        return speed;
//    }
//};
//
//int FrCreater(const Kamaz& kamaz, const Tatra& tatra) {
//    double kamazSpeed = kamaz.getSpeed();
//    double tatraSpeed = tatra.getSpeed();
//
//    if (kamazSpeed > tatraSpeed)
//        return 1;
//    else if (kamazSpeed == tatraSpeed)
//        return 0;
//    else
//        return -1;
//}
//
//void displayResults(const Kamaz kamaz[], const Tatra tatra[], int size) {
//    cout << "+------------------------------------------+" << endl;
//    cout << "|   Таблица результатов ралли-марафона:    |" << endl;
//    cout << "+------------------------------------------+" << endl;
//    cout << "|  Грузовик               |     Скорость   |" << endl;
//    cout << "|------------------------------------------|" << endl;
//
//    for (int i = 0; i < size; ++i) {
//        kamaz[i].display();
//        tatra[i].display();
//        if (i < size-1) {
//            cout << "+------------------------------------------+" << endl;
//        }
//    }
//    cout << "+------------------------------------------+" << endl;
//
//    int kamazTotalSpeed = 0;
//    int tatraTotalSpeed = 0;
//    for (int i = 0; i < size; ++i) {
//        int result = FrCreater(kamaz[i], tatra[i]);
//        if (result == 1)
//            kamazTotalSpeed++;
//        else if (result == -1)
//            tatraTotalSpeed++;
//    }
//    if (kamazTotalSpeed > tatraTotalSpeed)
//        cout << "Победитель: Камаз" << endl;
//    else if (kamazTotalSpeed < tatraTotalSpeed)
//        cout << "Победитель: Татра" << endl;
//    else
//        cout << "Нет явного победителя" << endl;
//}
//
//int main() {
//    setlocale(LC_ALL, "Russian");
//
//    const int size = 3;
//
//    Kamaz kamaz[size] = {
//        Kamaz("Равнина", 100),
//        Kamaz("Гора", 110),
//        Kamaz("Пустыня", 150)
//    };
//
//    Tatra tatra[size] = {
//        Tatra("Равнина", 150),
//        Tatra("Гора", 100),
//        Tatra("Пустыня", 100)
//    };
//
//    displayResults(kamaz, tatra, size);
//
//    return 0;
//}

//#include <iostream>
//#include <string>
//#include <locale>
//#include <iomanip>
//
//using namespace std;
//
//class Kamaz;
//
//class Tatra {
//private:
//    string name;
//    double speed;
//public:
//    Tatra(string n, double s) : name(n), speed(s) {}
//    void display() const {
//        cout << "| " << setw(24) << left << ("Татра " + name) << "| " << setw(15) << left << speed << "|" << endl;
//    }
//    double getSpeed() const {
//        return speed;
//    }
//    friend int FrCreater(const Kamaz& kamaz, const Tatra& tatra);
//};
//
//class Kamaz {
//private:
//    string name;
//    double speed;
//public:
//    Kamaz(string n, double s) : name(n), speed(s) {}
//    void display() const {
//        cout << "| " << setw(24) << left << ("Камаз " + name) << "| " << setw(15) << left << speed << "|" << endl;
//    }
//    double getSpeed() const {
//        return speed;
//    }
//    friend int FrCreater(const Kamaz& kamaz, const Tatra& tatra);
//};
//
//int FrCreater(const Kamaz& kamaz, const Tatra& tatra) {
//    double kamazSpeed = kamaz.getSpeed();
//    double tatraSpeed = tatra.getSpeed();
//
//    if (kamazSpeed > tatraSpeed)
//        return 1;
//    else if (kamazSpeed == tatraSpeed)
//        return 0;
//    else
//        return -1;
//}
//
//void displayResults(const Kamaz kamaz[], const Tatra tatra[], int size) {
//    cout << "+------------------------------------------+" << endl;
//    cout << "|   Таблица результатов ралли-марафона:    |" << endl;
//    cout << "+------------------------------------------+" << endl;
//    cout << "|  Грузовик               |     Скорость   |" << endl;
//    cout << "|------------------------------------------|" << endl;
//
//    for (int i = 0; i < size; ++i) {
//        kamaz[i].display();
//        tatra[i].display();
//        if (i < size - 1) {
//            cout << "+------------------------------------------+" << endl;
//        }
//    }
//    cout << "+------------------------------------------+" << endl;
//
//    int kamazTotalSpeed = 0;
//    int tatraTotalSpeed = 0;
//    for (int i = 0; i < size; ++i) {
//        int result = FrCreater(kamaz[i], tatra[i]);
//        if (result == 1)
//            kamazTotalSpeed++;
//        else if (result == -1)
//            tatraTotalSpeed++;
//    }
//    if (kamazTotalSpeed > tatraTotalSpeed)
//        cout << "Победитель: Камаз" << endl;
//    else if (kamazTotalSpeed < tatraTotalSpeed)
//        cout << "Победитель: Татра" << endl;
//    else
//        cout << "Нет явного победителя" << endl;
//}
//
//int main() {
//    setlocale(LC_ALL, "Russian");
//
//    const int size = 3;
//
//    Kamaz kamaz[size] = {
//        Kamaz("Равнина", 100),
//        Kamaz("Гора", 110),
//        Kamaz("Пустыня", 150)
//    };
//
//    Tatra tatra[size] = {
//        Tatra("Равнина", 150),
//        Tatra("Гора", 100),
//        Tatra("Пустыня", 100)
//    };
//
//    displayResults(kamaz, tatra, size);
//
//    return 0;
//}
#include <iostream>
#include <string>
#include <locale>
#include <iomanip>

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
    cout << "Tatra has access to Kamaz's speed: " << kamaz.speed << endl;
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

    tatra[0].testAccess(kamaz[0]);

    return 0;
}
