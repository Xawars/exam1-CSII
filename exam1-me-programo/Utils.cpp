#include "Utils.h"

using namespace std;

// Función para dividir una línea en ID y nombre.
void parse_line(const char *line, long long &id, char *name) {
    id = 0;
    int i = 0;

    for(; line[i] != ','; i++) {
        id = id * 10 + (line[i] - '0');
    }

    i++; // Saltar la coma
    int j = 0;
    for (; line[i] != '\0'; i++, j++) {
        name[j] = line[i];
    }
    name[j] = '\0';
}

void int_to_str(int number, char *str, int buffer_size) {
    int i = 0;
    if (number == 0) {
        str[i++] = 0;
    } else {
        while (number > 0 && i < buffer_size - 1) {
            str[i++] = '0' + (number % 10);
            number /= 10;
        }
    }
    str[i] = '\0';

    // Invertir la cadena
    for (int j = 0; j < i / 2; j++) {
        char temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }
}

void calculate_sizes(ifstream &file, int &num_elements,
                     int &max_line_length, int &max_name_length) {
    num_elements = 0;
    max_line_length = 0;
    max_name_length = 0;
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
            num_elements++;
            max_line_length = max(max_line_length, line_length);
            max_name_length = max(max_name_length, name_length);
            line_length = 0;
            name_length = 0;
            in_name = false;
        }
    }
    num_elements++; // Para contar la última línea se agrega 1
    max_line_length = max(max_line_length, line_length);
    max_name_length = max(max_name_length, name_length);
    file.clear(); // Limpiar el estado del archivo
    file.seekg(0); // Devolver el cursor al inicio del archivo
}
