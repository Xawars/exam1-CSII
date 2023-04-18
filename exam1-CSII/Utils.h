#ifndef UTILS_H
#define UTILS_H
#include <fstream>
#include <iostream>

using namespace std;

bool isValidID(const char *id);
bool isValidName(const char *name);

void saveStudentData(const char *id, const char *name);
void displayStudents();
void showMenu1();
void showMenu2();

int customStrlen(const char *str);
int customStrncmp(const char *s1, const char *s2, long n);

#endif // UTILS_H
