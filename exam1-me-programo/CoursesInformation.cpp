#include "CoursesInformation.h"
#include "Utils.h"
#include <fstream>
#include <iostream>

using namespace std;

int calculate_hti(int credits, int theory_hours, int practice_hours) {
    if (credits > 1) {
        int total_hours = 48 * credits;
        int class_hours = theory_hours + practice_hours;
        int indepenpent_study_hours = total_hours / 16 - class_hours;
        return indepenpent_study_hours;
    } else {
        int independent_study_hours = 0;
        return independent_study_hours;
    }
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
    for (; line[i] != ',' && line[i] != '\0'; i++) { // Añadir comprobación
        // adicional
        practice_hours = practice_hours * 10 + (line[i] - '0');
    }
}

void display_courses(int input_id) {
    char subject_file_name[20];
    int_to_str(input_id, subject_file_name, sizeof(subject_file_name));
    ifstream subject_file(subject_file_name);

    if (!subject_file) {
        cerr << "\t\nNo se pudo abrir el archivo de materias." << endl;
        return;
    }

    cout << "\t" << "\t\nSus materias matriculadas en el semestre son:\n"
         << endl;

    ofstream temp_file("temp.txt");
    if (!temp_file) {
        cerr << "\t\nNo se pudo crear el archivo temporal." << endl;
        return;
    }

    int num_subjects = 0;
    int max_subject_line_length = 0;
    int max_subject_name_length = 0;

    // Calcular el tamaño máximo de las líneas de materias y nombres
    // de materias
    ifstream subject_file_for_size_calculation(subject_file_name);
    if (!subject_file_for_size_calculation) {
        cerr << "\t\nNo se pudo abrir el archivo de materias para calcular"
                " los tamaños máximos." << endl;
            return;
    }

    calculate_sizes(subject_file_for_size_calculation, num_subjects,
                    max_subject_line_length, max_subject_name_length);

    // Asignar memoria dinámica utilizando los tamaños máximos calculados
    char *subject_line = new char[max_subject_line_length + 1];
    char *subject_name = new char[max_subject_name_length + 1];

    while (subject_file.getline(subject_line, max_subject_line_length +1 ))
    {
        long long code;
        int credits, theory_hours, practice_hours;

        parse_subject_line(subject_line, code, subject_name, credits,
                           theory_hours, practice_hours);
        int independent_study_hours = calculate_hti(credits, theory_hours,
                                                    practice_hours);

        cout << code << "," << subject_name << "," << credits << "," <<
            theory_hours << "," << practice_hours << ",HTI:"
             << independent_study_hours << endl;
        temp_file << code << "," << subject_name << "," << credits << ","
                  << theory_hours << "," << practice_hours << ",HTI:"
                  << independent_study_hours << endl;
    }
    subject_file.close();
    temp_file.close();

    remove(subject_file_name);
    rename("temp.txt", subject_file_name);

    delete[] subject_line;
    delete[] subject_name;
}


