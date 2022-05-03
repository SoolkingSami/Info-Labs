//
// Created by asus on 5/3/2022.
//

#ifndef EMAIL_EMAILADDRESS_H
#define EMAIL_EMAILADDRESS_H


#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

class EmailAddress {
private:
    string address;

public:
    explicit EmailAddress() = default;
    explicit EmailAddress(string address);
    EmailAddress(const EmailAddress &other);
    EmailAddress &operator=(const EmailAddress &other);
    ~EmailAddress() = default;

    string getAddress() const;
    void setAddress(const string& address);

private:
    string toString() const;

public:
    friend istream& operator>>(istream& is, EmailAddress& emailAddress);
    friend ostream& operator<<(ostream& os, const EmailAddress& emailAddress);

    bool isValid() const;

private:
    static bool isValidStr(const string& str);

    friend class EmailLetter;
};


#endif //EMAIL_EMAILADDRESS_H
