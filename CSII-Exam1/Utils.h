#ifndef UTILS_H
#define UTILS_H

bool isValidID(const char *id);
bool isValidName(const char *name);

bool stringCompare(const char *str1, const char *str2);
void customStrcat(char *destination, const char *source);
void customStrcpy(char *destination, const char *source);
int customStrlen(const char *str);

#endif // UTILS_H
