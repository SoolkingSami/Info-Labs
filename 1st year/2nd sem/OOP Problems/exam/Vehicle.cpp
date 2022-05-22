//
// Created by asus on 5/10/2022.
//

#include "Vehicle.h"

Vehicle::Vehicle(char *matriculation, int maxSpeed): maxSpeed(maxSpeed) {
    this->matriculation = new char[strlen(matriculation) + 1];
    strcpy(this->matriculation, matriculation);
}

Vehicle::Vehicle(const Vehicle &other): maxSpeed(other.maxSpeed) {
    this->matriculation = new char[strlen(other.matriculation) + 1];
    strcpy(this->matriculation, other.matriculation);
}

Vehicle &Vehicle::operator=(const Vehicle &other) {
    if (this != &other) {
        if (strlen(other.matriculation) > strlen(this->matriculation)) {
            delete[] this->matriculation;
            this->matriculation = new char[strlen(other.matriculation) + 1];
        }
        strcpy(this->matriculation, other.matriculation);
        this->maxSpeed = other.maxSpeed;
    }
    return *this;
}

Vehicle::~Vehicle() {
    delete[] this->matriculation;
}

char *Vehicle::getMatriculation() const {
    return this->matriculation;
}

int Vehicle::getMaxSpeed() const {
    return this->maxSpeed;
}

void Vehicle::setMatriculation(char *matriculation) {
    if (strlen(matriculation) > strlen(this->matriculation)) {
        delete[] this->matriculation;
        this->matriculation = new char[strlen(matriculation) + 1];
    }
    strcpy(this->matriculation, matriculation);
}

void Vehicle::setMaxSpeed(int maxSpeed) {
    this->maxSpeed = maxSpeed;
}

void Vehicle::print(ostream &out) const {
    out << "Matriculation: " << this->matriculation << endl;
    out << "Max speed: " << this->maxSpeed << " kph" << endl;
}

void Vehicle::read(ifstream &in) {
    in.getline(this->matriculation, 100);
    in >> this->maxSpeed;
    in.ignore();
}

ostream &operator<<(ostream &out, const Vehicle &vehicle) {
    vehicle.print(out);
    return out;
}

ifstream &operator>>(ifstream &in, Vehicle &vehicle) {
    vehicle.read(in);
    return in;
}

ostream &operator<<(ostream &out, const Vehicle *vehicle) {
    vehicle->print(out);
    return out;
}

ifstream &operator>>(ifstream &in, Vehicle *vehicle) {
    vehicle->read(in);
    return in;
}