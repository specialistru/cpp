#include "Message.h"
#include "Date.h"
#include "Time.h"

#include <iostream>

class Date;
class Time;

int main(int argc, char** argv) {
    system("chcp 1251 > nul");
    Message("Лабораторная работа по курсу программирования на C++. Задача 1.2. \n\n");

    // Тестирование структуры Date
    Message("\n=== Тестирование дат ===\n");
    Date date1, date2;
    
    Message("Первая дата -> ");
    date1.Read();
    Message("Вторая дата -> ");
    date2.Read();

    Message("\nРезультаты:\n");
    Message("Дата 1: ");
    date1.Print();
    Message("Дата 2: ");
    date2.Print();
	
	Message("\nСравнение дат:\n");
        
    Message(
	date1.Equal(date2) ? "Даты равны.\n"  :
	date1.Less(date2)  ? "Дата 1 меньше Даты 2.\n" :
       					 "Дата 1 больше Даты 2.\n");

    // Тестирование структуры Time
    Message("\n=== Тестирование времени ===\n");
    Time time1, time2;
    
    Message("Первое время -> ");
    time1.Read();
    Message("Второе время -> ");
    time2.Read();

    Message("\nРезультаты:\n");
    Message("Время 1: ");
    time1.Print();
    Message("Время 2: ");
    time2.Print();

	Message("\nСравнение времени:\n");

    Message(
    time1.Equal(time2) ? "Времена равны.\n" :
    time1.Less(time2)  ? "Время 1 меньше Времени 2.\n" :
                         "Время 1 больше Времени 2.\n");

    return 0;
}
