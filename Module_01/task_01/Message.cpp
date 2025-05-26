#include "Message.h"

#include <iostream>

void Error(const char* msg) {
    std::cout << "Ошибка: " << msg;
}

void Message(const char* msg) {
    std::cout << msg;
}
