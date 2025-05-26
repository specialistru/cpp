#include "Message.h"
#include "Time.h"

#include <iostream>

void Time::Set(int h, int m, int s) {
    if (h < 0 || h > 23) {
        Error("часы должны быть от 0 до 23");
        return;
    }
    if (m < 0 || m > 59) {
        Error("минуты должны быть от 0 до 59");
        return;
    }
    if (s < 0 || s > 59) {
        Error("секунды должны быть от 0 до 59");
        return;
    }

    hours = h;
    minutes = m;
    seconds = s;
}

void Time::Print() const {
    if (hours < 10) std::cout << '0';
    std::cout << hours << ':';

    if (minutes < 10) std::cout << '0';
    std::cout << minutes << ':';

    if (seconds < 10) std::cout << '0';
    std::cout << seconds << "\n";
}


void Time::Read() {
    int h, m, s;
    Message("Введите время (час, минуты [секунды]): ");
    std::cin >> h >> m;
    // Чтение секунд, если они указаны
    if (std::cin.peek() != '\n') {
        std::cin >> s;
        Set(h, m, s);
    } else {
        Set(h, m); // Установка времени без секунд
    }
}
