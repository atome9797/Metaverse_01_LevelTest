#pragma once
#include <iostream>

using namespace std;


#include <stdlib.h>

class Bingo
{
	static const int BOARD_SIZE = 10;
	static const int BLANK = 0;
public:
	Bingo() = default;
	Bingo(const Bingo& other) = delete;
	Bingo& operator=(const Bingo& other) = delete;

	//빙고 초기화
	void Init()
	{
		bool isUsed[BOARD_SIZE* BOARD_SIZE+1] = { false };
		//1. 빙고판을 초기화
		srand(time(NULL));
		for (int i = 0; i < BOARD_SIZE; i++)
		{
			for (int j = 0; j < BOARD_SIZE; j++)
			{
				int n = 0;

				do
				{
					n = rand() % (BOARD_SIZE* BOARD_SIZE) + 1;

				} while (isUsed[n] == true);

				board[i][j] = n;
				isUsed[n] = true;
			}

		}
	}

	/// <summary>
	/// 빙고를 출력해준다.
	/// </summary>
	void Print() const
	{
		for (int i = 0; i < BOARD_SIZE; i++)
		{
			for (int j = 0; j < BOARD_SIZE; j++)
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


	}

	/// <summary>
	/// 빙고를 업데이트 한다.
	/// </summary>
	/// <param name="input">입력 데이터</param>
	void Update(int input)
	{
		//4. 빙고판을 최신화 => 숫자를 지워 준다.
		for (int i = 0; i < BOARD_SIZE; i++)
		{
			bool isExit = false;
			for (int j = 0; j < BOARD_SIZE; j++)
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

		
		//5.빙고 개수를 센다.
		int count = CountHorizontalBingo();
		count += CountVerticalBingo();
		count += CountDiagonalBingo();
		

		bingoCount = count;
	}

	/// <summary>
	/// 빙고가 끝났는지 판별한다.
	/// </summary>
	/// <returns>끝났다면 true, 아니면 false</returns>
	bool IsCompleted() const
	{
		//빙고 총갯수와 같으면
		if (bingoCount == BOARD_SIZE * 2 + 2)
		{
			return true;
		}

		return false;
	}

private:
	/// <summary>
	/// 가로줄의 빙고를 센다.
	/// </summary>
	/// <returns></returns>
	int CountHorizontalBingo() const
	{
		//5. 빙고 개수를 센다.
		// -  가로의 모든 숫자를 지운것
		int count = 0;
		for (int i = 0; i < BOARD_SIZE; i++)
		{
			bool isBingo = true;
			for (int j = 0; j < BOARD_SIZE; j++)
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

		return count;
	}

	/// <summary>
	/// 세로줄의 빙고를 센다.
	/// </summary>
	/// <returns></returns>
	int CountVerticalBingo() const
	{
		int count = 0;

		// -  세로의 모든 숫자를 지운것
		for (int i = 0; i < BOARD_SIZE; i++)
		{
			bool isBingo = true;
			for (int j = 0; j < BOARD_SIZE; j++)
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

		return count;
	}

	/// <summary>
	/// 대각선의 빙고를 센다.
	/// </summary>
	/// <returns></returns>
	int CountDiagonalBingo() const
	{
		// -  대각선의 모든 숫자를 지운것
		int count = 0;
		{
			bool isBingo = true;
			for (int i = 0; i < BOARD_SIZE; i++)
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
			for (int i = 0; i < BOARD_SIZE; i++)
			{
				if (board[i][BOARD_SIZE - 1 - i] != BLANK)
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

		return count;
	}

private:
	int board[BOARD_SIZE][BOARD_SIZE] = { 0 };
	int bingoCount = 0;
};
