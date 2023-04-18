import qbs

CppApplication {
    consoleApplication: true
    install: true
    files: [
        "ProcessFile.cpp",
        "ProcessFile.h",
        "Utils.cpp",
        "Utils.h",
        "main.cpp",
    ]
}
