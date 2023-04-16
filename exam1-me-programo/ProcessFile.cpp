#include "ProcessFile.h"
#include "CoursesInformation.h"
#include "Utils.h"

void run_program() {
    const char *file_path = "./students";
    ifstream file(file_path);

    if (!file) {
        cerr << "No se pudo abrir el archivo." << endl;
        return;
    }

    // Contar el número de líneas (estudiantes) y el tamaño máximo de las
    // líneas y los nombres
    int num_students = 0;
    int max_line_length = 0;
    int max_name_length = 0;
    char c;
    int line_length = 0;
    int name_length = 0;
    bool in_name = false;
    while (file.get(c)) {
        line_length++;
        if (in_name) {
            name_length++;
        }
        if (c == ',') {
            in_name = true;
        }
        if (c == '\n') {
            num_students++;
            max_line_length = max(max_line_length, line_length);
            max_name_length = max(max_name_length, name_length);
            line_length = 0;
            name_length = 0;
            in_name = false;
        }
    }
    num_students++; // Para contar la última línea se agrega 1
    max_line_length = max(max_line_length, line_length);
    max_name_length = max(max_name_length, name_length);
    file.clear(); // Limpiar el estado del archivo
    file.seekg(0); // Devolver el cursor al inicio del archivo

    char *line = new char[max_line_length + 1]; // Se agrega 1 para el '\0'
    long long *ids = new long long[num_students];
    char **names = new char *[num_students]; // Se usa los punteros dobles
    // para almacenar los nombres

    for (int i = 0; i < num_students; i++) {
        names[i] = new char[max_name_length + 1];
    }

    int count = 0;

    while (file.getline(line, max_line_length + 1)) {
        parse_line(line, ids[count], names[count]);
        count++;
    }
    file.close();

    // Imprimir todos los estudiantes en la consola
    cout << "\n";
    for (int i = 0; i < count; i++) {
        cout << "\t" << ids[i] << "," << names[i] << endl;
    }

    cout << "\n\t" << "Ingrese el ID del estudiante con el que se va"
            " a gestionar las jornadas de estudio: ";
    int input_id;
    cin >> input_id;

    bool found = false;
    for (int i = 0; i < count; i++) {
        if (ids[i] == input_id) {
            found = true;
            cout << "Estudiante encontrado: " << names[i] << endl;
            break;
        }
    }

    if (!found) {
        cout << "Estudiante no encontrado." << endl;
    }

    // Liberar memoria dinámica
    delete[] line;
    delete[] ids;
    for (int i = 0; i < num_students; i++) {
        delete[] names[i];
    }
    delete[] names;

    char subject_file_name[20];
    sprintf(subject_file_name, "%d", input_id);
    ifstream subject_file(subject_file_name);

    if (!subject_file) {
        cerr << "No se pudo abrir el archivo de materias." << endl;
        return;
    }

    cout << "\nSus materias matriculadas en el semestre son:\n" << endl;

    ofstream temp_file("temp.txt");
    if (!temp_file) {
        cerr << "No se pudo crear el archivo temporal." << endl;
        return;
    }

    char subject_line[100];
    while (subject_file.getline(subject_line, 100)) {
        long long code;
        char subject_name[100];
        int credits, theory_hours, practice_hours;

        parse_subject_line(subject_line, code, subject_name, credits, theory_hours, practice_hours);
        int independent_study_hours = calculate_hti(credits, theory_hours, practice_hours);

        cout << code << "," << subject_name << "," << credits << "," << theory_hours << "," << practice_hours << ",HTI:" << independent_study_hours << endl;
        temp_file << code << "," << subject_name << "," << credits << "," << theory_hours << "," << practice_hours << ",HTI:" << independent_study_hours << endl;
    }
    subject_file.close();
    temp_file.close();

    remove(subject_file_name);
    rename("temp.txt", subject_file_name);

}

