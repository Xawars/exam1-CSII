#ifndef COURSESINFORMATION_H
#define COURSESINFORMATION_H

int calculate_hti(int credits, int theory_hours, int practice_hours);
void parse_subject_line(const char *line, long long &code,
                        char *subject_name, int &credits,
                        int &theory_hours, int &practice_hours);
void display_courses(int intput_id);

#endif // COURSESINFORMATION_H
