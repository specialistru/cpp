#include "Message.h"
#include <iostream>

void Error(const char* msg) {
    std::cout << "������: " << msg << "\n";    
}

void Message(const char* msg) {
    std::cout << msg << "\n";    
}
