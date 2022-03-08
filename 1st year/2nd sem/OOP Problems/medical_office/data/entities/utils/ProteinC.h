//
// Created by asus on 2/16/2022.
//

#ifndef MEDICAL_OFFICE_PROTEINC_H
#define MEDICAL_OFFICE_PROTEINC_H

#include <string>

using namespace std;

enum class ProteinCStatus {
    OPTIMUM,
    BAD
};

class ProteinC {
private:
    float value;
    ProteinCStatus status;
public:
    ProteinCStatus getStatus() const;
private:
    void setStatus();

private:
    string date;
public:
    ProteinC(float value, const string &date);

    ProteinC();

    float getValue() const;

    void setValue(float value);

    const string &getDate() const;

    void setDate(const string &date);
};


#endif //MEDICAL_OFFICE_PROTEINC_H
