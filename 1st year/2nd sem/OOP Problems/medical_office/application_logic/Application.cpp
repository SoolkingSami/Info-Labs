//
// Created by asus on 2/16/2022.
//

#include "Application.h"

Application::Application(IPatientRepository *repository, IView<Patient> *view) :
        patientRepository(repository),
        patientView(view) {}

void Application::run() {
    while (true) {
        patientView->printMenu();
        switch (patientView->askForCommand()) {
            case 1:
                patientView->printByCategory(patientRepository->getAll());
                break;
            case 2:
                patientView->printByCategory(patientRepository->getAdultsWithHighCardioVascularRisk());
                break;
            case 3:
                patientView->printByCategory(patientRepository->getChildrenWithCardioVascularRisk());
                break;
            case 4:
                patientView->printByCategory(patientRepository->getByName(patientView->askForName()));
                break;
            case 5:
                return;
            default:
                patientView->printError("Invalid command!");
        }
        patientView->pause();
    }
}

Application::~Application() {
    delete patientRepository;
    delete patientView;
}
