#include "Utils.h"

bool isValidID(const char *id) {
    for (int i = 0; id[i] != '\0'; i++) {
        if (id[i] < '0' || id[i] > '9') {
            return false;
        }
    }
    return true;
}

bool isValidName(const char *name) {
    for (int i = 0; name[i] != '\0'; i++) {
        if ((name[i] < 'A' || name[i] > 'Z') && (name[i] < 'a' ||
                                                 name[i] > 'z') &&
            name[i] != ' ') {
            return false;
        }
    }
    return true;
}

bool stringCompare(const char *str1, const char *str2) {
    while (*str1 && *str2) {
        if (*str1 != *str2) {
            return false;
        }
        str1++;
        str2++;
    }
    return *str1 == *str2;
}
