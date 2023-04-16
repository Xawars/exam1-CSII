#include "CoursesInformation.h"

int calculate_hti(int credits, int theory_hours, int practice_hours) {
    int total_hours = 48 * credits;
    int class_hours = theory_hours + practice_hours;
    int independent_study_hours = total_hours / 16 - class_hours;
    return independent_study_hours;
}

void parse_subject_line(const char *line, long long &code,
                        char *subject_name, int &credits,
                        int &theory_hours, int &practice_hours) {
    code = 0;
    int i = 0;

    // Extraer código de la materia
    for (; line[i] != ','; i++) {
        code = code * 10 + (line[i] - '0');
    }

    i++; // Saltar la coma
    int j = 0;
    // Extraer el nombre de la materia
    for (; line[i] != ','; i++, j++) {
        subject_name[j] = line[i];
    }
    subject_name[j] = '\0';
    i++; // Saltar la coma

    // Extraer los créditos
    credits = 0;
    for (; line[i] != ','; i++) {
        credits = credits * 10 + (line[i] - '0');
    }
    i++; // Saltar la coma

    // Extraer las horas de teoría
    theory_hours = 0;
    for (; line[i] != ','; i++) {
        theory_hours = theory_hours * 10 + (line[i] - '0');
    }
    i++; // Saltar la coma

    // Extraer las horas de práctica
    practice_hours = 0;
    for (; line[i] != ',' && line[i] != '\0'; i++) { // Añadir comprobación adicional
        practice_hours = practice_hours * 10 + (line[i] - '0');
    }
}

