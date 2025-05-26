#include "Message.h"
#include "Time.h"

#include <iostream>

void Time::Set(int h, int m, int s) {
    hours = h;
    minutes = m;
    seconds = s;

    if ((unsigned)h > 23 | (unsigned)m > 59 | (unsigned)s > 59) {
        hours = -1;
        Error("Íåêîððåêòíîå âðåìÿ: ÷àñû [0-23], ìèíóòû [0-59], ñåêóíäû [0-59]\n");
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
        Message("Ââåäèòå âðåìÿ (÷àñ, ìèíóòû [ñåêóíäû]): ");
        std::cin >> h >> m;
        if (std::cin.peek() != '\n') {
            std::cin >> s;
        }
        
        // Î÷èñòêà áóôåðà ââîäà àëüòåðíàòèâíûì ñïîñîáîì
        while (std::cin.get() != '\n') continue;
        
        Set(h, m, s);
        valid = (hours != -1);
        
        if (!valid) {
            Message("\n");
        }
    }
}
