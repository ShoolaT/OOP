//#include <iostream>
//#include <string>
//
//class Employee {
//protected:
//    std::string name;
//    std::string position;
//    double salary;
//
//public:
//    // Default constructor
//    Employee() : name(""), position(""), salary(0.0) {}
//
//    // Parameterized constructor
//    Employee(const std::string& empName, const std::string& empPosition, double empSalary)
//        : name(empName), position(empPosition), salary(empSalary) {}
//
//    // Destructor
//    virtual ~Employee() {}
//
//    // Calculate annual salary
//    double calculateAnnualSalary() const {
//        return salary * 12;
//    }
//
//    // Display information about the employee
//    void displayInfo() const {
//        std::cout << "+-------------------------------+" << std::endl;
//        std::cout << "Name: " << name << std::endl;
//        std::cout << "Position: " << position << std::endl;
//        std::cout << "Monthly Salary: $" << salary << std::endl;
//        std::cout << "Annual Salary: $" << calculateAnnualSalary() << std::endl;
//        std::cout << "+-------------------------------+" << std::endl;
//    }
//};
//
//class Manager : public Employee {
//private:
//    double annual_bonus;
//    std::string company_car;
//    int stock_options;
//
//public:
//    // Default constructor
//    Manager() : Employee(), annual_bonus(0.0), company_car(""), stock_options(0) {}
//
//    // Parameterized constructor
//    Manager(const std::string& empName, const std::string& empPosition, double empSalary,
//        double bonus, const std::string& car, int options)
//        : Employee(empName, empPosition, empSalary), annual_bonus(bonus),
//        company_car(car), stock_options(options) {}
//
//    // Destructor
//    ~Manager() {}
//
//    // Display information about the manager
//    void displayManagerInfo() const {
//        displayInfo(); 
//        std::cout << "Annual Bonus: $" << annual_bonus << std::endl;
//        std::cout << "Company Car: " << company_car << std::endl;
//        std::cout << "Stock Options: " << stock_options << std::endl;
//        std::cout << "+-------------------------------+" << std::endl;
//    }
//};
//
//int main() {
//    // Test Employee class
//    Employee employee("John Doe", "Developer", 5000.0);
//    employee.displayInfo();
//
//    std::cout << "\n";
//
//    // Test Manager class
//    Manager manager("Jane Smith", "Manager", 8000.0, 2000.0, "Company Car", 100);
//    manager.displayManagerInfo();
//
//    return 0;
//}





// Task 2
//#include <iostream>
//#include <cstring>
//
//class Display {
//private:
//    char type[32];
//    long colors;
//    int x_resolution;
//    int y_resolution;
//
//public:
//    // Parameterized constructor
//    Display(const char* displayType, long displayColors, int resolutionX, int resolutionY)
//        : colors(displayColors), x_resolution(resolutionX), y_resolution(resolutionY) {
//        strcpy_s(type, displayType);
//    }
//
//    const long getColors() const {
//                return colors;
//            }
//
//    // Display information about the Display
//    void displayInfo() const {
//        std::cout << "Display Type: " << type << std::endl;
//        std::cout << "Colors: " << colors << std::endl;
//        std::cout << "Resolution: " << x_resolution << "x" << y_resolution << std::endl;
//    }
//};
//
//class MotherBoard {
//protected:
//    int processor;
//    int speed;
//    int RAM;
//
//public:
//    // Parameterized constructor
//    MotherBoard(int processorType, int processorSpeed, int memoryRAM)
//        : processor(processorType), speed(processorSpeed), RAM(memoryRAM) {}
//
//    // Display information about the MotherBoard
//    void displayInfo() const {
//        std::cout << "Processor Type: " << processor << std::endl;
//        std::cout << "Processor Speed: " << speed << " GHz" << std::endl;
//        std::cout << "RAM: " << RAM << " GB" << std::endl;
//    }
//};
//class MotherB {
//protected:
//    int processor;
//  
//
//public:
//    // Parameterized constructor
//    MotherB(int processorType)
//        : processor(processorType){}
//
//    // Display information about the MotherBoard
//    void displayInfo() const {
//        std::cout << "Processor Type: " << processor << std::endl;
//        
//    }
//};
//
//class Computer : private Display, public MotherBoard, public MotherB {
//private:
//    char name[64];
//    int hard_disk;
//
//public:
//    // Parameterized constructor
//    Computer(const char* computerName, const char* displayType, long displayColors,
//        int resolutionX, int resolutionY, int processorType, int processorSpeed,
//        int memoryRAM, int processorT, int diskSize)
//        : Display(displayType, displayColors, resolutionX, resolutionY),
//        MotherBoard(processorType, processorSpeed, memoryRAM), MotherB(processorT), hard_disk(diskSize) {
//        strcpy_s(name, computerName);
//    }
//
//    // Display information about the Computer
//    void show() const {
//        std::cout << "COLORS FROM PARENT: " << this->getColors() << std::endl;
//        std::cout << "Computer Name: " << name << std::endl;
//        Display::displayInfo();  // Display information from Display
//        MotherBoard::displayInfo();
//        std::cout << "Hard Disk Size: " << hard_disk << " GB" << std::endl;
//
//
//        MotherB::displayInfo();
//    }
//};
//
//int main() {
//
//    Computer myComputer("Dell", "LED", 16777216, 1366, 768, 1, 3, 8,1999, 512);
//    myComputer.show();
//
//    return 0;
//}




//////////////////////////

// Task 3
#include <iostream>
#include <string>

class Employee {
private:
    std::string name;
    std::string position;
    double salary;


public:
    // Default constructor
    Employee() : name(""), position(""), salary(0.0) {}

    // Parameterized constructor
    Employee(const std::string& empName, const std::string& empPosition, double empSalary)
        : name(empName), position(empPosition), salary(empSalary) {}

    // Destructor
    virtual ~Employee() {}

    // Calculate annual salary
    double calculateAnnualSalary() const {
        return salary * 12;
    }


    // Display information about the employee
    void displayInfo() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Position: " << position << std::endl;
        std::cout << "Monthly Salary: $" << salary << std::endl;
        std::cout << "Annual Salary: $" << calculateAnnualSalary() << std::endl;
    }

    const std::string& getName() const {
        return name;
    }
};

class Manager : private Employee {
private:
    double annual_bonus;
    std::string company_car;
    int stock_options;

public:
    // Default constructor
    Manager() : Employee(), annual_bonus(0.0), company_car(""), stock_options(0) {}

    // Parameterized constructor
    Manager(const std::string& empName, const std::string& empPosition, double empSalary,
        double bonus, const std::string& car, int options)
        : Employee(empName, empPosition, empSalary), annual_bonus(bonus),
        company_car(car), stock_options(options) {}

    // Destructor
    ~Manager() {}

    // Display information about the manager
    void displayManagerInfo() const {
        displayInfo();  // Inherited from the base class
        std::cout << "Name FROM MANAGER CLASS: " << this->getName() << std::endl;

        std::cout << "Annual Bonus: $" << annual_bonus << std::endl;
        std::cout << "Company Car: " << company_car << std::endl;
        std::cout << "Stock Options: " << stock_options << std::endl;
    }
};

int main() {
    // Test Employee class
    Employee employee("John Doe", "Developer", 5000.0);
    employee.displayInfo();


    std::cout << "\n";

    // Test Manager class
    Manager manager("Jane Smith", "Manager", 8000.0, 2000.0, "Company Car", 100);
    manager.displayManagerInfo();

    return 0;
}