#include "Init.h"
#include "Player.h"
#include "Store.h"
#include "Test.h"
#include <conio.h> 
#include <iostream>

using namespace std;

Player* player1 = new Player();
store* store1 = new store();
Test* test = new Test();

void InitMain(Player* player)
{

	cout << "서울대 합격하자 게임!" << endl;

	cout << "본 게임은 서울대를 합격하기 위해 치열한 혈투를\n 치루는 수험생의 도전이야기입니다.\n 수험생 여러분들 모두 화이팅 하시고 좋은 성과를 내시기 바랍니다.\n" << endl;

	cout << "사용자 이름을 입력해 주세요. : ";

	string user_name;

	cin >> user_name;
	player->InputName(user_name);

	system("cls");
}

void store_1(Player* player)
{

	while (1)
	{
		system("cls");

		store1->storeStatus();
		player1->UserInformation();

		cout << "입력 : " << endl;
		int input_key = 0;
		cin >> input_key;

		store1->Buy(player, input_key);

		if (input_key == 5)
		{
			break;
		}
	}

}

void cram_school(Player* player)
{

	system("cls");
	//학원가면 집중도 오름
	
	srand(time(NULL));

	//1에서 5사이의 랜덤으로 집중력 오름
	int random = rand() % 5;

	cout << "학원 비용은 3코인 입니다." << endl;
	cout << "당신의 집중력은 "<< random << "올랐습니다." << endl;
	
	int Concentration = player->getConcentration();
	
	player->setConcentration(Concentration + random);

	cout << "▷나가기" << endl;

	int key = _getch();

	
}

void Test_1(Player* player)
{
	int test_result = 5;
	int random = rand() % 2;
	int answer = 0;

	while (test_result > 0)
	{
		system("cls");

		//과목을 랜덤으로 주고 70점이상되면 합격.
		//테스트 할때 마다 체력 1씩 깍임
		//체력 방전되면 공부 안함 => 매점에서 사먹는걸로 체력 체울수있음

		srand(time(NULL));
		if (random == 0)
		{
			answer = test->math();
		}
		else {
			answer = test->english();
		}

		
		//사용자 정보
		player1->UserInformation();

		char str[10];
		cin >> str;

		if (answer == atoi(str))
		{
			test_result--;
		}

		int Concentration = player->getConcentration();
		if (Concentration > 5)
		{
			player->minorsStamina();
		}
		else
		{
			player->minorsStamina();
			player->minorsStamina();
		}
		player->setConcentration(--Concentration);


		if (player1->getStamina() <= 0)
		{
			break;
		}


	}

	if (random == 0)
	{
		player->UpgradeScore("수학");
	}
	else {
		player->UpgradeScore("과학");
	}

}

int Menu()
{

	int input_type_number = 0;

	while (1)
	{

		cout << "메인 메뉴" << endl;

		switch (input_type_number)
		{
		case 0: cout << "▷1. 테스트\n2. 학원\n3. 매점" << endl; break;
		case 1: cout << "1. 테스트\n▷2. 학원\n3. 매점" << endl; break;
		case 2: cout << "1. 테스트\n2. 학원\n▷3. 매점" << endl; break;
		}

		//사용자 정보
		player1->UserInformation();


		int key = _getch();

		if (key == 13)
		{
			break;
		}

		switch (key)
		{
		case 80: {
			if (input_type_number < 2)
			{
				input_type_number++;
			}
			break;
		}
		case 72: {
			if (input_type_number > 0)
			{
				input_type_number--;
			}
			break;
		}
		}


		system("cls");
	}

	return input_type_number;
}


void Init()
{

	InitMain(player1);
	int finish = true;

	while (player1->getStamina() > 0)
	{
		system("cls");

		int menu_number = Menu();

		//테스트
		if (menu_number == 0)
		{
			Test_1(player1);
		}
		else if (menu_number == 1) //학원
		{
			cram_school(player1);
		}
		else if (menu_number == 2) //매점
		{
			store_1(player1);
		}

		if (player1->isGotoSeoulUniversity())
		{
			system("cls");
			cout << "서울대 합격!" << endl;
			break;
		}
		
	}



	if (player1->getStamina() <= 0)
	{
		system("cls");
		cout << "GAME OVER" << endl;
	}


}

