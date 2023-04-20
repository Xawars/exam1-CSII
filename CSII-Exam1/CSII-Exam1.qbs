import qbs

CppApplication {
    consoleApplication: true
    install: true
    files: [
        "HTIProcess.cpp",
        "HTIProcess.h",
        "ProcessFile.cpp",
        "ProcessFile.h",
        "StudentsProcess.cpp",
        "StudentsProcess.h",
        "SubjectsProcess.cpp",
        "SubjectsProcess.h",
        "Utils.cpp",
        "Utils.h",
        "main.cpp",
    ]
}
