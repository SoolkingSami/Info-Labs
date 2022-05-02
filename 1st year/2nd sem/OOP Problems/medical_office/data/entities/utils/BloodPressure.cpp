//
// Created by asus on 2/16/2022.
//

#include "BloodPressure.h"

int BloodPressure::getValue() const {
    return value;
}

void BloodPressure::setValue(int value) {
    BloodPressure::value = value;
}

BloodPressureStatus BloodPressure::getStatus() const {
    return status;
}

void BloodPressure::setStatus() {
    if (130 <= value && value <= 139) {
        status = BloodPressureStatus::STABLE;
    } else {
        status = BloodPressureStatus::UNSTABLE;
    }
}

BloodPressure::BloodPressure(int value, const string& date) :
    value(value), status(BloodPressureStatus::STABLE), date(date) {
    setStatus();
}

const string &BloodPressure::getDate() const {
    return date;
}

void BloodPressure::setDate(const string &date) {
    BloodPressure::date = date;
}

BloodPressure::BloodPressure(): value(0), status(BloodPressureStatus::STABLE), date("") {}
