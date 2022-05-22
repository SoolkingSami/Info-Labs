//
// Created by asus on 5/10/2022.
//

#include "Tank.h"

Tank::Tank(char *matriculation, int maxSpeed, float volume): Vehicle(matriculation, maxSpeed), volume(volume) {}

Tank::Tank(const Tank &other): Vehicle(other), volume(other.volume) {}

Tank &Tank::operator=(const Tank &other) {
    if (this != &other) {
        Vehicle::operator=(other);
        volume = other.volume;
    }
    return *this;
}

float Tank::getVolume() const {
    return volume;
}

void Tank::setVolume(float volume) {
    Tank::volume = volume;
}

void Tank::print(ostream &out) const {
    Vehicle::print(out);
    out << "Tank volume: " << volume << " l" << endl;
}

void Tank::read(ifstream &in) {
    Vehicle::read(in);
    in >> volume;
    in.ignore();
}

ostream &operator<<(ostream &out, const Tank &tank) {
    tank.print(out);
    return out;
}

ifstream &operator>>(ifstream &in, Tank &tank) {
    tank.read(in);
    return in;
}

ostream &operator<<(ostream &out, const Tank *tank) {
    tank->print(out);
    return out;
}

ifstream &operator>>(ifstream &in, Tank *tank) {
    tank->read(in);
    return in;
}