#include <iostream>


int main(int argc, char* argv[]) {
    std::cout << "Command-line arguments count: " << argc << std::endl;
    for (int i = 0; i < argc; ++i) {
        std::cout << "Argument " << i << ": " << argv[i] << std::endl;
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}