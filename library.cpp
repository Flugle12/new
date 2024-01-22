// library.cpp
#include <iostream>

extern "C" {
    void hello() {
        std::cout << "Hello from the dynamic library!" << std::endl;
    }
}
