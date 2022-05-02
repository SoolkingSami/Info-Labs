//
// Created by asus on 2/17/2022.
//

#include "Sedentariness.h"

ostream &operator<<(ostream &os, const Sedentariness &sedentariness) {
    switch (sedentariness) {
        case Sedentariness::LOW:
            os << "LOW";
            break;
        case Sedentariness::MEDIUM:
            os << "MEDIUM";
            break;
        case Sedentariness::HIGH:
            os << "HIGH";
            break;
    }
    return os;
}