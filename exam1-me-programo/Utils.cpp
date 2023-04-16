#include "Utils.h"

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
