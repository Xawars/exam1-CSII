import qbs

CppApplication {
    consoleApplication: true
    install: true
    files: [
        "ProcessFile.cpp",
        "ProcessFile.h",
        "StudentsProcess.cpp",
        "StudentsProcess.h",
        "Utils.cpp",
        "Utils.h",
        "main.cpp",
    ]
}
