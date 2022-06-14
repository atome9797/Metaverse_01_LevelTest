#include <iostream>

using namespace std;

#define BLANK 0

int main()
{

	//1. 빙고판을 초기화
	srand(time(NULL));
	bool isUsed[26] = { false };
	int board[5][5] = { 0 };
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int n = 0;

			do
			{
				n = rand() % 25 + 1;
				
			} while (isUsed[n] == true);

			board[i][j] = n;
			isUsed[n] = true;
		}

	}

	int bingoCount = 0;
	while (1) {
		system("cls");

		//2. 빙고 현황출력
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{

				if (board[i][j] == BLANK)
				{
					cout << "\t";
				}
				else {
					cout << board[i][j] << "\t";
				}

			}
			cout << endl;

		}

		cout << "현제 " << bingoCount << "줄의 빙고가 완성되었습니다." << endl;

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


		//4. 빙고판을 최신화 => 숫자를 지워 준다.
		for (int i = 0; i < 5; i++)
		{
			bool isExit = false;
			for (int j = 0; j < 5; j++)
			{
				if (board[i][j] == input)
				{
					board[i][j] = BLANK;
					isExit = true;
					break;
				}
			}

			if (isExit)
			{
				break;
			}
		}

		//5. 빙고 개수를 센다.
		// -  가로의 모든 숫자를 지운것
		int count = 0;
		for (int i = 0; i < 5; i++)
		{
			bool isBingo = true;
			for (int j = 0; j < 5; j++)
			{
				if (board[i][j] != BLANK)
				{
					isBingo = false;
					break;
				}
			}

			//0이 아닌게 있으면 false가 되기 때문에 true인 상태는 전부 0인상태임 => 빙고 이므로 count 해줌
			if (isBingo)
			{
				++count;
			}
		}

		// -  세로의 모든 숫자를 지운것
		for (int i = 0; i < 5; i++)
		{
			bool isBingo = true;
			for (int j = 0; j < 5; j++)
			{
				if (board[j][i] != BLANK)
				{
					isBingo = false;
					break;
				}
			}

			//0이 아닌게 있으면 false가 되기 때문에 true인 상태는 전부 0인상태임 => 빙고 이므로 count 해줌
			if (isBingo)
			{
				++count;
			}
		}

		// -  대각선의 모든 숫자를 지운것

		{
			bool isBingo = true;
			for (int i = 0; i < 5; i++)
			{
				if (board[i][i] != BLANK)
				{
					isBingo = false;
					break;
				}
			}

			//0이 아닌게 있으면 false가 되기 때문에 true인 상태는 전부 0인상태임 => 빙고 이므로 count 해줌
			if (isBingo)
			{
				++count;
			}
		}

		{
			bool isBingo = true;
			for (int i = 0; i < 5; i++)
			{
				if (board[i][4 - i] != BLANK)
				{
					isBingo = false;
					break;
				}
			}

			//0이 아닌게 있으면 false가 되기 때문에 true인 상태는 전부 0인상태임 => 빙고 이므로 count 해줌
			if (isBingo)
			{
				++count;
			}
		}

		bingoCount = count;


		//6. 2번 부터 다시 반복 한다.
	}

	return 0;
}