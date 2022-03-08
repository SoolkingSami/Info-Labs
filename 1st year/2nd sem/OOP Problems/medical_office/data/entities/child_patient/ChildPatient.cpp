//
// Created by asus on 2/16/2022.
//

#include <stdexcept>
#include "ChildPatient.h"

const PersonDTO &ChildPatient::getFather() const {
    return father;
}

void ChildPatient::setFather(const PersonDTO &father) {
    ChildPatient::father = father;
}

const PersonDTO &ChildPatient::getMother() const {
    return mother;
}

void ChildPatient::setMother(const PersonDTO &mother) {
    ChildPatient::mother = mother;
}

const ProteinC &ChildPatient::getProteinC() const {
    return proteinC;
}

void ChildPatient::setProteinC(const ProteinC &proteinC) {
    ChildPatient::proteinC = proteinC;
}

bool ChildPatient::isFamilyDisease() const {
    return family_disease;
}

void ChildPatient::setFamilyDisease(bool familyDisease) {
    family_disease = familyDisease;
}

void ChildPatient::setFamilyDiseaseFromString(const string &basicString) {
    if (basicString == "yes") {
        family_disease = true;
    } else if (basicString == "no") {
        family_disease = false;
    } else {
        throw invalid_argument("Invalid argument");
    }
}

ChildPatient::ChildPatient(const string &name, const string &surname, const string &address, int age, int cholesterol,
                           const string &cholesterolDate, int bloodPressure, const string &bloodPressureDate,
                           const string &fatherName, const string &fatherSurname, const string &motherName,
                           const string &motherSurname, float proteinC, const string& proteinCDate, const string &familyDisease):
                           person(name, surname), address(address), age(age), cholesterol(cholesterol, cholesterolDate), bloodPressure(bloodPressure, bloodPressureDate),
                                                                                                 father(fatherName, fatherSurname),
                                                                                                 mother(motherName, motherSurname),
                                                                                                 proteinC(proteinC, proteinCDate),
                                                                                                 family_disease(false) {
    setFamilyDiseaseFromString(familyDisease);
    setCardiovascularRisk();
}

int ChildPatient::calculateCardioVascularRisk() {
    int risk = 0;
    if (this->getCholesterol().getRisk() == CholesterolRisk::HIGH) {
        ++risk;
    }
    if (this->getBloodPressure().getStatus() == BloodPressureStatus::UNSTABLE) {
        ++risk;
    }
    if (family_disease) {
        ++risk;
    }
    if (proteinC.getStatus() == ProteinCStatus::BAD) {
        ++risk;
    }
    return risk;
}

ifstream &operator>>(ifstream &in, ChildPatient &childPatient) {
    string name, surname, address, fatherName, fatherSurname, motherName, motherSurname, familyDisease;
    int age, cholesterol, bloodPressure;
    float proteinC;
    string cholesterolDate, bloodPressureDate, proteinCDate;
    in >> name >> surname;
    in.get();
    getline(in, address);
    in >> age >> cholesterol >> cholesterolDate;
    in.get();
    in >> bloodPressure >> bloodPressureDate;
    in.get();
    in >> fatherName >> fatherSurname;
    in.get();
    in >> motherName >> motherSurname;
    in.get();
    in >> proteinC >> proteinCDate;
    in.get();
    in >> familyDisease;
    in.get();
    childPatient = ChildPatient(name, surname, address, age, cholesterol, cholesterolDate, bloodPressure, bloodPressureDate,
                                    fatherName, fatherSurname, motherName, motherSurname, proteinC, proteinCDate, familyDisease);
    return in;
}

void ChildPatient::setCardiovascularRisk() {
    if (this->calculateCardioVascularRisk() == 0) {
        cardiovascularRisk = CardiovascularRisk::LOW;
    } else if (this->calculateCardioVascularRisk() == 1) {
        cardiovascularRisk = CardiovascularRisk::MEDIUM;
    } else {
        cardiovascularRisk = CardiovascularRisk::HIGH;
    }
}

void ChildPatient::setCardiovascularRisk(CardiovascularRisk cardiovascularRisk) {
    ChildPatient::cardiovascularRisk = cardiovascularRisk;
}

CardiovascularRisk ChildPatient::getCardiovascularRisk() const {
    return cardiovascularRisk;
}

void ChildPatient::setPerson(const PersonDTO &person) {
    ChildPatient::person = person;
}

const PersonDTO &ChildPatient::getPerson() const {
    return person;
}

void ChildPatient::setBloodPressure(int value, const string &date) {
    bloodPressure = BloodPressure(value, date);
}

const BloodPressure &ChildPatient::getBloodPressure() const {
    return bloodPressure;
}

void ChildPatient::setCholesterol(int value, const string &date) {
    cholesterol = Cholesterol(value, date);
}

const Cholesterol &ChildPatient::getCholesterol() const {
   return cholesterol;
}

void ChildPatient::setAge(int age) {
    ChildPatient::age = age;
}

int ChildPatient::getAge() const {
   return age;
}

void ChildPatient::setAddress(const string &address) {
    ChildPatient::address = address;
}

const string &ChildPatient::getAddress() const {
   return address;
}

ChildPatient::ChildPatient(): person(), address(""), age(0), cholesterol(), bloodPressure(),
                              father(), mother(), proteinC(), family_disease(false),
                              cardiovascularRisk(CardiovascularRisk::LOW) {}

ifstream &operator>>(ifstream &in, ChildPatient *&childPatient) {
    string name, surname, address, fatherName, fatherSurname, motherName, motherSurname, familyDisease;
    int age, cholesterol, bloodPressure;
    float proteinC;
    string cholesterolDate, bloodPressureDate, proteinCDate;
    in >> name >> surname;
    in.get();
    getline(in, address);
    in >> age >> cholesterol >> cholesterolDate;
    in.get();
    in >> bloodPressure >> bloodPressureDate;
    in.get();
    in >> fatherName >> fatherSurname;
    in.get();
    in >> motherName >> motherSurname;
    in.get();
    in >> proteinC >> proteinCDate;
    in.get();
    in >> familyDisease;
    in.get();
    childPatient = new ChildPatient(name, surname, address, age, cholesterol, cholesterolDate, bloodPressure, bloodPressureDate,
                                    fatherName, fatherSurname, motherName, motherSurname, proteinC, proteinCDate, familyDisease);
    return in;
}

ostream &operator<<(ostream &out, const ChildPatient &childPatient) {
    out << childPatient.person << ":" << endl;
    out << "\tRisc cardiovascular - " << childPatient.cardiovascularRisk << ";" << endl;
    out << "\tColesterol (" << childPatient.cholesterol.getDate() << "): "
        << childPatient.cholesterol.getValue() << " mg/dl;" << endl;
    out << "\tTA (" << childPatient.bloodPressure.getDate() << "): "
        << childPatient.bloodPressure.getValue() << ";" << endl;
    out << "\tProteina C (" << childPatient.proteinC.getDate() << "): "
        << childPatient.proteinC.getValue() << " mg/dl;" << endl;
    out << "\tAntecedente familie: " << childPatient.family_disease << "." << endl;
    return out;
}

ostream &ChildPatient::format(ostream &out) const {
    out << *this;
    return Patient::format(out);
}
