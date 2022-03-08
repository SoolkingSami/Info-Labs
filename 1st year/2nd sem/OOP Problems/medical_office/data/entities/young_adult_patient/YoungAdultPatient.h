//
// Created by asus on 2/16/2022.
//

#ifndef MEDICAL_OFFICE_YOUNGADULTPATIENT_H
#define MEDICAL_OFFICE_YOUNGADULTPATIENT_H


#include "../patient/Patient.h"

class YoungAdultPatient: public Patient {
private:
    PersonDTO person;
    string address;
    int age;
    CardiovascularRisk cardiovascularRisk;
    Cholesterol cholesterol;
    BloodPressure bloodPressure;
public:
    YoungAdultPatient(const string &name, const string &surname, const string &address, int age, int cholesterol,
                      const string &cholesterolDate, int bloodPressure, const string &bloodPressureDate);

    YoungAdultPatient();

    friend ifstream& operator>>(ifstream& in, YoungAdultPatient& youngAdultPatient);

    friend ifstream& operator>>(ifstream& in, YoungAdultPatient* &youngAdultPatient);

    friend ostream& operator<<(ostream& out, const YoungAdultPatient& youngAdultPatient);

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

protected:
    int calculateCardioVascularRisk() override;
};


#endif //MEDICAL_OFFICE_YOUNGADULTPATIENT_H
