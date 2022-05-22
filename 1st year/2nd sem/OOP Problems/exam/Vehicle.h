//
// Created by asus on 5/10/2022.
//

#ifndef EXAM_VEHICLE_H
#define EXAM_VEHICLE_H

#include <fstream>
#include <cstring>
#include <string>

using namespace std;

class Vehicle {
protected:
    char* matriculation;
    int maxSpeed;

public:
    Vehicle(char* matriculation = (char*)"", int maxSpeed = 0);
    Vehicle(const Vehicle& other);
    Vehicle& operator=(const Vehicle& other);
    virtual ~Vehicle();

    char* getMatriculation() const;
    int getMaxSpeed() const;

    void setMatriculation(char* matriculation);
    void setMaxSpeed(int maxSpeed);

    virtual void print(ostream& out) const;
    virtual void read(ifstream& in);

    friend ostream& operator<<(ostream& out, const Vehicle& vehicle);
    friend ifstream& operator>>(ifstream& in, Vehicle& vehicle);

    friend ostream& operator<<(ostream& out, const Vehicle* vehicle);
    friend ifstream& operator>>(ifstream& in, Vehicle* vehicle);
};


#endif //EXAM_VEHICLE_H
