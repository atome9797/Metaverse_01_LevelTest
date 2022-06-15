#include <iostream>
#include <conio.h>

/*
	탈출게임
	1. 플레이어는 p로 표현한다.
	2. 맵은 10x10으로 표현한다.
	3. 플레이어의 초기 위치는 (0,0)이다.
	4. 탈출지점은 E로 표현한다.
	5. 탈출지점의 위치는 (8,8)이다.
	6. 키 입력은 w /a /s /d이다


	###########
	###########
	###########
	###########
	###########
	###########
	###########
	###########
	###########
	###########

	이동할 방향키를 입력해 주세요.
*/
using namespace std;

class ExistGame
{
public:
	ExistGame() = default;
	~ExistGame() = default;
	
	void mapView()
	{
		//맵 출력
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (player_x == i && player_y == j)
				{
					cout << "P";
				}
				else if (i == 8 && j == 8)
				{
					cout << "E";
				}
				else {
					cout << "#";
				}
			}

			cout << endl;
		}
	}
	
	bool move(char input)
	{

		int player_y_1 = player_y;
		int player_x_1 = player_x;


		switch (input)
		{
			case 'a':
			{
				player_y_1--;
				break;
			} 
			case 's': 
			{
				player_x_1++;
				break;
			}
			case 'd': 
			{
				player_y_1++;
				break;
			}
			case 'w': 
			{
				player_x_1--;
				break;
			}
		}

		if (player_y_1 < 0 || player_x_1 >= 10 || player_y_1 >= 10 || player_x_1 < 0)
		{
			return false;
		}
		
		player_y = player_y_1;
		player_x = player_x_1;
		

		if (player_x == 8 && player_y == 8) {
			return true;
		}

		return false;
	}
private:
	char map[10][10] = { 0 };
	int player_x = 0;//세로
	int player_y = 0;//가로
};

int main()
{
	ExistGame game;
	bool exit = false;
	do
	{
		system("cls");
		game.mapView();
		//플레이어 입력
		cout << "이동할 방향키를 입력해 주세요. : ";
		char key = _getch();
		exit = game.move(key);

	} while (exit == false);
	
	cout << "탈출" << endl;
	
	return 0;
}