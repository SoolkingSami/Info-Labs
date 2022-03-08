//
// Created by asus on 2/16/2022.
//

#ifndef MEDICAL_OFFICE_CHOLESTEROL_H
#define MEDICAL_OFFICE_CHOLESTEROL_H

#include <string>

using namespace std;

enum class CholesterolRisk {
    OPTIMUM,
    NORMAL,
    HIGH
};

class Cholesterol {
private:
    int value;
    CholesterolRisk risk;
    string date;
public:
    const string &getDate() const;

    void setDate(const string &date);

public:
    Cholesterol(int value, const string& date);
    Cholesterol();

public:
    int getValue() const;

    void setValue(int value);

    CholesterolRisk getRisk() const;

private:
    void setRisk();
};


#endif //MEDICAL_OFFICE_CHOLESTEROL_H
