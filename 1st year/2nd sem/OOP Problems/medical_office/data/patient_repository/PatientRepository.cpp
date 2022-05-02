//
// Created by asus on 2/16/2022.
//

#include "PatientRepository.h"

PatientRepository::PatientRepository(const string &fileName): scanner(fileName), patients() {
    init();
}

vector<Patient*> PatientRepository::getAll() {
    return this->patients;
}

void PatientRepository::init() {
    Patient *patient;
    while ((patient = scanner.readPatient())) {
        this->patients.push_back(patient);
    }
}

vector<Patient *> PatientRepository::getByName(const string &name) {
    vector<Patient *> result;
    copy_if(patients.begin(), patients.end(), back_inserter(result), [=](Patient *patient) {
        return patient->getPerson().getSurname() == name;
    });
    return result;
}

vector<Patient *> PatientRepository::getAdultsWithHighCardioVascularRisk() {
    vector<Patient *> result;
    copy_if(patients.begin(), patients.end(), back_inserter(result), [=](Patient *patient) {
        return patient->getAge() >= 18 && patient->getCardiovascularRisk() == CardiovascularRisk::HIGH;
    });
    return result;
}

vector<Patient *> PatientRepository::getChildrenWithCardioVascularRisk() {
    vector<Patient *> result;
    copy_if(patients.begin(), patients.end(), back_inserter(result), [=](Patient *patient) {
        return patient->getAge() < 18 && patient->getCardiovascularRisk() != CardiovascularRisk::LOW;
    });
    return result;
}

PatientRepository::~PatientRepository() = default;

PatientRepository::PatientRepository() = default;
