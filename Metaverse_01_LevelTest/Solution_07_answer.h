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

	//���� �ʱ�ȭ
	void Init()
	{
		bool isUsed[BOARD_SIZE* BOARD_SIZE+1] = { false };
		//1. �������� �ʱ�ȭ
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
	/// ���� ������ش�.
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
		cout << "���� " << bingoCount << "���� ���� �ϼ��Ǿ����ϴ�." << endl;


	}

	/// <summary>
	/// ���� ������Ʈ �Ѵ�.
	/// </summary>
	/// <param name="input">�Է� ������</param>
	void Update(int input)
	{
		//4. �������� �ֽ�ȭ => ���ڸ� ���� �ش�.
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

		
		//5.���� ������ ����.
		int count = CountHorizontalBingo();
		count += CountVerticalBingo();
		count += CountDiagonalBingo();
		

		bingoCount = count;
	}

	/// <summary>
	/// ���� �������� �Ǻ��Ѵ�.
	/// </summary>
	/// <returns>�����ٸ� true, �ƴϸ� false</returns>
	bool IsCompleted() const
	{
		//���� �Ѱ����� ������
		if (bingoCount == BOARD_SIZE * 2 + 2)
		{
			return true;
		}

		return false;
	}

private:
	/// <summary>
	/// �������� ���� ����.
	/// </summary>
	/// <returns></returns>
	int CountHorizontalBingo() const
	{
		//5. ���� ������ ����.
		// -  ������ ��� ���ڸ� �����
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

			//0�� �ƴѰ� ������ false�� �Ǳ� ������ true�� ���´� ���� 0�λ����� => ���� �̹Ƿ� count ����
			if (isBingo)
			{
				++count;
			}
		}

		return count;
	}

	/// <summary>
	/// �������� ���� ����.
	/// </summary>
	/// <returns></returns>
	int CountVerticalBingo() const
	{
		int count = 0;

		// -  ������ ��� ���ڸ� �����
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

			//0�� �ƴѰ� ������ false�� �Ǳ� ������ true�� ���´� ���� 0�λ����� => ���� �̹Ƿ� count ����
			if (isBingo)
			{
				++count;
			}
		}

		return count;
	}

	/// <summary>
	/// �밢���� ���� ����.
	/// </summary>
	/// <returns></returns>
	int CountDiagonalBingo() const
	{
		// -  �밢���� ��� ���ڸ� �����
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

			//0�� �ƴѰ� ������ false�� �Ǳ� ������ true�� ���´� ���� 0�λ����� => ���� �̹Ƿ� count ����
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

			//0�� �ƴѰ� ������ false�� �Ǳ� ������ true�� ���´� ���� 0�λ����� => ���� �̹Ƿ� count ����
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
