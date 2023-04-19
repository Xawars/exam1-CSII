#include <iostream>
#include <fstream>
#include "StudentsProcess.h"
#include "Utils.h"

using namespace std;

bool findStudent(const char *id, char *name) {
    ifstream file("students");
    if (file.is_open()) {
        char currentId[20];
        while (!file.eof()) {
            file.getline(currentId, 20, ',');
            file.getline(name, 50);
            if (file.eof()) {
                break;
            }
            if (stringCompare(currentId, id)) {
                file.close();
                return true;
            }
        }
        file.close();
    }

    return false;
}

void addStudent(const char *id, const char *name) {
    ofstream file("students", ios::app);
    if (file.is_open()) {
        file << id << ',' << name << endl;
        file.close();
    } else {
        cerr << "Error al abrir el archivo students.txt" << endl;
    }
}
