#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
int main()
{

	int snail = 0;
	
	std::cout << "�迭�� ũ�⸦ �Է��ϼ��� : ";
	scanf("%d", &snail);

	int snail_map[100][100] = {0};

	//x, y��ǥ�� ���Ѵ��� �ش� ��ǥ���� count ���� �ִ� ������� �����
	int x = 0;
	int y = 0;

	int count = 1;
	int snail_defend_x = snail - 1;
	int snail_defend_y = snail - 1;

	for (int i = 0; i < snail * snail; i++)
	{
			
			int switchNum =  0;

			//�� Ÿ�� ����ġ ��ȯ�ǰ���
			if (y == snail_defend_y)
			{
				switchNum = 1;
			}
			else if (x == snail_defend_x)
			{
				switchNum = 2;
			}
			else if (y == snail - snail_defend_y - 1 && x == snail_defend_x)
			{
				snail_defend_y -= 1;
				switchNum = 3;
			}
			else if (x == snail - snail_defend_x && y == snail - snail_defend_y - 1)
			{
				snail_defend_x -= 1;
				switchNum = 0;
			}


			switch (switchNum)
			{
			case 0: y++; break;
			case 1: x++; break;
			case 2: y--; break;
			case 3: x--; break;
			}

			snail_map[x][y] = count;
			count++;

		
	}

	for (int i = 0; i < snail; i++)
	{
		for (int j = 0; j < snail; j++)
		{
			std::cout << snail_map[i][j] << "    ";
		}
		std::cout << std::endl;
	}


	return 0;
}