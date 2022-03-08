//
// Created by asus on 2/16/2022.
//

#ifndef MEDICAL_OFFICE_CHILDPATIENT_H
#define MEDICAL_OFFICE_CHILDPATIENT_H


#include "../patient/Patient.h"
#include "../utils/PersonDTO.h"
#include "../utils/ProteinC.h"

class ChildPatient: public Patient {
public:
    ChildPatient(const string &name, const string &surname, const string &address, int age, int cholesterol,
                 const string &cholesterolDate, int bloodPressure, const string &bloodPressureDate,
                 const string &fatherName, const string &fatherSurname, const string &motherName,
                 const string &motherSurname, float proteinC, const string &proteinCDate, const string &familyDisease);

    ChildPatient();

private:
    PersonDTO person;
    string address;
    int age;
    CardiovascularRisk cardiovascularRisk;
    Cholesterol cholesterol;
    BloodPressure bloodPressure;
    PersonDTO father, mother;
    ProteinC proteinC;
    bool family_disease;

protected:
    int calculateCardioVascularRisk() override;
public:
    const PersonDTO &getFather() const;

    void setFather(const PersonDTO &father);

    const PersonDTO &getMother() const;

    void setMother(const PersonDTO &mother);

    const ProteinC &getProteinC() const;

    void setProteinC(const ProteinC &proteinC);

    bool isFamilyDisease() const;

    void setFamilyDisease(bool familyDisease);

    friend ifstream& operator>>(ifstream& in, ChildPatient& childPatient);

    friend ifstream& operator>>(ifstream& in, ChildPatient* &childPatient);

    friend ostream& operator<<(ostream& out, const ChildPatient& childPatient);

    ostream& format(ostream& out) const override;

    void setCardiovascularRisk();

    void setCardiovascularRisk(CardiovascularRisk cardiovascularRisk) override;

    CardiovascularRisk getCardiovascularRisk() const override;

    void setPerson(const PersonDTO &person) override;

    const PersonDTO &getPerson() const override;

    void setBloodPressure(int value, const string &date) override;

    const BloodPressure &getBloodPressure() const override;

    void setCholesterol(int value, const string &date) override;

    const Cholesterol &getCholesterol() const override;

    void setAge(int age) override;

    int getAge() const override;

    void setAddress(const string &address) override;

    const string &getAddress() const override;

public:
    void setFamilyDiseaseFromString(const string &basicString);
};


#endif //MEDICAL_OFFICE_CHILDPATIENT_H
