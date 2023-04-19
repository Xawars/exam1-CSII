#include "ProcessFile.h"
#include "StudentsProcess.h"
#include "Utils.h"

void runProgram() {
    cout << "\n\tSISTEMA DE MATRICULA 2023-2\n" << endl;

    char *id = new char[20];
    char *name = new char[50];
    int option;

    cout << "Por favor ingrese su número de identificación (id): ";
    cin >> id;

    if (isValidID(id)) {

        if (!findStudent(id, name)) {
            cout << "Por favor ingrese su nombre completo: ";
            cin.ignore();
            cin.getline(name, 50);
            addStudent(id, name);
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
                    // Implementar función para ver matrícula
                    break;
                case 2:
                    // Implementar función para ver jornadas de estudio
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
    } else {
        cout << "El ID ingresado no es válido. Debe contener solo números."
             << endl;
    }

    delete[] id;
    delete[] name;

}
