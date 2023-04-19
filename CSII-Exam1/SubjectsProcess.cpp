#include "SubjectsProcess.h"
#include "Utils.h"
#include <iostream>
#include <fstream>

using namespace std;

void displaySubjects(char *name) {
    ifstream file("subjects");

    if (file.is_open()) {
        system("clear");
        cout << "\n\tBienvenid@ " << name << endl;
        cout << "\n\tLista de materias disponibles:\n\n";
        cout << "Código,Nombre,Créditos,Horas teoría,"
                "Horas práctica,Horario disponible" << endl;
                    cout << "-------------------------------"
                "----------------------------"
                "----------"
             << endl;

        int bufferSize = 100;
        char *line = new char[bufferSize];

        while (!file.eof()) {
            file.getline(line, bufferSize);
            while (file.fail() && !file.eof()) {
                file.clear();
                file.ignore(bufferSize, '\n');
                bufferSize *= 2;
                delete[] line;
                line = new char[bufferSize];
                file.getline(line, bufferSize);
            }
            if (!file.eof()) {
                cout << line << endl;
            }
        }
        delete[] line;
        file.close();
    } else {
        cerr << "Error al abrir el archivo de subjects" << endl;
    }
}

void enrollSubjects(const char *id) {
    const int bufferSize = 100;
    char subjectCode[10];
    char enrolledSubjects[1000] = "";
    int totalCredits = 0;
    bool finished = false;

    while (!finished) {
        cout << "\n\t¿Qué materias desea matricular?, ingrese el código: ";
        cin >> subjectCode;

        char subjectDetails[bufferSize];
        int subjectCredits = 0;

        if (getSubjectDetails(subjectCode, subjectDetails,
                              subjectCredits)){
            if (totalCredits + subjectCredits <= 16) {

                totalCredits += subjectCredits;

                ofstream file(id, ios::app);

                if (file.is_open()) {
                    //file << subjectDetails << endl;
                    char modifiedSubjectDetails[bufferSize];
                    customStrcpy(modifiedSubjectDetails, subjectCode);
                    customStrcat(modifiedSubjectDetails, ",");

                    int commaCount = 0;
                    int srcIndex = 0;
                    int destIndex = customStrlen(modifiedSubjectDetails);
                    while (subjectDetails[srcIndex] != '\0') {
                        if (subjectDetails[srcIndex] == ',') {
                            commaCount++;
                        }

                        // Copia la cadena hasta la segunda coma
                        if (commaCount < 1 || commaCount >= 4) {
                            modifiedSubjectDetails[destIndex++] =
                                subjectDetails[srcIndex];
                        }
                        srcIndex++;
                    }

                    modifiedSubjectDetails[destIndex] = '\0';
                    //customStrcat(modifiedSubjectDetails, subjectDetails);

                    file << modifiedSubjectDetails << endl;
                    customStrcat(enrolledSubjects, modifiedSubjectDetails);
                    customStrcat(enrolledSubjects, "\n");
                    file.close();
                } else {
                    cerr << "Error al abrir el archivo " << id << endl;
                }

                cout << "\n\tMaterias matriculadas:" << endl;
                cout << enrolledSubjects << endl;
                cout << "\tCréditos matriculados: " << totalCredits << endl;


                char decision;
                if (totalCredits >= 8) {
                    do {
                        cout << "\t¿Deseas matricular otra materia? (S/N): ";
                                cin >> decision;

                        // Limpiar el búfer

                        while (cin.get() != '\n');
                    } while (decision != 'S' && decision != 's' &&
                             decision != 'N' && decision != 'n');

                    if (decision == 'N' || decision == 'n') {
                        finished = true;
                    }
                }
            } else {
                cout << "Matricular esta materia excedería el "
                        "límite de 16 créditos. "
                     << "Se terminará el proceso de matrícula." << endl;
                            finished = true;
            }
        } else {
            cout << "No se ha encontrado la materia con el código ingresado."
                    " Por favor, intente nuevamente." << endl;
        }
    }
}


bool getSubjectDetails(const char *code, char *subjectDetails,
                       int &subjectCredits) {
    ifstream file("subjects");

    if (file.is_open()) {
        char currentCode[10];
        while (!file.eof()) {
            file.getline(currentCode, 10, ',');
            file.getline(subjectDetails, 100, '\n');

            if (stringCompare(currentCode, code)) {
                // Obtener los créditos de la materia
                int commaCount = 0;
                for (int i = 0; subjectDetails[i] != '\0'; i++) {
                    if (subjectDetails[i] == ',') {
                        commaCount++;
                        if (commaCount == 2) {
                            subjectCredits = 0;
                            for (int j = i + 1; subjectDetails[j] != ',';
                                 j++) {
                                subjectCredits = subjectCredits * 10 +
                                                 (subjectDetails[j] - '0');
                            }
                            break;
                        }
                    }
                }

                file.close();
                return true;
            }
        }
        file.close();
    } else {
        cerr << "Error al abrir el archivo de subjects" << endl;
    }

    return false;
}
