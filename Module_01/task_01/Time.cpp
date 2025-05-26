#include "Message.h"
#include "Time.h"

#include <iostream>

void Time::Set(int h, int m, int s) {
    hours = h;
    minutes = m;
    seconds = s;

    if ((unsigned)h > 23 | (unsigned)m > 59 | (unsigned)s > 59) {
        hours = -1;
        Error("Некорректное время: часы [0-23], минуты [0-59], секунды [0-59]\n");
    }
}

void Time::Print() const {
    std::cout << (hours < 10 ? "0" : "") << hours << ":"
              << (minutes < 10 ? "0" : "") << minutes << ":"
              << (seconds < 10 ? "0" : "") << seconds << "\n";
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
