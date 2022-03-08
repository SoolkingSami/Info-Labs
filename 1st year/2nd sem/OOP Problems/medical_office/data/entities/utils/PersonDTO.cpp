//
// Created by asus on 2/16/2022.
//

#include <iostream>
#include "PersonDTO.h"

PersonDTO::PersonDTO(const string &name, const string &surname) : name(name), surname(surname) {}

const string &PersonDTO::getName() const {
    return name;
}

void PersonDTO::setName(const string &name) {
    PersonDTO::name = name;
}

const string &PersonDTO::getSurname() const {
    return surname;
}

void PersonDTO::setSurname(const string &surname) {
    PersonDTO::surname = surname;
}

ifstream &operator>>(ifstream &in, PersonDTO &person) {
    in >> person.name >> person.surname;
    return in;
}

PersonDTO::PersonDTO(): name(""), surname("") {}

ostream &operator<<(ostream &out, const PersonDTO &person) {
    cout << person.surname << " " << person.name;
    return out;
}
