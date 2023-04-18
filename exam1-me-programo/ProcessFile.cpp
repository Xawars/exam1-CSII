#include "ProcessFile.h"
#include "CoursesInformation.h"
#include "HoursPerWeekCourses.h"
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

    calculate_sizes(file, num_students, max_line_length, max_name_length);

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

    cout << "\n\t" << "Ingrese el ID del estudiante con el que se va\n"
            "\ta gestionar las jornadas de estudio: ";
    int input_id;
    cin >> input_id;

    bool found = false;
    for (int i = 0; i < count; i++) {
        if (ids[i] == input_id) {
            found = true;
            cout << "\t\t\nEstudiante encontrado: " << names[i] << endl;
            break;
        }
    }

    if (!found) {
        cout << "\t\nEstudiante no encontrado." << endl;
    }

    // Liberar memoria dinámica
    delete[] line;
    delete[] ids;
    for (int i = 0; i < num_students; i++) {
        delete[] names[i];
    }
    delete[] names;

    display_courses(input_id);
    schedule_courses(input_id);
}

