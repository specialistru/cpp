#include "Message.h"
#include "Date.h"
#include "Time.h"

#include <iostream>

class Date;
class Time;

int main(int argc, char** argv)
{
    system("chcp 1251 > nul");
    Message("������������ ������ �� ����� ���������������� �� C++. ������ 1.1. \n\n");

    Date d;
    Time t;
	
    // ������ � ����� ����
    d.Read();
    Message("��������� ����: ");
 
    // ������ � ����� �������
    t.Read();
    Message("��������� �����: ");
    
    d.Print();
    t.Print();

    return 0;
}
