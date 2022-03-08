//
// Created by asus on 2/16/2022.
//

#ifndef MEDICAL_OFFICE_BLOODPRESSURE_H
#define MEDICAL_OFFICE_BLOODPRESSURE_H

#include <string>

using namespace std;

enum class BloodPressureStatus {
    STABLE,
    UNSTABLE
};

class BloodPressure {
private:
    int value;
    BloodPressureStatus status;
    string date;
public:
    const string &getDate() const;

    void setDate(const string &date);

public:
    BloodPressure(int value, const string &date);

    BloodPressure();

public:
    int getValue() const;

    void setValue(int value);

    BloodPressureStatus getStatus() const;

private:
    void setStatus();
};


#endif //MEDICAL_OFFICE_BLOODPRESSURE_H
