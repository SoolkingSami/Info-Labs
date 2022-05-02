cmake_minimum_required(VERSION 3.20)
project(medical_office)

set(CMAKE_CXX_STANDARD 20)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/patients.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(medical_office main.cpp data/entities/patient/Patient.h data/entities/utils/Cholesterol.cpp data/entities/utils/Cholesterol.h data/entities/utils/BloodPressure.cpp data/entities/utils/BloodPressure.h data/entities/utils/Sedentariness.h data/entities/adult_patient/AdultPatient.cpp data/entities/adult_patient/AdultPatient.h data/entities/young_adult_patient/YoungAdultPatient.cpp data/entities/young_adult_patient/YoungAdultPatient.h data/entities/child_patient/ChildPatient.cpp data/entities/child_patient/ChildPatient.h data/entities/utils/ProteinC.cpp data/entities/utils/ProteinC.h data/entities/utils/PersonDTO.cpp data/entities/utils/PersonDTO.h application_logic/Application.cpp application_logic/Application.h data/patient_repository/PatientRepository.cpp data/patient_repository/PatientRepository.h data/patient_scanner/PatientScanner.cpp data/patient_scanner/PatientScanner.h data/entities/patient/Patient.cpp data/entities/utils/Sedentariness.cpp data/patient_repository/IPatientRepository.h presentation/PatientView.cpp presentation/PatientView.h presentation/IView.h)

if (MSVC AND WIN32 AND NOT MSVC_VERSION VERSION_LESS 142)

    # option 2: apply the option on a per-target basis
    target_link_options(${PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:/INCREMENTAL>)
    target_compile_options(${PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:/ZI>)

endif()
