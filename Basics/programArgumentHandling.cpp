#include <iostream>

/*
    argc - count of command line args
    argv - command line args as c strings
    env - system environment variables
*/
int main(int argc, char* argv[], char* env[]) {

    std::cout << "argc: " << argc << std::endl;

    // print args
    for (int i = 0; i < argc; i++) {
        std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
    }

    // print envs

    // Way1 - Loop through all envs
    int j = 0;
    for (;;) {
        std::cout << "env[" << j << "]: ";
        std::cout << env[j++] << std::endl;
        if (env[j] == nullptr) {
            break;
        }
    }

    // Way2 - use getenv
    std::cout << "PATH: " << std::getenv("PATH") << std::endl;

    return 0;
}