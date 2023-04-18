#include "Utils.h"

void registerStudent() {
    char *id = nullptr;
    char *name = nullptr;
    unsigned long bufferSize = 0;
    long inputLength;

    cout << "Por favor ingrese su cedula (ID): ";
    inputLength = getline(&id, &bufferSize, stdin);
    id[inputLength - 1] = '\0';

    while (!isValidID(id)) {
        cout << "Identificación invalida. Ingrese solo numeros: ";
            inputLength = getline(&id, &bufferSize, stdin);
        id[inputLength - 1] = '\0';
    }

    cout << "Por favor ingrese su nombre: ";
    inputLength = getline(&name, &bufferSize, stdin);
    name[inputLength - 1] = '\0';

    while (!isValidName(name)) {
        cout << "Nombre invalido. Ingrese solo letras y espacios: ";
        inputLength = getline(&name, &bufferSize, stdin);
        name[inputLength - 1] = '\0';
    }

    saveStudentData(id, name);
    cout << "Estudiante " << name << " con ID " << id << " guardado"
                                                         " exitosamente!. "
         << endl;

    free(id);
    free(name);
}

void displayStudents() {
    ifstream file("students");
    char line[256];
    cout << "Estudiantes registrados: " << endl;
    while (file.getline(line, sizeof(line))) {
        cout << line << endl;
    }
    file.close();
    cout << endl;
}

void confirmStudent() {
    cout << "Ingresa tu ID: ";
}



