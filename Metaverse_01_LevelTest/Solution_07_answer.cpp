#include <iostream>

using namespace std;

int main() {
	
	//1. 빙고 게임 판을 생성해야함
	//2차원 배열로 데이터를 받는다.
	int board[5][5] = { 0 };
	int isUsed[26] = { false }; //추가적인 공간을 부여 해서 시간 복잡도를 낮추는 방법

	srand(time(NULL));

	//1-1. 랜덤하게 수를 배치해야함
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int random = 0;
			do
			{
				int random = rand() % 25 + 1;
			} while (isUsed[random]);

			board[i][j] = random;
			isUsed[random] = true;
		}
	}


	int bingoCount = 0;
	while (true)
	{
		
		//현황 출력
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (board[i][j] == 0) {
					cout << "     ";
				}
				else {
					cout << board[i][j] << "    ";
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
		if (input <= 0 || input > 25)
		{
			//3-1. 오입력을 했다면? 1번 부터 다시 한다.

		}

		//4. 숫자를 지워준다.
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (board[i][j] == input) {
					board[i][j] = 0;
				}
			}
		}

		//5. 빙고 개숫를 센다.
		int count_line_w[5] = { 5, 5 ,5, 5, 5 }; //가로줄 카운트
		int count_line_h[5] = { 5, 5 ,5, 5, 5 }; //세로줄 카운트
		int count_line_s1 = 5; //대각선 카운트
		int count_line_s2 = 5; //대각선 카운트
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
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
				if ((4 - i) == j && board[j][i] == 0)
				{
					count_line_s2 -= 1;
				}
			}
		}




		//6. 1번 부터 반복한다.

	}
	



	return 0;
}