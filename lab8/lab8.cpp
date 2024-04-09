//#include <iostream>
//#include <Windows.h>
//#include <sstream>
//
//template <typename T>
//T findMax(const T* array, int size) {
//    T max = array[0];
//    for (int i = 1; i < size; ++i) {
//        if (array[i] > max) {
//            max = array[i];
//        }
//    }
//    return max;
//}
//
//template <typename T>
//void sortArray(T* array, int size) {
//    for (int i = 0; i < size - 1; ++i) {
//        for (int j = 0; j < size - i - 1; ++j) {
//            if (array[j] > array[j + 1]) {
//                T temp = array[j];
//                array[j] = array[j + 1];
//                array[j + 1] = temp;
//            }
//        }
//    }
//}
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    // Пример работы с целыми числами
//    int intArray[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
//    int intArraySize = sizeof(intArray) / sizeof(intArray[0]);
//
//    std::cout << "Максимальный элемент в массиве intArray: " << findMax(intArray, intArraySize) << std::endl;
//
//    sortArray(intArray, intArraySize);
//    std::cout << "Отсортированный массив intArray: ";
//    for (int i = 0; i < intArraySize; ++i) {
//        std::cout << intArray[i] << " ";
//    }
//    std::cout << std::endl;
//
//    // Пример работы с вещественными числами
//    double doubleArray[] = { 3.14, 2.71, 1.61, 1.41 };
//    int doubleArraySize = sizeof(doubleArray) / sizeof(doubleArray[0]);
//
//    std::cout << "Максимальный элемент в массиве doubleArray: " << findMax(doubleArray, doubleArraySize) << std::endl;
//
//    sortArray(doubleArray, doubleArraySize);
//    std::cout << "Отсортированный массив doubleArray: ";
//    for (int i = 0; i < doubleArraySize; ++i) {
//        std::cout << doubleArray[i] << " ";
//    }
//    std::cout << std::endl;
//
//    return 0;
//}



#include <iostream>
#include <cstdlib> // Для использования функции rand()
#include <ctime>   // Для инициализации генератора случайных чисел
#include <Windows.h>
#include <sstream>

template<typename T, int size>
class ArraySum {
private:
    T array1[size];
    T array2[size];

public:
    ArraySum() {
        srand(time(nullptr));
        for (int i = 0; i < size; ++i) {
            array1[i] = static_cast<T>(rand() % 100);
            array2[i] = static_cast<T>(rand() % 100);
        }
    }

    //T sum() {
    //    T sum = 0;
    //    // Вычисление суммы элементов массивов
    //    for (int i = 0; i < size; ++i) {
    //        sum += array1[i];
    //        sum += array2[i];
    //    }
    //    return sum;
    //}

    virtual T sum() {
        T sum = 0;
        // Вычисление суммы элементов массивов
        for (int i = 0; i < size; ++i) {
            sum += array1[i];
            sum += array2[i];
        }
        return sum;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Пример работы с целыми числами
    ArraySum<int, 5> intArraySum;
    std::cout << "Сумма элементов массивов intArraySum: " << intArraySum.sum() << std::endl;

    // Пример работы с вещественными числами
    ArraySum<double, 3> doubleArraySum;
    std::cout << "Сумма элементов массивов doubleArraySum: " << doubleArraySum.sum() << std::endl;


    return 0;
}


//#include <iostream>
//#include <vector>
//#include <string>
//
//template<typename T>
//class Stack {
//private:
//    std::vector<T> elements;
//
//public:
//    void push(const T& element) {
//        elements.push_back(element);
//    }
//
//    T pop() {
//        if (elements.empty()) {
//            throw std::runtime_error("Stack is empty");
//        }
//        T element = elements.back();
//        elements.pop_back();
//        return element;
//    }
//
//    bool isEmpty() const {
//        return elements.empty();
//    }
//};
//
//struct Worker {
//    std::string surname;
//    int age;
//    std::string specialization;
//    double averageSalary;
//};
//
//int main() {
//    int numFactories;
//    std::cout << "Enter the number of factories: ";
//    std::cin >> numFactories;
//
//    Stack<Worker> workersStack;
//
//    for (int i = 0; i < numFactories; ++i) {
//        std::cout << "Factory " << i + 1 << ":" << std::endl;
//
//        int numWorkers;
//        std::cout << "Enter the number of workers: ";
//        std::cin >> numWorkers;
//
//        for (int j = 0; j < numWorkers; ++j) {
//            Worker worker;
//
//            std::cout << std::endl;
//            std::cout << "Worker " << j + 1 << ":" << std::endl;
//            std::cout << "Enter the worker's surname: ";
//            std::cin >> worker.surname;
//
//            std::cout << "Enter the worker's age: ";
//            std::cin >> worker.age;
//
//            std::cout << "Enter the worker's specialization: ";
//            std::cin.ignore();
//            std::getline(std::cin, worker.specialization);
//
//            std::cout << "Enter the worker's average salary: ";
//            std::cin >> worker.averageSalary;
//
//            workersStack.push(worker);
//        }
//    }
//
//    int numLocksmiths = 0;
//    int numTurners = 0;
//
//    while (!workersStack.isEmpty()) {
//        Worker worker = workersStack.pop();
//        if (worker.specialization == "locksmith") {
//            numLocksmiths++;
//        }
//        else if (worker.specialization == "turner") {
//            numTurners++;
//        }
//    }
//
//    std::cout << "Number of locksmiths: " << numLocksmiths << std::endl;
//    std::cout << "Number of turners: " << numTurners << std::endl;
//
//    return 0;
//}
