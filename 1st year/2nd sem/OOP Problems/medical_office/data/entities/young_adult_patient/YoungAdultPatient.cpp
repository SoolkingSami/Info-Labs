//
// Created by asus on 2/16/2022.
//

#include "YoungAdultPatient.h"

YoungAdultPatient::YoungAdultPatient(const string &name, const string &surname, const string &address, int age,
                                     int cholesterol, const string &cholesterolDate, int bloodPressure,
                                     const string &bloodPressureDate) :
                                     person(name, surname), address(address), age(age), cholesterol(cholesterol, cholesterolDate),
                                     bloodPressure(bloodPressure, bloodPressureDate), cardiovascularRisk(CardiovascularRisk::LOW) {
    setCardiovascularRisk();
}

int YoungAdultPatient::calculateCardioVascularRisk() {
    int risk = 0;
    if (this->getCholesterol().getRisk() == CholesterolRisk::HIGH) {
        ++risk;
    }
    if (this->getBloodPressure().getStatus() == BloodPressureStatus::UNSTABLE) {
        ++risk;
    }
    return risk;
}


void YoungAdultPatient::setCardiovascularRisk() {
    if (this->calculateCardioVascularRisk() == 0) {
        cardiovascularRisk = CardiovascularRisk::LOW;
    } else if (this->calculateCardioVascularRisk() == 1) {
        cardiovascularRisk = CardiovascularRisk::MEDIUM;
    } else {
        cardiovascularRisk = CardiovascularRisk::HIGH;
    }
}

ifstream &operator>>(ifstream &in, YoungAdultPatient &youngAdultPatient) {
    string name, surname, address, cholesterolDate, bloodPressureDate;
    int age, cholesterol, bloodPressure;
    in >> name >> surname;
    in.get();
    getline(in, address);
    in >> age >> cholesterol >> cholesterolDate;
    in.get();
    in >> bloodPressure >> bloodPressureDate;
    in.get();
    youngAdultPatient = YoungAdultPatient(name, surname, address, age, cholesterol, cholesterolDate, bloodPressure,
                                              bloodPressureDate);
    return in;
}

void YoungAdultPatient::setCardiovascularRisk(CardiovascularRisk cardiovascularRisk) {
    this->cardiovascularRisk = cardiovascularRisk;
}

CardiovascularRisk YoungAdultPatient::getCardiovascularRisk() const {
    return cardiovascularRisk;
}

void YoungAdultPatient::setPerson(const PersonDTO &person) {
    this->person = person;
}

const PersonDTO &YoungAdultPatient::getPerson() const {
   return person;
}

void YoungAdultPatient::setBloodPressure(int value, const string &date) {
    bloodPressure = BloodPressure(value, date);
}

const BloodPressure &YoungAdultPatient::getBloodPressure() const {
    return bloodPressure;
}

void YoungAdultPatient::setCholesterol(int value, const string &date) {
    cholesterol = Cholesterol(value, date);
}

const Cholesterol &YoungAdultPatient::getCholesterol() const {
   return cholesterol;
}

void YoungAdultPatient::setAge(int age) {
    this->age = age;
}

int YoungAdultPatient::getAge() const {
   return age;
}

void YoungAdultPatient::setAddress(const string &address) {
    this->address = address;
}

const string &YoungAdultPatient::getAddress() const {
   return address;
}

YoungAdultPatient::YoungAdultPatient(): person(), address(), age(0), cholesterol(), bloodPressure(),
                                        cardiovascularRisk(CardiovascularRisk::LOW) {}

ifstream &operator>>(ifstream &in, YoungAdultPatient *&youngAdultPatient) {
    string name, surname, address, cholesterolDate, bloodPressureDate;
    int age, cholesterol, bloodPressure;
    in >> name >> surname;
    in.get();
    getline(in, address);
    in >> age >> cholesterol >> cholesterolDate;
    in.get();
    in >> bloodPressure >> bloodPressureDate;
    in.get();
    youngAdultPatient = new YoungAdultPatient(name, surname, address, age, cholesterol, cholesterolDate, bloodPressure,
                                              bloodPressureDate);
    return in;
}

ostream &operator<<(ostream &out, const YoungAdultPatient &youngAdultPatient) {
    out << youngAdultPatient.person << ":" << endl;
    out << "\tRisc cardiovascular - " << youngAdultPatient.cardiovascularRisk << ";" << endl;
    out << "\tColesterol (" << youngAdultPatient.cholesterol.getDate() << "): "
        << youngAdultPatient.cholesterol.getValue() << " mg/dl;" << endl;
    out << "\tTA (" << youngAdultPatient.bloodPressure.getDate() << "): "
        << youngAdultPatient.bloodPressure.getValue() << "." << endl;
    return out;
}

ostream &YoungAdultPatient::format(ostream &out) const {
    out << *this;
    return Patient::format(out);
}
