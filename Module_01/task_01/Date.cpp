#include "Message.h"
#include "Date.h"

#include <iostream>

void Date::Set(int d, int m, int y) {
    static constexpr int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if ((unsigned)(y) < 1 || (unsigned)(m - 1) >= 12 || (unsigned)(d - 1) >= 31) {
        Error("Некорректная дата: год > 0, месяц 1-12, день 1-31.\n");
        return;
    }

    if (m == 2) {
        bool isLeap = (y % 4 == 0) && (y % 100 != 0 || y % 400 == 0);
        int maxDays = isLeap ? 29 : 28;
        if (d > maxDays) {
            Error(isLeap ? "Февраль в високосный год имеет 29 дней.\n" : "Февраль имеет 28 дней.\n");
            return;
        }
    }

    else if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) {
        Error("В этом месяце только 30 дней.\n");
        return;
    }

    day = d;
    month = m;
    year = y;
}

void Date::Print() const {
    std::cout << (day < 10 ? "0" : "") << day << "/"
              << (month < 10 ? "0" : "") << month << "/"
              << year << "\n";
}

void Date::Read() {
    int d, m, y;
    Message("Введите дату (день месяц год): ");
    std::cin >> d >> m >> y;
    Set(d, m, y);
}
