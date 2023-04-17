#ifndef UTILS_H
#define UTILS_H
#include <fstream>
#include <iostream>

using namespace std;

void parse_line(const char *line, long long &id, char *name);
void int_to_str(int number, char *str, int buffer_size);
void calculate_sizes(ifstream &file, int &num_elements, int &max_line_length,
                     int &max_name_length);

#endif // UTILS_H
