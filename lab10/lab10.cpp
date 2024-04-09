#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <Windows.h>

using namespace std;

class Shooting {
private:
    static double p;
public:
    static void setProbability(double probability) {
        if (probability >= 0 && probability <= 1) {
            p = probability;
        }
        else {
            throw invalid_argument("Ошибка: Вероятность должна быть в диапазоне от 0 до 1.");
        }
    }

    static int shootDown(int n) {
        if (p == 0) {
            throw logic_error("Ошибка: Вероятность попадания не установлена.");
        }

        srand(time(0));

        for (int i = 0; i < n; ++i) {
            if (rand() / (RAND_MAX + 1.0) < p) {
                cout << "Выстрел " << i + 1 << " попал " << endl;
                cout << "Оценочная вероятность поражения цели: " << Shooting::estimatedHitProbability(i + 1, p) << endl;
                return 1;
            }
            else {
                cout << "Выстрел " << i + 1 << " не попал, т.к. rand = 0" << endl;
            }
        }
        cout << "Выстрел не попал после " << n << " выстрелов" << endl;
        cout << "Оценочная вероятность поражения цели: " << Shooting::estimatedHitProbability(n, p) << endl;
        return 0;
    }

    static double estimatedHitProbability(int n, double p1) {
        if (p1 == 0) {
            throw logic_error("Ошибка: Вероятность попадания не установлена.");
        }
        return 1 - pow(1 - p1, n); // Оценочное значение вероятности поражения цели
    }
};

double Shooting::p = 0;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try {
        double probability = 0.1;
        int shots = 20;
        Shooting::setProbability(probability);
        cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "Вероятность: "<< probability << endl;
        cout << "Кол-во выстрелов: " << shots << endl<<endl<<endl;
        cout << "Результат стрельбы: " << Shooting::shootDown(shots) << endl;
        /*cout << "| Оценочная вероятность поражения цели: " << Shooting::estimatedHitProbability(shots) << endl;*/
        cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
    }
    catch (const exception& e) {
        cerr << "Исключение: " << e.what() << endl;
    }

    return 0;
}
