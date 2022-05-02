//
// Created by asus on 2/16/2022.
//

#ifndef MEDICAL_OFFICE_SEDENTARINESS_H
#define MEDICAL_OFFICE_SEDENTARINESS_H

#include <iostream>

using namespace std;

enum class Sedentariness {
    LOW,
    MEDIUM,
    HIGH
};

ostream &operator<<(ostream &os, const Sedentariness &sedentariness);

#endif //MEDICAL_OFFICE_SEDENTARINESS_H
