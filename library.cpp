// main.cpp
#include <iostream>
#include <dlfcn.h>

typedef void (*HelloFunction)();

int main() {
    void* handle = dlopen("./-llibrary.so", RTLD_LAZY);
    if (!handle) {
        std::cerr << "Cannot open library: " << dlerror() << std::endl;
        return 1;
    }

    // Загрузка функции из библиотеки
    HelloFunction hello = (HelloFunction) dlsym(handle, "hello");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Cannot load symbol 'hello': " << dlsym_error << std::endl;
        dlclose(handle);
        return 1;
    }

    // Вызов функции из библиотеки
    hello();

    // Закрытие библиотеки
    dlclose(handle);

    return 0;
}

