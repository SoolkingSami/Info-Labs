//
// Created by asus on 2/16/2022.
//

#ifndef MEDICAL_OFFICE_PATIENT_H
#define MEDICAL_OFFICE_PATIENT_H

#include <string>
#include <iostream>
#include "../utils/Cholesterol.h"
#include "../utils/BloodPressure.h"
#include "../utils/PersonDTO.h"

using namespace std;

enum class CardiovascularRisk {
    LOW,
    MEDIUM,
    HIGH
};

ostream &operator<<(ostream &os, const CardiovascularRisk &risk);

class Patient {
public:
    virtual const PersonDTO &getPerson() const = 0;

    virtual void setPerson(const PersonDTO &person) = 0;

protected:
    virtual int calculateCardioVascularRisk() = 0;

public:
    virtual CardiovascularRisk getCardiovascularRisk() const = 0;

    virtual void setCardiovascularRisk(CardiovascularRisk cardiovascularRisk) = 0;

public:
    virtual const BloodPressure &getBloodPressure() const = 0;

    virtual void setBloodPressure(int value, const string &date) = 0;

    virtual const string &getAddress() const = 0;

    virtual void setAddress(const string &address) = 0;

    virtual int getAge() const = 0;

    virtual void setAge(int age) = 0;

    virtual const Cholesterol &getCholesterol() const = 0;

    virtual void setCholesterol(int value, const string &date) = 0;

    virtual ostream& format(ostream& os) const;

    friend ostream& operator<<(ostream& os, const Patient& patient);
};


#endif //MEDICAL_OFFICE_PATIENT_H
