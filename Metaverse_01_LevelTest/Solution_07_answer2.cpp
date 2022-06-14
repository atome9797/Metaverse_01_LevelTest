#include <iostream>

using namespace std;

#define BLANK 0

int main()
{

	//1. �������� �ʱ�ȭ
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

		//2. ���� ��Ȳ���
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

		cout << "���� " << bingoCount << "���� ���� �ϼ��Ǿ����ϴ�." << endl;

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


		//4. �������� �ֽ�ȭ => ���ڸ� ���� �ش�.
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

		//5. ���� ������ ����.
		// -  ������ ��� ���ڸ� �����
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

			//0�� �ƴѰ� ������ false�� �Ǳ� ������ true�� ���´� ���� 0�λ����� => ���� �̹Ƿ� count ����
			if (isBingo)
			{
				++count;
			}
		}

		// -  ������ ��� ���ڸ� �����
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

			//0�� �ƴѰ� ������ false�� �Ǳ� ������ true�� ���´� ���� 0�λ����� => ���� �̹Ƿ� count ����
			if (isBingo)
			{
				++count;
			}
		}

		// -  �밢���� ��� ���ڸ� �����

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

			//0�� �ƴѰ� ������ false�� �Ǳ� ������ true�� ���´� ���� 0�λ����� => ���� �̹Ƿ� count ����
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

			//0�� �ƴѰ� ������ false�� �Ǳ� ������ true�� ���´� ���� 0�λ����� => ���� �̹Ƿ� count ����
			if (isBingo)
			{
				++count;
			}
		}

		bingoCount = count;


		//6. 2�� ���� �ٽ� �ݺ� �Ѵ�.
	}

	return 0;
}