#include "HTIProcess.h"
#include <fstream>
#include <iostream>

using namespace std;

int calculateHTI(int credits, int theoreticalHours, int practicalHours) {
    if (credits == 1 && practicalHours == 2) {
        int independentStudyHours = 1;
        return independentStudyHours;
    } else if (credits == 1 && practicalHours == 0) {
        int independentStudyHours = 0;
        return independentStudyHours;
    } else {
        int totalHoursPerSemester = 48 * credits;
        int hoursPerWeek = totalHoursPerSemester / 16;
        int independentStudyHours = hoursPerWeek - (theoreticalHours + practicalHours);
        return independentStudyHours;
    }
}
