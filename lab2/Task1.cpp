//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <iomanip>
//
//class Aeroflot {
//public:
//    int flightNumber;
//    std::string departurePoint;
//    std::string destinationPoint;
//    std::string arrivalTime;
//    std::string departureTime;
//    int registrationSection;
//
//    // Class constructor
//    Aeroflot(int number, const std::string& departure, const std::string& destination,
//        const std::string& arrival, const std::string& departureTime, int section)
//        : flightNumber(number),
//        departurePoint(departure),
//        destinationPoint(destination),
//        arrivalTime(arrival),
//        departureTime(departureTime),
//        registrationSection(section) {}
//
//    void displayFlightInfo() const {
//        std::cout << "| " << std::setw(13) << flightNumber << " | " << std::setw(18) << departurePoint
//            << " | " << std::setw(22) << destinationPoint << " | " << std::setw(14) << arrivalTime
//            << " | " << std::setw(17) << departureTime << " | " << std::setw(21) << registrationSection << " |" << std::endl;
//    }
//
//    static void displayTableHeader() {
//        std::cout << "\n****************************************************************************************************************************" << std::endl;
//        std::cout << "| Flight Number |   Departure Point  |   Destination Point    |  Arrival Time  |   Departure Time  | Registration Section  |" << std::endl;
//        std::cout << "----------------------------------------------------------------------------------------------------------------------------" << std::endl;
//    }
//
//    static void displayTableFooter() {
//        std::cout << "****************************************************************************************************************************" << std::endl;
//    }
//};
//
//bool compareByDestination(const Aeroflot& a, const Aeroflot& b) {
//    return a.destinationPoint < b.destinationPoint;
//}
//
//int main() {
//    std::vector<Aeroflot> flights; 
//
//    int numFlights;
//    std::cout << "Enter the number of flights: ";
//    std::cin >> numFlights;
//
//    for (int i = 0; i < numFlights; ++i) {
//        int number, section;
//        std::string departure, destination, arrival, departureTime;
//
//        std::cout << std::endl;
//        std::cout << "Enter the flight number: ";
//        std::cin >> number;
//
//        std::cout << "Enter the departure point: ";
//        std::cin >> departure;
//
//        std::cout << "Enter the destination point: ";
//        std::cin >> destination;
//
//        std::cout << "Enter the arrival time: ";
//        std::cin >> arrival;
//
//        std::cout << "Enter the departure time: ";
//        std::cin >> departureTime;
//
//        std::cout << "Enter the registration section number: ";
//        std::cin >> section;
//
//        flights.emplace_back(number, departure, destination, arrival, departureTime, section);
//    }
//
//    std::sort(flights.begin(), flights.end(), compareByDestination);
//
//    Aeroflot::displayTableHeader();
//
//    for (const auto& flight : flights) {
//        flight.displayFlightInfo();
//    }
//
//    if (flights.empty()) {
//        std::cout << "No available flights." << std::endl;
//    }
//
//    Aeroflot::displayTableFooter();
//
//    return 0;
//}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//class Student {
//public:
//    std::string firstName;
//    std::string lastName;
//    std::string birthDate;
//    std::string phoneNumber;
//
//    // Конструктор класса Student
//    Student(const std::string& first, const std::string& last, const std::string& birth, const std::string& phone)
//        : firstName(first), lastName(last), birthDate(birth), phoneNumber(phone) {}
//
//    // Вывод информации о студенте
//    void displayStudentInfo() const {
//        std::cout << "Name: " << firstName << " " << lastName << "\tBirthdate: " << birthDate << "\tPhone: " << phoneNumber << std::endl;
//    }
//};
//
//class StudentGroup {
//private:
//    std::vector<Student> students;
//
//public:
//    void addStudent(const Student& student) {
//        students.push_back(student);
//    }
//
//    void removeStudentByLastName(const std::string& lastName) {
//        students.erase(std::remove_if(students.begin(), students.end(),
//            [lastName](const Student& student) { return student.lastName == lastName; }), students.end());
//    }
//
//    void findStudentByLastName(const std::string& lastName) const {
//        for (const auto& student : students) {
//            if (student.lastName == lastName) {
//                std::cout << "Student found: ";
//                student.displayStudentInfo();
//                return;
//            }
//        }
//        std::cout << "Student with last name '" << lastName << "' not found." << std::endl;
//    }
//
//    void sortStudentsByLastName() {
//        std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
//            return a.lastName < b.lastName;
//            });
//    }
//
//    void displayAllStudents() const {
//        std::cout << "\nAll students in the group:\n";
//        for (const auto& student : students) {
//            student.displayStudentInfo();
//        }
//        std::cout << std::endl;
//    }
//};
//
//int main() {
//    StudentGroup group;
//
//    group.addStudent(Student("Shoola", "Tabyldieva", "01-02-2003", "234566543345"));
//    group.addStudent(Student("Ksenia", "Park", "12-02-2004", "23456765433456"));
//    group.addStudent(Student("Alex", "Johnson", "14-06-2003", "3456788765"));
//
//    int choice;
//    std::string lastName;
//
//    do {
//        std::cout << "\n****************************";
//        std::cout << "\nStudent Group Menu:\n"
//            << "1. Display all students\n"
//            << "2. Add student\n"
//            << "3. Remove student by last name\n"
//            << "4. Find student by last name\n"
//            << "5. Sort students by last name\n"
//            << "6. Exit\n";
//            std::cout << "****************************" << std::endl;
//
//            std::cout<< "Enter your choice: ";
//        std::cin >> choice;
//        std::cout << std::endl;
//
//        switch (choice) {
//        case 1:
//            group.displayAllStudents();
//            break;
//
//        case 2:
//        {
//            std::string first, last, birth, phone;
//            std::cout << "Enter student information:\n";
//            std::cout << "First name: ";
//            std::cin >> first;
//            std::cout << "Last name: ";
//            std::cin >> last;
//            std::cout << "Birthdate: ";
//            std::cin >> birth;
//            std::cout << "Phone number: ";
//            std::cin >> phone;
//            group.addStudent(Student(first, last, birth, phone));
//            std::cout << "Student added successfully.\n";
//        }
//        break;
//
//        case 3:
//            std::cout << "Enter the last name of the student to remove: ";
//            std::cin >> lastName;
//            group.removeStudentByLastName(lastName);
//            std::cout << "Student removed successfully.\n";
//            break;
//
//        case 4:
//            std::cout << "Enter the last name of the student to find: ";
//            std::cin >> lastName;
//            group.findStudentByLastName(lastName);
//            break;
//
//        case 5:
//            group.sortStudentsByLastName();
//            std::cout << "Students sorted by last name.\n";
//            break;
//
//        case 6:
//            std::cout << "Exiting the program.\n";
//            break;
//
//        default:
//            std::cout << "Invalid choice. Please enter a valid option.\n";
//            break;
//        }
//
//    } while (choice != 0);
//
//    return 0;
//}

#include <iostream>
#include <fstream>
#include <stack>

class TrainStation {
private:
    std::stack<int> leftDirection; 
    std::stack<int> rightDirection;

public:
    void addWagon(int type) {
        if (type == 1) {
            leftDirection.push(type);
            std::cout << "Wagon of type 1 added to the left direction.\n";
        }
        else if (type == 2) {
            rightDirection.push(type);
            std::cout << "Wagon of type 2 added to the right direction.\n";
        }
        else {
            std::cout << "Invalid wagon type.\n";
        }
    }

    void sendTrain() {
        std::cout << "\nSending trains...\n";

        while (!leftDirection.empty()) {
            std::cout << "Train going left with wagon type " << leftDirection.top() << "\n";
            leftDirection.pop();
        }

        while (!rightDirection.empty()) {
            std::cout << "Train going right with wagon type " << rightDirection.top() << "\n";
            rightDirection.pop();
        }
    }
};

int main() {
    TrainStation station;

    int wagonType;
    int choice;

    do {
        std::cout << "\n****************************";
        std::cout << "\nTrain Station Menu:\n"
            << "1. Add wagon\n"
            << "2. Send trains\n"
            << "0. Exit\n";
            std::cout << "****************************" << std::endl;
            std::cout<< "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter wagon type (1 or 2): ";
            std::cin >> wagonType;
            station.addWagon(wagonType);
            break;

        case 2:
            station.sendTrain();
            break;

        case 0:
            std::cout << "Exiting the program.\n";
            break;

        default:
            std::cout << "Invalid choice. Please enter a valid option.\n";
            break;
        }

    } while (choice != 0);

    return 0;
}
