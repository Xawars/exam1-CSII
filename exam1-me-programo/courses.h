#ifndef COURSES_H
#define COURSES_H

const int maxAmountCourses = 10;
const int maxLenght = 50;

int readCourses(const char* file, char**& codes, char**& subjects, int*& credits,
                int*& theoreticalHours, int*& practiceHours,
                int*& independentHours);
void processCourse();

#endif // COURSES_H
