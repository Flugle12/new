// example.cpp
#include <iostream>

extern "C" {
    void hello() {
        std::cout << "Hello from dynamic library!" << std::endl;
    }
}
