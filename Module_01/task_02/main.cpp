#include "Message.h"
#include "Date.h"
#include "Time.h"

#include <iostream>

class Date;
class Time;

int main(int argc, char** argv) {
    system("chcp 1251 > nul");
    Message("������������ ������ �� ����� ���������������� �� C++. ������ 1.2. \n\n");

    // ������������ ��������� Date
    Message("\n=== ������������ ��� ===\n");
    Date date1, date2;
    
    Message("������ ���� -> ");
    date1.Read();
    Message("������ ���� -> ");
    date2.Read();

    Message("\n����������:\n");
    Message("���� 1: ");
    date1.Print();
    Message("���� 2: ");
    date2.Print();
	
	Message("\n��������� ���:\n");
        
    Message(
	date1.Equal(date2) ? "���� �����.\n"  :
	date1.Less(date2)  ? "���� 1 ������ ���� 2.\n" :
       					 "���� 1 ������ ���� 2.\n");

    // ������������ ��������� Time
    Message("\n=== ������������ ������� ===\n");
    Time time1, time2;
    
    Message("������ ����� -> ");
    time1.Read();
    Message("������ ����� -> ");
    time2.Read();

    Message("\n����������:\n");
    Message("����� 1: ");
    time1.Print();
    Message("����� 2: ");
    time2.Print();

	Message("\n��������� �������:\n");

    Message(
    time1.Equal(time2) ? "������� �����.\n" :
    time1.Less(time2)  ? "����� 1 ������ ������� 2.\n" :
                         "����� 1 ������ ������� 2.\n");

    return 0;
}
