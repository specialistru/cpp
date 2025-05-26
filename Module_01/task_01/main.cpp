#include <iostream>
#include "Message.h"
#include "Date.h"
#include "Time.h"

class Date;
class Time;

int main(int argc, char** argv)
{
	system("chcp 1251 > nul");
    Message("Лабораторная работа по курсу программирования на C++. Задача 1.1. \n\n");

    Date date;
    Time time;
	
    // Чтение и вывод даты
    date.Read();
    Message("Введенная дата: ");
 
    // Чтение и вывод времени
    time.Read();
    Message("Введенное время: ");
    
	date.Print();
    time.Print();

    return 0;
}
