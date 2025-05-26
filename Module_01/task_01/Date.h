#ifndef _DATE_H_
#define _DATE_H_

class Date
{
    int day;
    int month;
    int year;

public:
    void Set(int d, int m, int y);    
    void Print() const;
    void Read();
};

#endif
