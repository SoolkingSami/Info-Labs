//
// Created by asus on 2/16/2022.
//

#ifndef MEDICAL_OFFICE_PATIENTSCANNER_H
#define MEDICAL_OFFICE_PATIENTSCANNER_H

#include <iostream>
#include <string>
#include <fstream>
#include "../entities/patient/Patient.h"

using namespace std;

class PatientScanner {
private:
    ifstream fStream;

public:
    PatientScanner(const string& fileName);

    PatientScanner();

    Patient* readPatient();
};


#endif //MEDICAL_OFFICE_PATIENTSCANNER_H
