#include <iostream>
#include <cstring>

using namespace std;

struct Car {
    char brand[20];
    int year;
    char fuel[20];

    void readCar();
    void printCar();
};

void Car::readCar() {
    cout << "Brand:\n";
    cin >> brand;
    cout << "Year:\n";
    cin >> year;
    cout << "Fuel:\n";
    cin >> fuel;
}

void Car::printCar() {
    cout << "Brand: " << brand << endl;
    cout << "Year: " << year << endl;
    cout << "Fuel: " << fuel << endl;
    cout << endl;
}

void readCars(Car* cars, int n) {
    for (int i = 0; i < n; i++) {
        cars[i].readCar();
    }
}

void printCars(Car* cars, int n) {
    for (int i = 0; i < n; i++) {
        cars[i].printCar();
    }
}

void printCarsByFuel(Car* cars, int n, char* fuel) {
    for (int i = 0; i < n; i++) {
        if (strcmp(cars[i].fuel, fuel) == 0) {
            cars[i].printCar();
        }
    }
}

int main() {
    int n;
    cout << "Number of cars:\n";
    cin >> n;

    Car* cars = new Car[n];

    readCars(cars, n);
    printCars(cars, n);

    char fuel[20];
    cout << "Fuel:\n";
    cin >> fuel;
    printCarsByFuel(cars, n, fuel);

    delete [] cars;
    return 0;
}
