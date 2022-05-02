//
// Created by asus on 2/17/2022.
//

#ifndef MEDICAL_OFFICE_IVIEW_H
#define MEDICAL_OFFICE_IVIEW_H

#include <vector>

using namespace std;

template<typename T>
class IView {
public:
    virtual void printMenu() = 0;
    virtual void printByCategory(const vector<T*>& items) = 0;
    virtual string askForName() = 0;
    virtual int askForCommand() = 0;
    virtual void pause() = 0;
    virtual void printError(const string& error) = 0;
    virtual ~IView() = default;
};

#endif //MEDICAL_OFFICE_IVIEW_H
