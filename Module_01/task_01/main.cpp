#include "Message.h"
#include "Date.h"
#include "Time.h"

#include <iostream>

class Date;
class Time;

int main(int argc, char** argv)
{
    system("chcp 1251 > nul");
    Message("Ëàáîðàòîðíàÿ ðàáîòà ïî êóðñó ïðîãðàììèðîâàíèÿ íà C++. Çàäà÷à 1.1. \n\n");

    Date date;
    Time time;
	
    // ×òåíèå è âûâîä äàòû
    date.Read();
    Message("Ââåäåííàÿ äàòà: ");
 
    // ×òåíèå è âûâîä âðåìåíè
    time.Read();
    Message("Ââåäåííîå âðåìÿ: ");
    
    date.Print();
    time.Print();

    return 0;
}
