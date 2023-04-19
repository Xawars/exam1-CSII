#include "SubjectsProcess.h"
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
                    cout << "-----------------------------------------------------------"
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
