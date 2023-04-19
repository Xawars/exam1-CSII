#ifndef SUBJECTSPROCESS_H
#define SUBJECTSPROCESS_H

void displaySubjects(char *name);
void displaySubjectOptions();
void enrollSubjects();
bool getSubjectDetails(const char *code, char *subjectDetails,
                       int &subjectCredits);
void enrollSubjects(const char *id);

#endif // SUBJECTSPROCESS_H
