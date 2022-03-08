//
// Created by asus on 2/16/2022.
//

#include <stdexcept>
#include "AdultPatient.h"

Sedentariness AdultPatient::getSedentariness() const {
    return sedentariness;
}

void AdultPatient::setSedentariness(const string& status) {
    if (status.find("low") != string::npos) {
        sedentariness = Sedentariness::LOW;
    } else if (status.find("medium") != string::npos) {
        sedentariness = Sedentariness::MEDIUM;
    } else if (status.find("high") != string::npos) {
        sedentariness = Sedentariness::HIGH;
    } else {
        throw invalid_argument("Invalid sedentariness status");
    }
}

bool AdultPatient::isSmoker() const {
    return is_smoker;
}

void AdultPatient::setIsSmoker(bool isSmoker) {
    is_smoker = isSmoker;
}

void AdultPatient::setIsSmokerFromString(const string &basicString) {
    if (basicString == "yes") {
        is_smoker = true;
    } else if (basicString == "no") {
        is_smoker = false;
    } else {
        throw invalid_argument("Invalid smoker status");
    }
}

int AdultPatient::calculateCardioVascularRisk() {
   int risk = 0;
   if (this->getCholesterol().getRisk() == CholesterolRisk::HIGH) {
        ++risk;
    }
    if (this->getBloodPressure().getStatus() == BloodPressureStatus::UNSTABLE) {
        ++risk;
    }
   if (is_smoker && sedentariness == Sedentariness::HIGH) {
       ++risk;
   }
   return risk;
}


void AdultPatient::setCardiovascularRisk() {
    if (this->calculateCardioVascularRisk() == 0) {
        cardiovascularRisk = CardiovascularRisk::LOW;
    } else if (this->calculateCardioVascularRisk() == 1) {
        cardiovascularRisk = CardiovascularRisk::MEDIUM;
    } else {
        cardiovascularRisk = CardiovascularRisk::HIGH;
    }
}

ifstream &operator>>(ifstream &in, AdultPatient &adultPatient) {
    string name, surname, address, cholesterolDate, bloodPressureDate, sedentariness, is_smoker;
    int age, cholesterol, bloodPressure;
    in >> name >> surname;
    in.get();
    getline(in, address);
    in >> age;
    in >> cholesterol >> cholesterolDate;
    in.get();
    in >> bloodPressure >> bloodPressureDate;
    in.get();
    in >> sedentariness;
    in.get();
    in >> is_smoker;
    in.get();
    adultPatient = AdultPatient(name, surname, address, age, cholesterol, cholesterolDate, bloodPressure, bloodPressureDate,
                                    sedentariness, is_smoker);
    return in;
}

AdultPatient::AdultPatient(const string &name, const string &surname, const string &address, int age, int cholesterol,
                           const string &cholesterolDate, int bloodPressure, const string &bloodPressureDate,
                           const string &sedentariness, const string &isSmoker):
                           person(name, surname), address(address), age(age), cholesterol(cholesterol, cholesterolDate),
                           bloodPressure(bloodPressure, bloodPressureDate), sedentariness(Sedentariness::MEDIUM),
                           is_smoker(false), cardiovascularRisk(CardiovascularRisk::LOW) {
    setSedentariness(sedentariness);
    setIsSmokerFromString(isSmoker);
    setCardiovascularRisk();
}


const string &AdultPatient::getAddress() const {
    return address;
}

void AdultPatient::setAddress(const string &address) {
    this->address = address;
}

int AdultPatient::getAge() const {
    return age;
}

void AdultPatient::setAge(int age) {
    this->age = age;
}

const Cholesterol &AdultPatient::getCholesterol() const {
    return cholesterol;
}

void AdultPatient::setCholesterol(int value, const string& date) {
    this->cholesterol = Cholesterol(value, date);
}

const BloodPressure &AdultPatient::getBloodPressure() const {
    return bloodPressure;
}

void AdultPatient::setBloodPressure(int value, const string& date) {
    this->bloodPressure = BloodPressure(value, date);
}

const PersonDTO &AdultPatient::getPerson() const {
    return person;
}

void AdultPatient::setPerson(const PersonDTO &person) {
    this->person = person;
}

CardiovascularRisk AdultPatient::getCardiovascularRisk() const {
    return cardiovascularRisk;
}

void AdultPatient::setCardiovascularRisk(CardiovascularRisk cardiovascularRisk) {
    this->cardiovascularRisk = cardiovascularRisk;
}

ifstream &operator>>(ifstream &in, AdultPatient*& adultPatient) {
    string name, surname, address, cholesterolDate, bloodPressureDate, sedentariness, is_smoker;
    int age, cholesterol, bloodPressure;
    in >> name >> surname;
    in.get();
    getline(in, address);
    in >> age;
    in >> cholesterol >> cholesterolDate;
    in.get();
    in >> bloodPressure >> bloodPressureDate;
    in.get();
    in >> sedentariness;
    in.get();
    in >> is_smoker;
    in.get();
    adultPatient = new AdultPatient(name, surname, address, age, cholesterol, cholesterolDate, bloodPressure, bloodPressureDate,
                                sedentariness, is_smoker);
    return in;
}

AdultPatient::AdultPatient(): person(), address(), age(0), cholesterol(), bloodPressure(), sedentariness(Sedentariness::MEDIUM),
                             is_smoker(false), cardiovascularRisk(CardiovascularRisk::LOW) {}

ostream &operator<<(ostream &out, const AdultPatient& adultPatient) {
    out << adultPatient.person << ":" << endl;
    out << "\tRisc cardiovascular - " << adultPatient.cardiovascularRisk << ";" << endl;
    out << "\tColesterol (" << adultPatient.cholesterol.getDate() << "): "
    << adultPatient.cholesterol.getValue() << " mg/dl;" << endl;
    out << "\tTA (" << adultPatient.bloodPressure.getDate() << "): "
    << adultPatient.bloodPressure.getValue() << ";" << endl;
    out << "\tFumator: " << adultPatient.is_smoker << ";" << endl;
    out << "\tSedentarism: " << adultPatient.sedentariness << "." << endl;
    return out;
}

ostream &AdultPatient::format(ostream &out) const {
    out << *this;
    return Patient::format(out);
}
