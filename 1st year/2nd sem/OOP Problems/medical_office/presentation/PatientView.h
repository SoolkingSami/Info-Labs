//
// Created by asus on 2/17/2022.
//

#ifndef MEDICAL_OFFICE_PATIENTVIEW_H
#define MEDICAL_OFFICE_PATIENTVIEW_H


#include "../data/entities/patient/Patient.h"
#include "IView.h"

class PatientView: public IView<Patient> {
public:
    void printMenu() override;

    void printByCategory(const vector<Patient*> &patients) override;

    string askForName() override;

    int askForCommand() override;

    void pause() override;

    void printError(const string &error) override;

    ~PatientView();
};


#endif //MEDICAL_OFFICE_PATIENTVIEW_H
