#include "ProcessFile.h"
#include "StudentsProcess.h"
#include "SubjectsProcess.h"
#include "HTIProcess.h"
#include "Utils.h"
#include <iostream>
#include <fstream>

using namespace std;

void runProgram() {
    cout << "\n\tSISTEMA DE MATRICULA 2023-2\n" << endl;

    char *id = new char[20];
    char *name = new char[50];
    int option;

    while (true) {
        cout << "Por favor ingrese su número de identificación (id): ";
        cin >> id;
        if (isValidID(id)) {
            break;
        }
        cout << "El ID ingresado no es válido. Por favor, ingrese solo "
                "números." << endl;
    }

    if (!findStudent(id, name)) {
        while (true) {
            cout << "Por favor ingrese su nombre completo: ";
            cin.ignore();
            cin.getline(name, 50);
            if (isValidName(name)) {
                break;
            }
            cout << "El nombre ingresado no es válido. Por favor, "
                    "ingrese solo letras y espacios." << endl;
        }
        addStudent(id, name);
        displaySubjects(name);
        char *enrolledSubjects = enrollSubjects(id);
        generateHTI(id, enrolledSubjects);
        delete[] enrolledSubjects;
    } else {
        system("clear");
        cout << "\n\tBienvenid@ " << name << endl;

        do {
            cout << "\nSeleccione una opción:\n";
            cout << "1. Ver mi matricula\n";
            cout << "2. Ver mis jornadas de estudio\n";
            cout << "3. Salir del programa\n";
            cout << "Opción: ";
            cin >> option;

            switch (option) {
            case 1:
                system("clear");
                cout << "\n\tEstudiante: " << name << endl;
                displayEnrollment(id);
                break;
            case 2:
                system("clear");
                cout << "\n\tEstudiante: " << name << endl;
                displayStudySessions(id);
                break;
            case 3:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida. Por favor, intente nuevamente."
                     << endl;
            }
        } while (option != 3);
    }

    delete[] id;
    delete[] name;
}


void displayEnrollment(const char *id) {
    ifstream file(id);

    if (file.is_open()) {
        cout << "\n\tMaterias matriculadas:\n";

        char line[100];
        while(file.getline(line, 100)) {
            cout << line << endl;
        }

        file.close();
    } else {
        cerr << "Error al abrir el archivo " << id << endl;
    }
}

void displayStudySessions(const char *id) {
    char fileName[50];
    customStrcpy(fileName, id);
    customStrcat(fileName, "_HTI");

    ifstream file(fileName);

    if (file.is_open()) {
        cout << "\n\tJornadas de estudio:\n";

        char line[100];
        while (file.getline(line, 100)) {
            cout << line << endl;
        }

        file.close();
    } else {
        cerr << "Error al abrir el archivo " << fileName << endl;
    }
}
