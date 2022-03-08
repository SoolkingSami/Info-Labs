#include <iostream>
#include "application_logic/Application.h"
#include "presentation/PatientView.h"

using namespace std;

int main() {
    try {
        auto *patientRepository = new PatientRepository("patients.txt");
        auto *patientView = new PatientView();
        auto *app = new Application(patientRepository, patientView);
        app->run();
    } catch (invalid_argument &e) {
        cerr << e.what() << endl;
    }

    cout << "Press any key to exit..." << endl;
    getchar();
    return 0;
}
