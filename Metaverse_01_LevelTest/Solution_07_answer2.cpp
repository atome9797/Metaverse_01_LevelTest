#include <iostream>
#include "Solution_07_answer.h"

int main()
{

	Bingo bingo;
	bingo.Init();
	while (false == bingo.IsCompleted()) {

		system("cls");

		bingo.Print();


		//3.사용자로 부터 입력 받음
		cout << "숫자를 입력해주세요. : ";
		int input;
		cin >> input;

		//3-1. 오입력이 들어왓다면 
		if (input < 0 || input > 25)
		{
			//2번부터 다시 시작한다.
			continue;
		}

		bingo.Update(input);


		//6. 2번 부터 다시 반복 한다.
	}

	return 0;
}