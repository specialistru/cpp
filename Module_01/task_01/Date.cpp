#include "iostream"
#include "Message.h"
#include "Date.h"

void Date::Set(int d, int m, int y) {
    if (y < 1) {
        Error("√од должен быть положительным.\n");
        return;
    }
    if (m < 1 || m > 12) {
        Error("ћес€ц должен быть от 1 до 12.\n");
        return;
    }
    if (d < 1 || d > 31) {
        Error("ƒень должен быть от 1 до 31.\n");
        return;
    }

    if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) {
        Error("¬ этом мес€це только 30 дней.\n");
        return;
    }

    if (m == 2) {
        bool leap = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
        if (leap && d > 29) {
            Error("‘евраль в високосный год имеет 29 дней.\n");
            return;
        } else if (!leap && d > 28) {
            Error("‘евраль имеет 28 дней.\n");
            return;
        }
    }

    day = d;
    month = m;
    year = y;
}

void Date::Print() const {
    if (day < 10) std::cout << '0';
    std::cout << day << '/';

    if (month < 10) std::cout << '0';
    std::cout << month << '/';

    std::cout << year << "\n";
}

void Date::Read() {
    int d, m, y;
    Message("¬ведите дату (день мес€ц год): ");
    std::cin >> d >> m >> y;
    Set(d, m, y);
}
