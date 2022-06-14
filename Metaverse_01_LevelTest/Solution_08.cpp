#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
int main()
{

	int snail = 0;
	
	std::cout << "배열의 크기를 입력하세요 : ";
	scanf("%d", &snail);

	//int snail_map[100][100] = {0};
	
	//2차원 배열 동적할당
	int** arr = new int* [snail];

	for (int i = 0; i < snail; i++)
	{
		arr[i] = new int[snail];
	}


	//x, y좌표를 구한다음 해당 촤표값에 count 값을 넣는 방식으로 만들기
	int x = 0;
	int y = 0;

	int count = 2;
	int snail_defend_x = snail - 1;
	int snail_defend_y = snail - 1;
	int switchNum = 0;
	arr[0][0] = 1;
	for (int i = 1; i < snail * snail; i++)
	{
			

			//벽 타면 스위치 전환되게함
			if (switchNum == 0 && y == snail_defend_y)
			{
				switchNum = 1;
			}
			else if (switchNum == 1 && x == snail_defend_x)
			{
				switchNum = 2;
			}
			else if (switchNum == 2 && y == snail - snail_defend_y - 1)
			{
				snail_defend_y -= 1;
				switchNum = 3;
			}
			else if (switchNum == 3 && x == snail - snail_defend_x)
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

			arr[x][y] = count;
			count++;

		
	}

	for (int i = 0; i < snail; i++)
	{
		for (int j = 0; j < snail; j++)
		{
			std::cout << arr[i][j] << "\t";
		}
		std::cout << std::endl;
	}


	//할당 해제
	for (int i = 0; i < snail; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;


	return 0;
}