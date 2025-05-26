#ifndef _TIME_H_
#define _TIME_H_

class Time
{
    int hours;
    int minutes;
    int seconds;

public:
    void Set(int h, int m, int s = 0);
    void Print() const;
    void Read();
};

#endif
