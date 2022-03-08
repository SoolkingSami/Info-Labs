//
// Created by asus on 2/16/2022.
//

#ifndef MEDICAL_OFFICE_PATIENTREPOSITORY_H
#define MEDICAL_OFFICE_PATIENTREPOSITORY_H

#include <vector>
#include <algorithm>
#include "../entities/patient/Patient.h"
#include "../patient_scanner/PatientScanner.h"
#include "./IPatientRepository.h"

using namespace std;

class PatientRepository: public IPatientRepository {
private:
    vector<Patient*> patients;
    PatientScanner scanner;

public:
    PatientRepository(const string& fileName);

    PatientRepository();

    ~PatientRepository();

    void init();

    vector<Patient*> getAll() override;

    vector<Patient*> getByName(const string& name) override;

    vector<Patient*> getAdultsWithHighCardioVascularRisk() override;

    vector<Patient*> getChildrenWithCardioVascularRisk() override;
};


#endif //MEDICAL_OFFICE_PATIENTREPOSITORY_H
