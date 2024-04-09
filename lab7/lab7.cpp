//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//const int MAX_SIZE = 100;
//
////class Array {
////protected:
////    unsigned arr[MAX_SIZE];
////    int size;
////
////public:
////    Array(int sz, unsigned init_val = 0) : size(sz) {
////        for (int i = 0; i < size; ++i) {
////            arr[i] = init_val;
////        }
////    }
////
////    virtual void add(const Array& other) {
////        int min_size = min(size, other.size);
////        for (int i = 0; i < min_size; ++i) {
////            arr[i] += other.arr[i];
////        }
////    }
////
////    virtual void display() const {
////        for (int i = 0; i < size; ++i) {
////            cout << arr[i] << " ";
////        }
////        cout << endl;
////    }
////};
////
////
////class Array1 : public Array {
////public:
////    Array1(int sz, unsigned init_val = 0) : Array(sz, init_val) {}
////
////    void add(const Array& other) override {
////        cout << "Adding Arrays of Type 1" << endl;
////        Array::add(other);
////    }
////};
////
////class Array2 : public Array {
////public:
////    Array2(int sz, unsigned init_val = 0) : Array(sz, init_val) {}
////
////    void add(const Array& other) override {
////        cout << "Adding Arrays of Type 2" << endl;
////        Array::add(other);
////    }
////};
//
//class Figure {
//public:
//    virtual float area() const = 0;
//    virtual float perimeter() const = 0;
//};
//
//class Rectangle : public Figure {
//protected:
//    float length, width;
//
//public:
//    Rectangle(float l, float w) : length(l), width(w) {}
//
//    float area() const override {
//        return length * width;
//    }
//
//    float perimeter() const override {
//        return 2 * (length + width);
//    }
//};
//
//class Circle : public Figure {
//protected:
//    float radius;
//
//public:
//    Circle(float r) : radius(r) {}
//
//    float area() const override {
//        return 3.14159 * radius * radius;
//    }
//
//    float perimeter() const override {
//        return 2 * 3.14159 * radius;
//    }
//};
//
//class Trapezium : public Figure {
//protected:
//    float a, b, height;
//
//public:
//    Trapezium(float side_a, float side_b, float h) : a(side_a), b(side_b), height(h) {}
//
//    float area() const override {
//        return (a + b) * height / 2;
//    }
//
//    float perimeter() const override {
//        return a + b + 2 * height;
//    }
//};
//
//int main() {
//
//    /*Array1 arr1(5, 2);
//    Array2 arr2(5, 3);
//    Array1 arr3(3, 1);
//
//    arr1.display();
//    arr2.display();
//
//    arr1.add(arr2);
//    arr1.display();
//
//    arr2.add(arr3);
//    arr2.display();*/
//
//    Rectangle rect(4, 5);
//    Circle circle(3);
//    Trapezium trap(3, 5, 4);
//
//
//    cout << "Rectangle Area: " << rect.area() << ", Perimeter: " << rect.perimeter() << endl;
//    cout << "Circle Area: " << circle.area() << ", Perimeter: " << circle.perimeter() << endl;
//    cout << "Trapezium Area: " << trap.area() << ", Perimeter: " << trap.perimeter() << endl;
//
//    return 0;
//}

//
//

//
#include <iostream>
#include <string>

using namespace std;

class currency {
public:
    virtual double torubles(double amount) const = 0;
    virtual void display(double amount) const = 0;

};

class dollar : public currency {
public:
    double torubles(double amount) const override {
        return amount * 89.0;
    }

    void display(double amount) const override {
        cout << "$" << amount;
    }
};

class euro : public currency {
public:
    double torubles(double amount) const override {
        return amount * 95.0;
    }

    void display(double amount) const override {
        cout << "€" << amount;
    }
};

int main() {
    dollar dollar;
    euro euro;

    double amount;

    cout << "enter amount in dollars: ";
    cin >> amount;
    cout << "amount in rubles: " << dollar.torubles(amount) << " rubles" << endl;

    cout << "enter amount in euros: ";
    cin >> amount;
    cout << "amount in rubles: " << euro.torubles(amount) << " rubles" << endl;

    return 0;
}
