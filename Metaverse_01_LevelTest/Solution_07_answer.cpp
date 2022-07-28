#include <iostream>

#define size 10
using namespace std;

int main() {
	
	//1. 빙고 게임 판을 생성해야함
	//2차원 배열로 데이터를 받는다.
	int board[size][size] = { 0 };
	int isUsed[size* size + 1] = { false }; //추가적인 공간을 부여 해서 시간 복잡도를 낮추는 방법

	srand(time(NULL));

	//1-1. 랜덤하게 수를 배치해야함
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			int random = 0;
			do
			{
				random = rand() % (size* size) + 1;
			} while (isUsed[random]);

			board[i][j] = random;
			isUsed[random] = true;
		}
	}


	int bingoCount = 0;
	while (true)
	{
		
		//현황 출력
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (board[i][j] == 0) {
					cout << "\t";
				}
				else {
					cout << board[i][j] << "\t";
				}
			}
			cout << endl;
		}


		cout << "현재 " << bingoCount << "줄의 빙고가 완성되었습니다." << endl;
		
		//2. 사용자로부터 입력을 받는다.
		cout << "숫자를 입력해 주세요 : ";
		int input;
		cin >> input;

		//3. 사용자의 입력이 유효한지 판단한다.
		if (input <= 0 || input > (size* size))
		{
			system("cls");
			//3-1. 오입력을 했다면? 1번 부터 다시 한다.
			continue;
		}

		//4. 숫자를 지워준다.
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (board[i][j] == input) {
					board[i][j] = 0;
				}
			}
		}


		//5. 빙고 개숫를 센다.
		int count_line_w[size] = {0}; //가로줄 카운트
		int count_line_h[size] = {0};//세로줄 카운트
		fill_n(count_line_h, size, size);
		fill_n(count_line_w, size, size);

		int count_line_s1 = size; //대각선 카운트
		int count_line_s2 = size;//대각선 카운트

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (board[i][j] == 0)
				{
					count_line_w[i] -= 1;
				}
				if (board[j][i] == 0)
				{
					count_line_h[i] -= 1;
				}
				if (i == j && board[j][i] == 0)
				{
					count_line_s1 -= 1;
				}
				if ((size - 1 - i) == j && board[j][i] == 0)
				{
					count_line_s2 -= 1;
				}
			}
		}

		int resultCount = 0;
		for (int i = 0; i < size; i++)
		{
			if (count_line_w[i] == 0) {
				resultCount += 1;
			}

			if (count_line_h[i] == 0)
			{
				resultCount += 1;
			}
		}

		if (count_line_s2 == 0)
		{
			resultCount += 1;
		}

		if (count_line_s1 == 0)
		{
			resultCount += 1;
		}


		bingoCount = resultCount;

		//6. 1번 부터 반복한다.

		system("cls");
	}
	



	return 0;
}