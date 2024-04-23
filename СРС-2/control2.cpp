#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include <algorithm> 

using namespace std;

// Класс для звезды
class Star {
private:
    string name; //названия звезды
    string constellation; //названия созвездия, в котором находится звезда
    double magnitude; //звездная величина
    double distance; //расстояние до звезды
    pair<double, double> coordinates; // Координаты на небесной сфере

public:
    Star(string _name, string _constellation, double _magnitude, double _distance, pair<double, double> _coordinates) :
        name(_name), constellation(_constellation), magnitude(_magnitude), distance(_distance), coordinates(_coordinates) {}

    string getName() const { return name; }
    string getConstellation() const { return constellation; }
    double getMagnitude() const { return magnitude; }
    double getDistance() const { return distance; }
    pair<double, double> getCoordinates() const { return coordinates; }
};

// Класс для справочника звезд
class StarCatalog {
private:
    vector<Star> stars;

public:
    // Метод для добавления звезды в справочник
    void addStar(const Star& star) {
        stars.push_back(star);
    }

    // Метод для поиска звезды по созвездию
    vector<Star> findStarsByConstellation(string constellation) const {
        vector<Star> result;
        for (const auto& star : stars) {
            if (star.getConstellation() == constellation) {
                result.push_back(star);
            }
        }
        return result;
    }

    // Метод для поиска самых ярких звезд в справочнике
    vector<Star> findBrightestStars(int count) const {
        vector<Star> result;
        vector<Star> sortedStars = stars;
        sort(sortedStars.begin(), sortedStars.end(), [](const Star& a, const Star& b) {
            return a.getMagnitude() < b.getMagnitude();
            });
        for (int i = 0; i < count && i < sortedStars.size(); ++i) {
            result.push_back(sortedStars[i]);
        }
        return result;
    }

    // Метод для вывода информации о звездах
    void printStars(const vector<Star>& stars) const {
        for (const auto& star : stars) {
            cout << "Name: " << star.getName() << ", Constellation: " << star.getConstellation() << ", Magnitude: "
                << star.getMagnitude() << ", Distance: " << star.getDistance() << ", Coordinates: ("
                << star.getCoordinates().first << ", " << star.getCoordinates().second << ")" << endl;
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    StarCatalog catalog;

    // Добавляем звезды
    catalog.addStar(Star("Sirius", "Canis Major", -1.46, 8.6, make_pair(101.28, -16.72)));
    catalog.addStar(Star("Vega", "Lyra", 0.03, 25.0, make_pair(279.23, 38.78)));
    catalog.addStar(Star("Altair", "Aquila", 0.77, 16.7, make_pair(297.7, 8.87)));

    // Поиск звезд по созвездию
    cout << "Stars in Canis Major:" << endl;
    catalog.printStars(catalog.findStarsByConstellation("Canis Major"));
    cout << endl;

    // Поиск самых ярких звезд
    cout << "Brightest stars:" << endl;
    catalog.printStars(catalog.findBrightestStars(3));

    return 0;
}
