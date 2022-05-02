//
// Created by asus on 2/16/2022.
//

#include "ProteinC.h"

ProteinC::ProteinC(float value, const string &date) :
    value(value), date(date), status(ProteinCStatus::OPTIMUM) {
    setStatus();
}

float ProteinC::getValue() const {
    return value;
}

void ProteinC::setValue(float value) {
    ProteinC::value = value;
}

const string &ProteinC::getDate() const {
    return date;
}

void ProteinC::setDate(const string &date) {
    ProteinC::date = date;
}

ProteinCStatus ProteinC::getStatus() const {
    return status;
}

void ProteinC::setStatus() {
    if (value <= 0.6f) {
        status = ProteinCStatus::OPTIMUM;
    } else {
        status = ProteinCStatus::BAD;
    }
}

ProteinC::ProteinC(): ProteinC(0.0f, "") {}