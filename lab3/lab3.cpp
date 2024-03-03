 //task 1
//#include <iostream>
//#include <windows.h>
//#include <string>
//#include <chrono>
//#include <thread>
//
//class Timer {
//private:
//    int seconds;
//
//public:
//    Timer(int initialseconds) : seconds(initialseconds) {}
//
//    Timer(const std::string& timestring) {
//        parsetimestring(timestring);
//    }
//
//    Timer(int minutes, int seconds) : seconds(minutes * 60 + seconds) {}
//
//    void run() {
//        while (seconds > 0) {
//            displaytime();
//            delay(1000);  // delay for 1000 milliseconds (1 second)
//            seconds--;
//        }
//
//        std::cout << "timer expired. beep beep beep!\n";
//        playsound();
//    }
//
//private:
//    void parsetimestring(const std::string& timestring) {
//        size_t pos1 = timestring.find(':');
//        size_t pos2 = timestring.rfind(':');
//
//        int hours = std::stoi(timestring.substr(0, pos1));
//        int minutes = std::stoi(timestring.substr(pos1 + 1, pos2 - pos1 - 1));
//        int secs = std::stoi(timestring.substr(pos2 + 1));
//
//        seconds = hours * 3600 + minutes * 60 + secs;
//    }
//
//    void displaytime() const {
//        int hours = seconds / 3600;
//        int minutes = (seconds % 3600) / 60;
//        int secs = seconds % 60;
//
//        std::cout << "time remaining: " << hours << "h " << minutes << "m " << secs << "s\n";
//    }
//
//    void delay(int milliseconds) {
//        auto start = std::chrono::steady_clock::now();
//        while (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count() < milliseconds);
//    }
//
//   
//    void playsound() const {
//        Beep(1000, 500); 
//    }
//};
//
//int main() {
//    Timer timer1(5);
//    Timer timer2("00:00:03");
//    Timer timer3(0, 3);
//
//    timer1.run();
//    timer2.run();
//    timer3.run();
//
//    return 0;
//}



// Task 2
//#include <iostream>
//#include <string>
//
//class Nomenclature {
//private:
//    std::string itemName;
//    double wholesalePrice;
//    double retailMarkup;
//    int stockQuantity;
//
//public:
//    Nomenclature(const std::string& name, double wholesale, double markup, int quantity)
//        : itemName(name), wholesalePrice(wholesale), retailMarkup(markup), stockQuantity(quantity) {}
//
//    ~Nomenclature() {
//        std::cout << "Object for item '" << itemName << "' has been destroyed.\n";
//    }
//
//    double calculateNetIncome(int soldQuantity) const {
//        double netIncome = (retailMarkup - wholesalePrice) * soldQuantity;
//        return netIncome;
//    }
//
//    void displayItemDetails() const {
//        std::cout << "Item Name: " << itemName << "\n";
//        std::cout << "Wholesale Price: " << wholesalePrice << "\n";
//        std::cout << "Retail Markup: " << retailMarkup << "\n";
//        std::cout << "Stock Quantity: " << stockQuantity << "\n";
//    }
//};
//
//int main() {
//    Nomenclature item("Product", 30, 50, 80);
//
//    std::cout << "Item Details:\n";
//    item.displayItemDetails();
//
//    int soldQuantity = 20;
//    double netIncome = item.calculateNetIncome(soldQuantity);
//    std::cout << "Net Income for selling " << soldQuantity << " items: " << netIncome << "\n";
//
//    return 0;
//}


// Task 3
//#include <iostream>
//#include <string>
//#include <ctime>
//
//class soft {
//private:
//    std::string programname;
//    std::string developer;
//    double occupiedspace;
//    time_t licenseexpirationdate;
//
//public:
//    soft(const std::string& name, const std::string& dev, double space, const std::string& expirationdate)
//        : programname(name), developer(dev), occupiedspace(space) {
//        tm expirationdatestruct = parsedate(expirationdate);
//        licenseexpirationdate = mktime(&expirationdatestruct);
//    }
//
//    ~soft() {
//        std::cout << "software for program '" << programname << "' has been uninstalled.\n";
//    }
//
//    void daysuntilexpiration() const {
//        time_t currenttime;
//        time(&currenttime);
//
//        tm currentlocaltime;
//        localtime_s(&currentlocaltime, &currenttime);
//
//        currentlocaltime.tm_hour = 0;
//        currentlocaltime.tm_min = 0;
//        currentlocaltime.tm_sec = 0;
//
//        double secondsremaining = difftime(licenseexpirationdate, mktime(&currentlocaltime));
//        int daysremaining = static_cast<int>(secondsremaining / (60 * 60 * 24));
//
//        if (daysremaining < 0) {
//            std::cout << "license already expired\n";
//        }
//        else if (daysremaining == 0) {
//            std::cout << "license expires today\n";
//        }
//        else {
//            std::cout << "days until license expiration: " << daysremaining << " days\n";
//        }
//    }
//
//    void displaysoftwaredetails() const {
//        std::cout << "software details:\n";
//        std::cout << "program name: " << programname << "\n";
//        std::cout << "developer: " << developer << "\n";
//        std::cout << "occupied space: " << occupiedspace << " gb\n";
//
//        tm expirationdatestruct;
//        localtime_s(&expirationdatestruct, &licenseexpirationdate);
//        std::cout << "license expiration date: " << expirationdatestruct.tm_mday << "/"
//            << expirationdatestruct.tm_mon + 1 << "/" << expirationdatestruct.tm_year + 1900 << "\n";
//    }
//
//private:
//    tm parsedate(const std::string& datestring) const {
//        tm result = {};
//        sscanf_s(datestring.c_str(), "%d/%d/%d", &result.tm_mday, &result.tm_mon, &result.tm_year);
//        result.tm_mon -= 1;  
//        result.tm_year -= 1900;  
//        return result;
//    }
//};
//
//int main() {
//    soft software("mysoftware", "it company", 2.5, "15/02/2023");
//    software.displaysoftwaredetails();
//   software.daysuntilexpiration();
//   std::cout << "\n";
//   
//   soft software2("mysoftware2", "it company", 2.5, "15/02/2024");
//   software2.displaysoftwaredetails();
//   software2.daysuntilexpiration();
//   std::cout << "\n";
//
//   
//   soft software3("mysoftware3", "it company", 2.5, "25/05/2024");
//   software3.displaysoftwaredetails();
//   software3.daysuntilexpiration();
//    
//
//    return 0;
//}