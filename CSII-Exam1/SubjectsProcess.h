#ifndef SUBJECTSPROCESS_H
#define SUBJECTSPROCESS_H

void displaySubjects(char *name);
void displaySubjectOptions();

bool getSubjectDetails(const char *code, char *subjectDetails,
                       int &subjectCredits);
char  *enrollSubjects(const char *id);
bool isSubjectEnrolled(const char *code, const char *enrolledSubjects);

#endif // SUBJECTSPROCESS_H
