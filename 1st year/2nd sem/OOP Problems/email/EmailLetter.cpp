//
// Created by asus on 5/3/2022.
//

#include "EmailLetter.h"

EmailLetter::EmailLetter(string from, string to, string subject, string  body):
    from(move(from)), to(move(to)), subject(move(subject)), body(move(body)) {}

EmailLetter::EmailLetter(const EmailLetter &other):
    from(other.from), to(other.to), subject(other.subject), body(other.body) {}

EmailLetter &EmailLetter::operator=(const EmailLetter &email) {
    if (this != &email) {
        from = email.from;
        to = email.to;
        subject = email.subject;
        body = email.body;
    }
    return *this;
}

EmailAddress EmailLetter::getFrom() const {
    return from;
}

EmailAddress EmailLetter::getTo() const {
    return to;
}

string EmailLetter::getSubject() const {
    return subject;
}

string EmailLetter::getBody() const {
    return body;
}

void EmailLetter::setFrom(const string& from) {
    this->from.setAddress(from);
}

void EmailLetter::setTo(const string& to) {
    this->to.setAddress(to);
}

void EmailLetter::setSubject(const string& subject) {
    EmailLetter::subject = subject;
}

void EmailLetter::setBody(const string& body) {
    EmailLetter::body = body;
}

bool EmailLetter::isValid() const {
    return from.isValid() && to.isValid() && !subject.empty() && !body.empty();
}

string EmailLetter::toString() const {
    return "\nFrom: " + from.toString() + "\nTo: " + to.toString() +
           "\nSubject: " + subject + "\nBody: " + body + "\n";
}

istream &operator>>(istream &is, EmailLetter &email) {
    cout << "From:\n";
    is >> email.from;
    cout << "To:\n";
    is >> email.to;
    cout << "Subject:\n";
    getline(is, email.subject);
    cout << "Body:\n";
    getline(is, email.body);

    return is;
}

ostream &operator<<(ostream &os, const EmailLetter &email) {
    os << email.toString();
    return os;
}


