#include "Message.h"
#include "Date.h"

#include <iostream>

void Date::Set(int d, int m, int y) {
    static constexpr int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if ((unsigned)(y) < 1 || (unsigned)(m - 1) >= 12 || (unsigned)(d - 1) >= 31) {
        Error("������������ ����: ��� > 0, ����� 1-12, ���� 1-31.\n");
        return;
    }

    if (m == 2) {
        bool isLeap = (y % 4 == 0) && (y % 100 != 0 || y % 400 == 0);
        int maxDays = isLeap ? 29 : 28;
        if (d > maxDays) {
            Error(isLeap ? "������� � ���������� ��� ����� 29 ����.\n" : "������� ����� 28 ����.\n");
            return;
        }
    }
    else if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) {
        Error("� ���� ������ ������ 30 ����.\n");
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
    bool valid = false;
    
    while (!valid) {
        Message("������� ���� (���� ����� ���): ");
        std::cin >> d >> m >> y;
        while (std::cin.get() != '\n') continue;
        int old_day = day, old_month = month, old_year = year;
        Set(d, m, y);
        valid = (day != old_day || month != old_month || year != old_year);
        
        if (!valid) {
            Message("\n");
        }
    }
}

// ��������� ���
bool Date::Equal(const Date& other) const {
    return day == other.day && month == other.month && year == other.year;
}

bool Date::Less(const Date& other) const {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day < other.day;
}

bool Date::Greater(const Date& other) const {
    if (year != other.year) return year > other.year;
    if (month != other.month) return month > other.month;
    return day > other.day;
}
