//
// Created by asus on 2/16/2022.
//

#ifndef MEDICAL_OFFICE_ADULTPATIENT_H
#define MEDICAL_OFFICE_ADULTPATIENT_H


#include "../utils/Sedentariness.h"
#include "../patient/Patient.h"

class AdultPatient: public Patient {
private:
    PersonDTO person;
    string address;
    int age;
    CardiovascularRisk cardiovascularRisk;
    Cholesterol cholesterol;
    BloodPressure bloodPressure;
    Sedentariness sedentariness;
    bool is_smoker;

protected:
    int calculateCardioVascularRisk() override;
public:
    AdultPatient(
            const string &name,
            const string &surname,
            const string &address,
            int age,
            int cholesterol,
            const string &cholesterolDate,
            int bloodPressure,
            const string &bloodPressureDate,
            const string& sedentariness,
            const string& isSmoker
    );

    AdultPatient();

    Sedentariness getSedentariness() const;

    void setSedentariness(const string& status);

    bool isSmoker() const;

    void setIsSmoker(bool isSmoker);

    void setIsSmokerFromString(const string &basicString);

    friend ifstream& operator>>(ifstream& in, AdultPatient& adultPatient);

    friend ifstream& operator>>(ifstream& in, AdultPatient* &adultPatient);

    friend ostream& operator<<(ostream& out, const AdultPatient& adultPatient);

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
};


#endif //MEDICAL_OFFICE_ADULTPATIENT_H
