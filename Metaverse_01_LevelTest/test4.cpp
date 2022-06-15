#include <iostream>
#include <conio.h>

/*
	Ż�����
	1. �÷��̾�� p�� ǥ���Ѵ�.
	2. ���� 10x10���� ǥ���Ѵ�.
	3. �÷��̾��� �ʱ� ��ġ�� (0,0)�̴�.
	4. Ż�������� E�� ǥ���Ѵ�.
	5. Ż�������� ��ġ�� (8,8)�̴�.
	6. Ű �Է��� w /a /s /d�̴�


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

	�̵��� ����Ű�� �Է��� �ּ���.
*/
using namespace std;

class ExistGame
{
public:
	ExistGame() = default;
	~ExistGame() = default;
	
	void mapView()
	{
		//�� ���
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
	int player_x = 0;//����
	int player_y = 0;//����
};

int main()
{
	ExistGame game;
	bool exit = false;
	do
	{
		system("cls");
		game.mapView();
		//�÷��̾� �Է�
		cout << "�̵��� ����Ű�� �Է��� �ּ���. : ";
		char key = _getch();
		exit = game.move(key);

	} while (exit == false);
	
	cout << "Ż��" << endl;
	
	return 0;
}