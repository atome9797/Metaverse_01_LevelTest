#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>

int main()
{

	srand(time(NULL));

	int map[5][5];

	//���� ����
	int bingo_random = rand() % 25 + 1;

	int bingo[25] = { 0 };

	for (int i = 0; i < 25; i++)
	{
		while (1)
		{
			int search = 0;

			for (int j = 0; j < i; j++)
			{
				if (bingo[j] == bingo_random)
				{
					search = 1;
					bingo_random = rand() % 25 + 1;
				}
			}

			if (search == 0) {
				break;
			}
		}
		bingo[i] = bingo_random;
	}

	//�� ����
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			map[i][j] = bingo[5 * i + j];
		}
	}



	int n = 0;
	while (1)
	{
		
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				std::cout << map[i][j] << "    ";
			}
			std::cout << std::endl;
		}
		
		
		
		std::cout << "���� " << n << "���� ���� �ϼ��Ǿ����ϴ�." << std::endl;
		
		std::cout << "���ڸ� �Է��� �ּ��� : ";
		
		int ch = 0;
		scanf("%d", &ch);
		



		//�Է� ���� ��ȣ ����
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (map[i][j] == ch) {
					map[i][j] = 0;
				}
			}
		}


		int count_line_w[5] = { 5, 5 ,5, 5,5 }; //������ ī��Ʈ
		int count_line_h[5] = { 5, 5 ,5, 5,5 }; //������ ī��Ʈ
		int count_line_s1 = 5; //�밢�� ī��Ʈ
		int count_line_s2 = 5; //�밢�� ī��Ʈ


		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{

				//������ ī��Ʈ
				if (map[i][j] == 0)
				{
					count_line_w[i] -= 1;
				}/*
				else
				{
					count_line_w[i] = 0;
				}*/

				//������ ī��Ʈ
				if (map[j][i] == 0)
				{
					count_line_h[i] -= 1;
				}/*
				else
				{
					count_line_h[i] = 0;
				}*/

				//�밢�� ī��Ʈ = ������ 
				if (i == j && map[j][i] == 0)
				{
					count_line_s1 -= 1;
				}/*
				else {
					count_line_s1 = 0;
				}*/

				//�밢�� ī��Ʈ ������ ������ �Ʒ���
				if ((4 - i) == j && map[j][i] == 0)
				{
					count_line_s2 -= 1;
				}/*
				else
				{
					count_line_s2 = 0;
				}*/
			}
		}

		int resultCount = 0;
		for (int i = 0; i < 5; i++)
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
		else if (count_line_s1 == 0)
		{
			resultCount += 1;
		}


		n = resultCount;


		system("cls");
	}

	


	return 0;
}