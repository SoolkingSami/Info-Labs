//
// Created by asus on 2/16/2022.
//

#ifndef MEDICAL_OFFICE_APPLICATION_H
#define MEDICAL_OFFICE_APPLICATION_H

#include <iostream>
#include <string>
#include "../data/patient_repository/PatientRepository.h"
#include "../presentation/IView.h"

using namespace std;

class Application {
private:
    IPatientRepository *patientRepository;
    IView<Patient> *patientView;

public:
    Application(IPatientRepository *patientRepository, IView<Patient> *view);

    ~Application();

    void run();
};


#endif //MEDICAL_OFFICE_APPLICATION_H
