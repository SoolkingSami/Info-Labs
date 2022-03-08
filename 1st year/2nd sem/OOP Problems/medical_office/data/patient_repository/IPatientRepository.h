//
// Created by asus on 2/17/2022.
//

#ifndef MEDICAL_OFFICE_IPATIENTREPOSITORY_H
#define MEDICAL_OFFICE_IPATIENTREPOSITORY_H


class IPatientRepository {
public:
    virtual vector<Patient*> getAll() = 0;
    virtual vector<Patient*> getByName(const string& name) = 0;
    virtual vector<Patient*> getAdultsWithHighCardioVascularRisk() = 0;
    virtual vector<Patient*> getChildrenWithCardioVascularRisk() = 0;
    virtual ~IPatientRepository() = default;
};


#endif //MEDICAL_OFFICE_IPATIENTREPOSITORY_H
