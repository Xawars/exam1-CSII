#ifndef HOURSPERWEEKCOURSES_H
#define HOURSPERWEEKCOURSES_H

void schedule_courses(int student_id);
bool is_time_slot_available(const char *time_slot,
                            const char **assigned_schedule,
                            int assigned_schedule_size);

#endif // HOURSPERWEEKCOURSES_H
