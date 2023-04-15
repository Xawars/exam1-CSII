import qbs

CppApplication {
    consoleApplication: true
    install: true
    files: [
        "CoursesInformation.cpp",
        "CoursesInformation.h",
        "GeneratingStudySessions.cpp",
        "GeneratingStudySessions.h",
        "HoursPerWeekCourses.cpp",
        "HoursPerWeekCourses.h",
        "ProcessFile.cpp",
        "ProcessFile.h",
        "Utils.cpp",
        "Utils.h",
        "main.cpp",
    ]
}
