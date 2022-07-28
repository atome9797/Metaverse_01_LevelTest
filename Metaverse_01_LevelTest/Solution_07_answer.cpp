#include <iostream>

#define size 10
using namespace std;

int main() {
	
	//1. ���� ���� ���� �����ؾ���
	//2���� �迭�� �����͸� �޴´�.
	int board[size][size] = { 0 };
	int isUsed[size* size + 1] = { false }; //�߰����� ������ �ο� �ؼ� �ð� ���⵵�� ���ߴ� ���

	srand(time(NULL));

	//1-1. �����ϰ� ���� ��ġ�ؾ���
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
		
		//��Ȳ ���
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


		cout << "���� " << bingoCount << "���� ���� �ϼ��Ǿ����ϴ�." << endl;
		
		//2. ����ڷκ��� �Է��� �޴´�.
		cout << "���ڸ� �Է��� �ּ��� : ";
		int input;
		cin >> input;

		//3. ������� �Է��� ��ȿ���� �Ǵ��Ѵ�.
		if (input <= 0 || input > (size* size))
		{
			system("cls");
			//3-1. ���Է��� �ߴٸ�? 1�� ���� �ٽ� �Ѵ�.
			continue;
		}

		//4. ���ڸ� �����ش�.
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (board[i][j] == input) {
					board[i][j] = 0;
				}
			}
		}


		//5. ���� ������ ����.
		int count_line_w[size] = {0}; //������ ī��Ʈ
		int count_line_h[size] = {0};//������ ī��Ʈ
		fill_n(count_line_h, size, size);
		fill_n(count_line_w, size, size);

		int count_line_s1 = size; //�밢�� ī��Ʈ
		int count_line_s2 = size;//�밢�� ī��Ʈ

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

		//6. 1�� ���� �ݺ��Ѵ�.

		system("cls");
	}
	



	return 0;
}