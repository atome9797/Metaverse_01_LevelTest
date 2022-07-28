#include <iostream>
#include <conio.h> 
#include "Init.h"

using namespace std;

int main()
{


    bool start = true;

    while (1)
    {
        cout << "게임을 시작 하시겠습니까?" << endl;

        if (start == true)
        {
            cout << "▷YES\t\tNO";
        }
        else
        {
            cout << "YES\t\t▷NO";
        }

        int key = _getch();


        if (key == 13)
        {
            break;
        }
        switch (key)
        {
        case 77: start = false;  break;
        case 75: start = true;   break;
        }

        system("cls");

    }

    if (start)
    {
        system("cls");
        Init();
    }

}

