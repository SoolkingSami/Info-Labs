//
// Created by asus on 5/10/2022.
//

#ifndef EXAM_TANK_H
#define EXAM_TANK_H


#include "Vehicle.h"

class Tank: public Vehicle {
private:
    float volume;

public:
    Tank(char* matriculation = (char*)"", int maxSpeed = 0, float volume = 0.f);
    Tank(const Tank& other);
    Tank& operator=(const Tank& other);
    ~Tank() = default;

    float getVolume() const;
    void setVolume(float volume);

    void print(ostream& out) const override;
    void read(ifstream& in) override;

    friend ostream& operator<<(ostream& out, const Tank& tank);
    friend ifstream& operator>>(ifstream& in, Tank& tank);

    friend ostream& operator<<(ostream& out, const Tank* tank);
    friend ifstream& operator>>(ifstream& in, Tank* tank);
};


#endif //EXAM_TANK_H
