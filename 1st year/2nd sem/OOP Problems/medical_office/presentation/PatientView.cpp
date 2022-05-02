//
// Created by asus on 2/17/2022.
//

#include "PatientView.h"

void PatientView::printMenu() {
    system("cls");
    cout << "1. Afiseaza informatiile medicale pentru toti pacientii." << endl;
    cout << "2. Afiseaza informatiile medicale pentru toti pacientii adulti cu factor de risc cardiovascular ridicat." << endl;
    cout << "3. Afiseaza informatiile medicale pentru toti pacientii copii cu factor de risc cardiovascular." << endl;
    cout << "4. Afiseaza informatiile medicale pentru toti pacientii cu un anumit nume de familie." << endl;
    cout << "5. Exit." << endl;
}

void PatientView::printByCategory(const vector<Patient *> &patients) {
    cout << "\nAdulti peste 40 de ani: " << endl;
    for (const auto &patient : patients) {
        if (patient->getAge() > 40) {
            cout << *patient << endl;
        }
    }
    cout << "\nAdulti sub 40 de ani: " << endl;
    for (const auto &patient : patients) {
        if (18 < patient->getAge() && patient->getAge() <= 40) {
            cout << *patient << endl;
        }
    }
    cout << "\nCopii: " << endl;
    for (const auto &patient : patients) {
        if (patient->getAge() <= 18) {
            cout << *patient << endl;
        }
    }
    cout << endl;
}

string PatientView::askForName() {
    string name;
    cout << "Introduceti numele de familie: ";
    cin >> name;
    return name;
}

int PatientView::askForCommand() {
    int command;
    cout << "Introduceti comanda: ";
    cin >> command;
    return command;
}

void PatientView::pause() {
    cout << "Apasati orice tasta pentru a continua...";
    cin.get();
    cin.get();
}

void PatientView::printError(const string &error) {
    cerr << error << endl;
    exit(1);
}

PatientView::~PatientView() = default;
