//
// Created by asus on 5/3/2022.
//

#ifndef EMAIL_EMAILLETTER_H
#define EMAIL_EMAILLETTER_H


#include <string>
#include <sstream>
#include <iostream>
#include "EmailAddress.h"

using namespace std;

class EmailLetter {
private:
    EmailAddress from;
    EmailAddress to;
    string subject;
    string body;

public:
    explicit EmailLetter() = default;
    explicit EmailLetter(string from, string to, string subject, string body);
    EmailLetter(const EmailLetter &email);
    EmailLetter &operator=(const EmailLetter &email);
    ~EmailLetter() = default;

    EmailAddress getFrom() const;
    EmailAddress getTo() const;
    string getSubject() const;
    string getBody() const;

    void setFrom(const string& from);
    void setTo(const string& to);
    void setSubject(const string& subject);
    void setBody(const string& body);

    bool isValid() const;

private:
    string toString() const;

public:
    friend istream &operator>>(istream &is, EmailLetter &email);
    friend ostream &operator<<(ostream &os, const EmailLetter &email);
};


#endif //EMAIL_EMAILLETTER_H
