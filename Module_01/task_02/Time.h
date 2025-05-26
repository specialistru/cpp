#ifndef _TIME_H_
#define _TIME_H_

class Time {
    int hours;
    int minutes;
    int seconds;

public:
    void Set(int h, int m, int s = 0);
    void Print() const;
    void Read();

    // Функции сравнения
    bool Equal(const Time& other) const;
    bool Less(const Time& other) const;
    bool Greater(const Time& other) const;
};

#endif
