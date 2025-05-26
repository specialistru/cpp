#include "Message.h"
#include "Date.h"
#include "Time.h"

#include <iostream>

class Date;
class Time;

int main(int argc, char** argv)
{
    system("chcp 1251 > nul");
    Message("Лабораторная работа по курсу программирования на C++. Задача 1.1. \n\n");

    Date d;
    Time t;
	
    // Чтение и вывод даты
    d.Read();
    Message("Введенная дата: ");
 
    // Чтение и вывод времени
    t.Read();
    Message("Введенное время: ");
    
    d.Print();
    t.Print();

    return 0;
}
