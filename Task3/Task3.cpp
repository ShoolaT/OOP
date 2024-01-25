#include <iostream>
#include <vector>
#include <string>

struct Worker {
    std::string surname;
    int age;
    std::string specialization;
    double averageSalary;
};

int main() {

    int numFactories;
    std::cout << "Enter the number of factories: ";
    std::cin >> numFactories;

    std::vector<Worker> workers;

    for (int i = 0; i < numFactories; ++i) {
        std::cout << "Factory " << i + 1 << ":" << std::endl;

        int numWorkers;
        std::cout << "Enter the number of workers: ";
        std::cin >> numWorkers;

        for (int j = 0; j < numWorkers; ++j) {
            Worker worker;

            std::cout << std::endl;
            std::cout << "Worker " << j + 1 << ":" << std::endl;
            std::cout << "Enter the worker's surname: ";
            std::cin >> worker.surname;

            std::cout << "Enter the worker's age: ";
            std::cin >> worker.age;

            std::cout << "Enter the worker's specialization: ";
            std::cin.ignore();
            std::getline(std::cin, worker.specialization);

            std::cout << "Enter the worker's average salary: ";
            std::cin >> worker.averageSalary;

            workers.push_back(worker);
        }
    }

    int numLocksmiths = 0;
    int numTurners = 0;

    for (const Worker& worker : workers) {
        if (worker.specialization == "locksmith") {
            numLocksmiths++;
        }
        else if (worker.specialization == "turner") {
            numTurners++;
        }
    }

    std::cout << "Number of locksmiths: " << numLocksmiths << std::endl;
    std::cout << "Number of turners: " << numTurners << std::endl;

    return 0;
}
