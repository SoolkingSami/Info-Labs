//
// Created by asus on 2/16/2022.
//

#include "PatientScanner.h"
#include "../entities/adult_patient/AdultPatient.h"
#include "../entities/young_adult_patient/YoungAdultPatient.h"
#include "../entities/child_patient/ChildPatient.h"

PatientScanner::PatientScanner(const string& fileName): fStream(fileName) {
}

Patient* PatientScanner::readPatient() {
    string type;
    fStream >> type;
    if (type == "adult") {
        auto *patient = new AdultPatient();
        fStream >> patient;
        return patient;
    } else if (type == "young") {
        auto *patient = new YoungAdultPatient();
        fStream >> patient;
        return patient;
    } else if (type == "child") {
        auto *patient = new ChildPatient();
        fStream >> patient;
        return patient;
    }
    getline(fStream, type);
    return nullptr;
}

PatientScanner::PatientScanner() = default;
