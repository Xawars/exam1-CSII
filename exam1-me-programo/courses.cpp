#include "courses.h"
#include <iostream>
#include <fstream>

using namespace std;

int readCourses(const char* file, char codes[][maxLenght],
                char subjects[][maxLenght], int credits[],
                int theoreticalHours[], int practiceHours[],
                int independentHours[]) {

    ifstream input(file);
    int index = 0;

    if (input.is_open()) {
        while (!input.eof()) {
            input.getline(codes[index], maxLenght, ',');
            input.getline(subjects[index], maxLenght, ',');
            input >> credits[index];
            input.ignore();
            input >> theoreticalHours[index];
            input.ignore();
            input >> practiceHours[index];
            input.ignore();
            input >> independentHours[index];
            input.ignore();

            index++;
        }
        input.close();
    } else {
        cout << "No se pudio abrir el archivo." << endl;
    }

    return index;
}

void processCourse() {
    char **codes= new char*[maxAmountCourses];
    char **subjects = new char*[maxAmountCourses];
    int *credits = new int[maxAmountCourses];
    int *theoreticalHours = new int[maxAmountCourses];
    int *practiceHours = new int[maxAmountCourses];
    int *independentHours = new int[maxAmountCourses];

    for (int i = 0; i < maxAmountCourses; i++) {
        codes[i] = new char[maxLenght];
        subjects[i] = new char[maxLenght];
    }

    char file[maxLenght];
    cout << "Ingrese el nombre del archivo (sin la extensión .txt): ";
    cin >> file;
    int length = 0;
    for (length = 0; file[length] != '\0'; length++);
    file[length] = '.';
    file[length + 1] = 't';
    file[length + 2] = 'x';
    file[length + 3] = 't';
    file[length + 4] = '\0';

    int amountCourses = readCourses(file, codes, subjects, credits,
                                    theoreticalHours, practiceHours,
                                    independentHours);

    for (int i = 0; i < amountCourses; i++) {
        cout << codes[i] << ", " << subjects[i] << ", " << credits[i] << ", "
             << theoreticalHours[i] << ", " << practiceHours[i] << ", "
             << independentHours[i] << endl;
    }

    for (int i = 0; i < maxAmountCourses; i++) {
        delete[] codes[i];
        delete[] subjects[i];
    }

    delete[] codes;
    delete[] subjects;
    delete[] credits;
    delete[] theoreticalHours;
    delete[] practiceHours;
    delete[] independentHours;
}
