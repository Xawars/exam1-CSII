#include "Utils.h"
#include "StudentsProcess.h"

bool isValidID(const char *id) {
    for (int i = 0; id[i] != '\0'; i++) {
        if (id[i] < '0' || id[i] > '9') {
            return false;
        }
    }
    return true;
}

bool isValidName(const char *name) {
    for (int i = 0; name[i] != '\0'; i++) {
        if ((name[i] < 'A' || name[i] > 'Z') && (name[i] < 'a' ||
                                                 name[i] > 'z') &&
            name[i] != ' ') {
            return false;
        }
    }
    return true;
}

void saveStudentData(const char *id, const char *name) {
    ofstream file;
    file.open("students", ios::app);
    file << id << "," << name << endl;
    file.close();
}



void showMenu1() {

    int option;
    cout << "Escoja una opción: " << endl;
    cout << "1. Ver datos" << endl;
    cout << "2. Registrarme" << endl;
    cout << "Opción: ";
    cin >> option;

    if (option == 1) {
        confirmStudent();
    } else if (option == 2) {
        registerStudent();
    } else {
        cout << "Opción invalida." << endl;
    }

}

int customStrlen(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void showMenu2() {

    int option;
    cout << "Escoja una opción: ";
    cout << "1. Ver materias matriculadas" << endl;
    cout << "2. Ver mi calendario de cursos" << endl;
    cout << "3. Ver mi calendario de estudio independiente" << endl;
    cin >> option;

    if (option == 1) {
        // Función para ver materias matriculadas
    } else if (option == 2) {
        // Función para ver calendario de cursos
    } else if (option == 3) {
        // Función para ver calendario de estudio independiente
    } else {
        cout << "Opción invalida." << endl;
    }

}



