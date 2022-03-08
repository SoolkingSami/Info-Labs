//
// Created by asus on 2/16/2022.
//

#ifndef MEDICAL_OFFICE_PERSONDTO_H
#define MEDICAL_OFFICE_PERSONDTO_H

#include <string>
#include <fstream>

using namespace std;

class PersonDTO {
private:
    string name, surname;
public:
    PersonDTO(const string &name, const string &surname);

    PersonDTO();

    const string &getName() const;

    void setName(const string &name);

    const string &getSurname() const;

    void setSurname(const string &surname);

    friend ifstream& operator>>(ifstream &in, PersonDTO &person);

    friend ostream& operator<<(ostream &out, const PersonDTO &person);
};


#endif //MEDICAL_OFFICE_PERSONDTO_H
