#include <iostream>

double power(double n, int p);


int main()
{
	setlocale(LC_ALL, "RUS");
	int degree;
	double num, answer;
	int inputAnswer;

	std::cout << "Введите число: ";
	std::cin >> num;

	std::cout << "Хотите возвести в степень число?(1- да, 0 - нет): ";
	std::cin >> inputAnswer;

	if (inputAnswer == 1) {
		do {
			std::cout << "Введите степень числа (> 2): ";
			std::cin >> degree;

			if (degree <= 2) {
				std::cerr << "Ошибка: Введите степень, большую чем 2." << std::endl;
			}
		} while (degree <= 2);
	}
	else {
		degree = 2;
	}

	answer = power(num, degree);
	std::cout << "Результат: " << answer << std::endl;

	system("pause");
	return 0;
}
double power(double n, int p) {
	double ch = 1;

	if (p == 0) {
		n = 1;
	}
	else {
		for (int i = 1; i <= p; i++)
			ch = ch * n;
	}
	return ch;
}