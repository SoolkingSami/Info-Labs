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

        delete app;
    } catch (invalid_argument &e) {
        cerr << e.what() << endl;
    }

	return 0;
}
