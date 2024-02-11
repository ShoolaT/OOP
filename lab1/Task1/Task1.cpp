#include <iostream>

double power(double n, int p);
double power(char n, int p);
double power(short int n, int p);
double power(long int n, int p);
double power(float n, int p);


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

	char charNum = static_cast<char>(num);
	answer = power(charNum, degree);
	std::cout << "Результат (char): " << answer << std::endl;

	short int shortNum = static_cast<short int>(num);
	answer = power(shortNum, degree);
	std::cout << "Результат (short int): " << answer << std::endl;

	long int longNum = static_cast<long int>(num);
	answer = power(longNum, degree);
	std::cout << "Результат (long int): " << answer << std::endl;

	float floatNum = static_cast<float>(num);
	answer = power(floatNum, degree);
	std::cout << "Результат (float): " << answer << std::endl;

	system("pause");
	return 0;
}
double power(double n, int p) {
	double ch = 1;

	for (int i = 1; i <= p; i++)
		ch = ch * n;
	return ch;
}
double power(char n, int p) {
	double num = static_cast<double>(n);
	return power(num, p);
}

double power(short int n, int p) {
	double num = static_cast<double>(n);
	return power(num, p);
}

double power(long int n, int p) {
	double num = static_cast<double>(n);
	return power(num, p);
}

double power(float n, int p) {
	double num = static_cast<double>(n);
	return power(num, p);
}