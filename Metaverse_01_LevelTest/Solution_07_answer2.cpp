#include <iostream>
#include "Solution_07_answer.h"

int main()
{

	Bingo bingo;
	bingo.Init();
	while (false == bingo.IsCompleted()) {

		system("cls");

		bingo.Print();


		//3.����ڷ� ���� �Է� ����
		cout << "���ڸ� �Է����ּ���. : ";
		int input;
		cin >> input;

		//3-1. ���Է��� ���Ӵٸ� 
		if (input < 0 || input > 25)
		{
			//2������ �ٽ� �����Ѵ�.
			continue;
		}

		bingo.Update(input);


		//6. 2�� ���� �ٽ� �ݺ� �Ѵ�.
	}

	return 0;
}