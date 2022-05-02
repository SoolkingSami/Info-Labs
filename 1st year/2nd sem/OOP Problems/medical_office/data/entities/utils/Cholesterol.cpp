//
// Created by asus on 2/16/2022.
//

#include "Cholesterol.h"

int Cholesterol::getValue() const {
    return value;
}

void Cholesterol::setValue(int value) {
    Cholesterol::value = value;
}

void Cholesterol::setRisk() {
    if (value < 200) {
        risk = CholesterolRisk::OPTIMUM;
    } else if (value < 240) {
        risk =  CholesterolRisk::NORMAL;
    } else {
        risk = CholesterolRisk::HIGH;
    }
}

Cholesterol::Cholesterol(int value, const string& date) :
    value(value), risk(CholesterolRisk::OPTIMUM), date(date) {
    setRisk();
}

CholesterolRisk Cholesterol::getRisk() const {
    return risk;
}

const string &Cholesterol::getDate() const {
    return date;
}

void Cholesterol::setDate(const string &date) {
    Cholesterol::date = date;
}

Cholesterol::Cholesterol(): value(0), risk(CholesterolRisk::OPTIMUM), date("") {}
