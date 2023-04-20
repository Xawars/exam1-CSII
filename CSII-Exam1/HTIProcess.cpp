#include "HTIProcess.h"
#include "Utils.h"
#include <fstream>
#include <iostream>

using namespace std;

int calculateHTI(int credits, int theoreticalHours, int practicalHours) {
    if (credits == 1 && practicalHours == 2) {
        int independentStudyHours = 1;
        return independentStudyHours;
    } else if (credits == 1 && practicalHours == 0) {
        int independentStudyHours = 0;
        return independentStudyHours;
    } else {
        int totalHoursPerSemester = 48 * credits;
        int hoursPerWeek = totalHoursPerSemester / 16;
        int independentStudyHours = hoursPerWeek - (theoreticalHours
                                                    + practicalHours);
        return independentStudyHours;
    }
}

void generateHTI(const char *id, const char *enrolledSubjects) {
    char outputFileName[50];
    customStrcpy(outputFileName, id);
    customStrcat(outputFileName, "_HTI");

    ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        cerr << "Error al abrir el archivo " << outputFileName << endl;
        return;
    }

    int bufferSize = 100;
    char line[bufferSize];

    for (int i = 0; enrolledSubjects[i] != '\0';) {
        int j = 0;
        while (enrolledSubjects[i] != '\n' && enrolledSubjects[i] != '\0') {
            line[j++] = enrolledSubjects[i++];
        }
        line[j] = '\0';

        if (enrolledSubjects[i] == '\n') {
            i++;
        }

        int credits, theoreticalHours, practicalHours;
        getSubjectInfo(line, credits, theoreticalHours, practicalHours);
        int hti = calculateHTI(credits, theoreticalHours, practicalHours);

        while (hti > 0) {
            cout << "\nMateria: " << line << endl;
            cout << "Horas de estudio independientes restantes: " << hti << endl;
            cout << "¿Cómo quiere repartir las horas durante la semana? "
                    "(Por ejemplo: S8-10): ";
            char schedule[10];
            cin >> schedule;
            int startHour, endHour;
            extractHours(schedule, startHour, endHour);

            int hours = endHour - startHour;

            if (hours <= hti) {
                outputFile << line << "," << schedule << endl;
                hti -= hours;
            } else {
                cout << "La cantidad de horas ingresadas excede las horas de estudio"
                        " independientes restantes. Por favor, intente nuevamente."
                     << endl;
            }
        }
    }

    cout << "Se ha generado las jornadas de estudio con éxito!" << endl;
    outputFile.close();
}

void getSubjectInfo(const char *line, int &credits, int &theoreticalHours,
                    int &practicalHours) {
    int commaCount = 0;
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == ',') {
            commaCount++;
            if (commaCount == 2) {
                credits = line[i + 1] - '0';
            } else if (commaCount == 3) {
                theoreticalHours = line[i + 1] - '0';
            } else if (commaCount == 4) {
                practicalHours = line[i + 1] - '0';
                break;
            }
        }
    }
}

void extractHours(const char *schedule, int &startHour, int &endHour) {
    int index = 1;
    startHour = 0;
    endHour = 0;

    while (schedule[index] != '-') {
        startHour = startHour * 10 + (schedule[index] - '0');
        index++;
    }

    index++;

    while (schedule[index] != '\0') {
        endHour = endHour * 10 + (schedule[index] - '0');
        index++;
    }
}
