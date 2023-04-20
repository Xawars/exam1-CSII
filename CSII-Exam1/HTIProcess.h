#ifndef HTIPROCESS_H
#define HTIPROCESS_H

int calculateHTI(int credits, int theoreticalHours, int practicalHours);
void generateHTI(const char *id, const char *enrolledSubjects);
void getSubjectInfo(const char *line, int &credits, int &theoreticalHours,
                    int &practicalHours);
void extractHours(const char *schedule, int &startHour, int &endHour);

#endif // HTIPROCESS_H
