#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
int main()
{

	int snail = 0;
	
	std::cout << "배열의 크기를 입력하세요 : ";
	scanf("%d", &snail);

	int snail_map[100][100] = {0};

	//x, y좌표를 구한다음 해당 촤표값에 count 값을 넣는 방식으로 만들기
	int x = 0;
	int y = 0;

	int count = 1;
	int snail_defend_x = snail - 1;
	int snail_defend_y = snail - 1;

	//배열 이동할 횟수
	int move_count = snail * 2 - 1;

	//이동횟수가 9 이고 배열이 5면
	//555 44 33 22 
	int co = 0;
	int switchNum = 0;

	co += snail;
	
	for (int i = 0; i < move_count; i++)
	{

		if (i < 3) {

		}
	}
	

	for (int i = 0; i < 25; i++)
	{
		if (i == snail)
		{
			switchNum = 1;
		}
	}






	for (int i = 0; i < 25; i++)
	{
		if (co == 5) //5
		{
			switchNum = 1;
		}
		else if (co == 10) //5
		{
			switchNum = 2;
		}
		else if (co == 15) //5
		{
			switchNum = 3;
		}else if (co == 18) //3
		{
			switchNum = 0;
		}
		else if (co == 21) //3
		{
			switchNum = 0;
		}
		else if (co == 23)//2
		{
			switchNum = 0;
		}
		else if (co == 25) //2
		{
			switchNum = 0;
		}
		co++;
	}


	for (int i = 0; i < snail * snail; i++)
	{
			
			int switchNum =  0;

			//벽 타면 스위치 전환되게함
			if (y == snail_defend_y)
			{
				snail_defend_y -= 1;
				switchNum = 1;
			}
			else if (x == snail_defend_x)
			{
				snail_defend_x -= 1;
				switchNum = 2;
			}
			else if (y == snail - snail_defend_y - 1 && x == snail_defend_x)
			{
				switchNum = 3;
			}
			else if (x == snail - snail_defend_x && y == snail - snail_defend_y - 1)
			{
				snail_defend_x -= 1;
				switchNum = 4;
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