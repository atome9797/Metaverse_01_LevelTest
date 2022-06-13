#include <iostream>

using namespace std;

int main() {
	
	//1. ���� ���� ���� �����ؾ���
	//2���� �迭�� �����͸� �޴´�.
	int board[5][5] = { 0 };
	int isUsed[26] = { false }; //�߰����� ������ �ο� �ؼ� �ð� ���⵵�� ���ߴ� ���

	srand(time(NULL));

	//1-1. �����ϰ� ���� ��ġ�ؾ���
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
		
		//��Ȳ ���
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


		cout << "���� " << bingoCount << "���� ���� �ϼ��Ǿ����ϴ�." << endl;
		
		//2. ����ڷκ��� �Է��� �޴´�.
		cout << "���ڸ� �Է��� �ּ��� : ";
		int input;
		cin >> input;

		//3. ������� �Է��� ��ȿ���� �Ǵ��Ѵ�.
		if (input <= 0 || input > 25)
		{
			//3-1. ���Է��� �ߴٸ�? 1�� ���� �ٽ� �Ѵ�.

		}

		//4. ���ڸ� �����ش�.
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (board[i][j] == input) {
					board[i][j] = 0;
				}
			}
		}

		//5. ���� ������ ����.
		int count_line_w[5] = { 5, 5 ,5, 5, 5 }; //������ ī��Ʈ
		int count_line_h[5] = { 5, 5 ,5, 5, 5 }; //������ ī��Ʈ
		int count_line_s1 = 5; //�밢�� ī��Ʈ
		int count_line_s2 = 5; //�밢�� ī��Ʈ
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




		//6. 1�� ���� �ݺ��Ѵ�.

	}
	



	return 0;
}