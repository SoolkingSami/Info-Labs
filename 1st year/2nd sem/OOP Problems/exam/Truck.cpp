//
// Created by asus on 5/10/2022.
//

#include "Truck.h"

Truck::Truck(char *matriculation, int maxSpeed, float capacity): Vehicle(matriculation, maxSpeed), capacity(capacity) {}

Truck::Truck(const Truck &truck): Vehicle(truck), capacity(truck.capacity) {}

Truck& Truck::operator=(const Truck &truck) {
    if (this != &truck) {
        Vehicle::operator=(truck);
        capacity = truck.capacity;
    }
    return *this;
}

float Truck::getCapacity() const {
    return capacity;
}

void Truck::setCapacity(float capacity) {
    this->capacity = capacity;
}

void Truck::print(ostream &out) const {
    Vehicle::print(out);
    out << "Truck Capacity: " << capacity << " tons" << endl;
}

void Truck::read(ifstream &in) {
    Vehicle::read(in);
    in >> capacity;
    in.ignore();
}

ostream &operator<<(ostream &out, const Truck &truck) {
    truck.print(out);
    return out;
}

ifstream &operator>>(ifstream &in, Truck &truck) {
    truck.read(in);
    return in;
}

ostream &operator<<(ostream &out, const Truck *truck) {
    truck->print(out);
    return out;
}

ifstream &operator>>(ifstream &in, Truck *truck) {
    truck->read(in);
    return in;
}