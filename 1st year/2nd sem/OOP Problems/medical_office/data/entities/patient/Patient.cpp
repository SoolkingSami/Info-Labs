//
// Created by asus on 2/17/2022.
//

#include "Patient.h"

ostream &operator<<(ostream &os, const CardiovascularRisk &risk) {
    switch (risk) {
        case CardiovascularRisk::LOW:
            os << "Low";
            break;
        case CardiovascularRisk::MEDIUM:
            os << "Medium";
            break;
        case CardiovascularRisk::HIGH:
            os << "High";
            break;
    }
    return os;
}

ostream &operator<<(ostream &os, const Patient &patient) {
    return patient.format(os);
}

ostream &Patient::format(ostream &os) const {
    return os;
}
