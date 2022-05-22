//
// Created by asus on 5/10/2022.
//

#ifndef EXAM_TRUCK_H
#define EXAM_TRUCK_H


#include "Vehicle.h"

class Truck: public Vehicle {
private:
    float capacity;

public:
    Truck(char* matriculation = (char*)"", int maxSpeed = 0, float capacity = 0.f);
    Truck(const Truck& truck);
    Truck& operator=(const Truck& truck);
    ~Truck() = default;

    float getCapacity() const;
    void setCapacity(float capacity);

    void print(ostream& out) const override;
    void read(ifstream& in) override;

    friend ostream& operator<<(ostream& out, const Truck& truck);
    friend ifstream& operator>>(ifstream& in, Truck& truck);

    friend ostream& operator<<(ostream& out, const Truck* truck);
    friend ifstream& operator>>(ifstream& in, Truck* truck);
};


#endif //EXAM_TRUCK_H
