#include "HoursPerWeekCourses.h"
#include <iostream>
#include <fstream>
#include "Utils.h"

using namespace std;

bool is_time_slot_available(const char *time_slot,
                            const char **assigned_schedule,
                            int assigned_schedule_size) {

    for (int i = 0; i < assigned_schedule_size; i++) {
        if (custom_strcmp(time_slot, assigned_schedule[i]) == 0) {
            return false;
        }
    }
    return true;
}

