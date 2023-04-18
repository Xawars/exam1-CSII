#include "HoursPerWeekCourses.h"
#include <iostream>
#include <fstream>
#include "CoursesInformation.h"
#include "Utils.h"

using namespace std;

bool is_time_slot_available(const char *time_slot,
                            const char **assigned_schedule,
                            int assigned_schedule_size) {

    for (int i = 0; i < assigned_schedule_size; i++) {
        if (custom_strcmp(time_slot, assigned_schedule[i]) == 0) {
            return false;
        }
    }
    return true;
}

void schedule_courses(int student_id) {
    char courses_file_name[20];
    int_to_str(student_id, courses_file_name,
               sizeof(courses_file_name));
    ifstream courses_file(courses_file_name);

    if (!courses_file) {
        cerr << "No se pudo abrir el archivo de materias." << endl;
        return;
    }

    char schedule_file_name[25];
    custom_strcpy(schedule_file_name, courses_file_name);
    custom_strcat(schedule_file_name, "_schedule.txt");
    ofstream schedule_file(schedule_file_name);

    if (!schedule_file) {
        cerr << "No se pudo crear el archivo de horario." << endl;
        return;
    }

    const int max_line_length = 200;
    char line[max_line_length];

    while (courses_file.getline(line, max_line_length)) {
        long long code;
        char subject_name[100];
        int credits, theory_hours, practice_hours;

        parse_subject_line(line, code, subject_name, credits, theory_hours
                           , practice_hours);

        char **assigned_schedule = new char *[theory_hours +
                                              practice_hours];
        int assigned_schedule_size = 0;

        cout << "Asignando horario para " << subject_name << " (Teoría: " <<
            theory_hours << " horas, Práctica: " << practice_hours <<
            " horas):" << endl;

        int remaining_theory_hours = theory_hours;
        int remaining_practice_hours = practice_hours;

        while (remaining_theory_hours > 0 || remaining_practice_hours > 0){
            cout << "Quedan " << remaining_theory_hours <<
                " horas teóricas y " << remaining_practice_hours <<
            " horas prácticas. Ingresa el horario deseado "
                "(Ejemplo: L8-10): ";


            char day_time_slot[10];
            cin >> day_time_slot;

            if (is_time_slot_available(day_time_slot,
                                       const_cast<const char**>(assigned_schedule),
                                       assigned_schedule_size)) {
                char *new_time_slot = new char[custom_strlen(day_time_slot)+1];
                custom_strcpy(new_time_slot, day_time_slot);
                assigned_schedule[assigned_schedule_size++] = new_time_slot;

                if (remaining_theory_hours > 0) {
                    remaining_theory_hours -= 2;
                } else {
                    remaining_practice_hours -= 2;
                }

            } else {
                     cout << "Lo siento, ese horario ya está ocupado, "
                        "escoge otro." << endl;
            }
        }
        schedule_file << code << "," << credits;
        for (int i = 0; i < assigned_schedule_size; i++) {
            schedule_file << "," << assigned_schedule[i];
            delete[] assigned_schedule[i];
        }
        schedule_file << endl;

        delete[] assigned_schedule;
    }

    courses_file.close();
    schedule_file.close();
}
