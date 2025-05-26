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
    int h, m, s = 0;
    bool valid = false;
    
    while (!valid) {
        Message("Введите время (час, минуты [секунды]): ");
        std::cin >> h >> m;
        if (std::cin.peek() != '\n') {
            std::cin >> s;
        }
        while (std::cin.get() != '\n') continue;
        Set(h, m, s);
        valid = (hours != -1);
        
        if (!valid) {
            Message("\n");
        }
    }
}

// Сравнение времени
bool Time::Equal(const Time& other) const {
    return hours == other.hours && minutes == other.minutes && seconds == other.seconds;
}

bool Time::Less(const Time& other) const {
    if (hours != other.hours) return hours < other.hours;
    if (minutes != other.minutes) return minutes < other.minutes;
    return seconds < other.seconds;
}

bool Time::Greater(const Time& other) const {
    if (hours != other.hours) return hours > other.hours;
    if (minutes != other.minutes) return minutes > other.minutes;
    return seconds > other.seconds;
}
