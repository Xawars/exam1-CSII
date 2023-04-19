#ifndef SUBJECTSPROCESS_H
#define SUBJECTSPROCESS_H

void displaySubjects(char *name);
void displaySubjectOptions();
void enrollSubjects();
bool getSubjectDetails(const char *code, char *subjectDetails,
                       int &subjectCredits);
void enrollSubjects(const char *id);
bool isSubjectEnrolled(const char *code, const char *enrolledSubjects);


#endif // SUBJECTSPROCESS_H
