#include "Message.h"
#include "Date.h"

#include <iostream>

void Date::Set(int d, int m, int y) {
    static constexpr int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if ((unsigned)(y) < 1 || (unsigned)(m - 1) >= 12 || (unsigned)(d - 1) >= 31) {
        Error("Íåêîððåêòíàÿ äàòà: ãîä > 0, ìåñÿö 1-12, äåíü 1-31.\n");
        return;
    }

    if (m == 2) {
        bool isLeap = (y % 4 == 0) && (y % 100 != 0 || y % 400 == 0);
        int maxDays = isLeap ? 29 : 28;
        if (d > maxDays) {
            Error(isLeap ? "Ôåâðàëü â âèñîêîñíûé ãîä èìååò 29 äíåé.\n" : "Ôåâðàëü èìååò 28 äíåé.\n");
            return;
        }
    }
    else if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) {
        Error("Â ýòîì ìåñÿöå òîëüêî 30 äíåé.\n");
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
        Message("Ââåäèòå äàòó (äåíü ìåñÿö ãîä): ");
        std::cin >> d >> m >> y;
        
        // Î÷èñòêà áóôåðà ââîäà àëüòåðíàòèâíûì ñïîñîáîì
        while (std::cin.get() != '\n') continue;
        
        int old_day = day, old_month = month, old_year = year;
        Set(d, m, y);
        valid = (day != old_day || month != old_month || year != old_year);
        
        if (!valid) {
            Message("\n");
        }
    }
}
