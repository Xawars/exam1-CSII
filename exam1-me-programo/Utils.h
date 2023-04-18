#ifndef UTILS_H
#define UTILS_H
#include <fstream>
#include <iostream>

using namespace std;

void parse_line(const char *line, long long &id, char *name);
void int_to_str(int number, char *str, int buffer_size);
void calculate_sizes(ifstream &file, int &num_elements, int &max_line_length,
                     int &max_name_length);
int custom_strlen(const char *str);
void custom_strcpy(char *destination, const char *source);
int custom_strcmp(const char *str1, const char *str2);
void custom_strcat(char *destination, const char *source);
int custom_sizeof_array(const char *arr);

#endif // UTILS_H
