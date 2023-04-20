#ifndef UTILS_H
#define UTILS_H

bool isValidID(const char *id);
bool isValidName(const char *name);

bool stringCompare(const char *str1, const char *str2);
void customStrcat(char *destination, const char *source);
void customStrcpy(char *destination, const char *source);
int customStrlen(const char *str);

bool compareSubjectCodes(const char *code1, const char *code2);
void parseSubjectLine(const char *line, char *subjectCode,
                      char *subjectName, int &credits,
                      int &theoreticalHours, int &practicalHours);

#endif // UTILS_H
