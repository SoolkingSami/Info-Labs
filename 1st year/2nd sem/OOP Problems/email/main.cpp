#include <iostream>
#include "EmailLetter.h"

using namespace std;

int main() {
    auto email1 = EmailLetter("sami@ucv.gmail.com", "alin@ucv.yahoo.com", "None", "Hello");
    auto email2 = EmailLetter("sami@gmail.como", "alin@.com", "None", "Hello");

    cout << email1 << (email1.isValid() ? "---> is valid" : "---> is not valid") << endl;
    cout << email2 << (email2.isValid() ? "---> is valid" : "---> is not valid") << endl;

    auto email3 = EmailLetter();
    cin >> email3;
    cout << email3 << (email3.isValid() ? "---> is valid" : "---> is not valid") << endl;

    return 0;
}
