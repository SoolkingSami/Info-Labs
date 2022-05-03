//
// Created by asus on 5/3/2022.
//

#include "EmailAddress.h"

EmailAddress::EmailAddress(string address): address(move(address)) {}

EmailAddress::EmailAddress(const EmailAddress &other): address(other.address) {}

EmailAddress &EmailAddress::operator=(const EmailAddress &other) {
    if (this != &other) {
        address = other.address;
    }
    return *this;
}

istream &operator>>(istream &is, EmailAddress &emailAddress) {
    getline(is, emailAddress.address);
    return is;
}

string EmailAddress::getAddress() const {
    return address;
}

void EmailAddress::setAddress(const string &address) {
    EmailAddress::address = address;
}

string EmailAddress::toString() const {
    return address;
}

ostream &operator<<(ostream &os, const EmailAddress &emailAddress) {
    os << emailAddress.toString();
    return os;
}

bool EmailAddress::isValidStr(const string &str) {
    if (str.empty()) {
        return false;
    }

    for (auto c: str) {
        if (!isalpha(c) && !isdigit(c) && c != '.' && c != '_') {
            return false;
        }
    }

    return true;
}

bool EmailAddress::isValid() const {
    istringstream iss(address);
    string name, domain;
    getline(iss, name, '@');
    getline(iss, domain, '@');

    istringstream iss2(domain);
    string subsubdomain, subdomain, domainName;

    getline(iss2, subsubdomain, '.');
    getline(iss2, subdomain, '.');
    getline(iss2, domainName, '.');

    return isValidStr(name) && isValidStr(domainName)
        && isValidStr(subdomain)&& isValidStr(subsubdomain)
        && domainName.length() > 1 && domainName.length() < 4;
}
