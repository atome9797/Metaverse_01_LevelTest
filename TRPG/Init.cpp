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

	cout << "����� �հ����� ����!" << endl;

	cout << "�� ������ ����븦 �հ��ϱ� ���� ġ���� ������\n ġ��� ������� �����̾߱��Դϴ�.\n ����� �����е� ��� ȭ���� �Ͻð� ���� ������ ���ñ� �ٶ��ϴ�.\n" << endl;

	cout << "����� �̸��� �Է��� �ּ���. : ";

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

		cout << "�Է� : " << endl;
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
	//�п����� ���ߵ� ����
	
	srand(time(NULL));

	//1���� 5������ �������� ���߷� ����
	int random = rand() % 5;

	cout << "�п� ����� 3���� �Դϴ�." << endl;
	cout << "����� ���߷��� "<< random << "�ö����ϴ�." << endl;
	
	int Concentration = player->getConcentration();
	
	player->setConcentration(Concentration + random);

	cout << "��������" << endl;

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

		//������ �������� �ְ� 70���̻�Ǹ� �հ�.
		//�׽�Ʈ �Ҷ� ���� ü�� 1�� ����
		//ü�� �����Ǹ� ���� ���� => �������� ��Դ°ɷ� ü�� ü�������

		srand(time(NULL));
		if (random == 0)
		{
			answer = test->math();
		}
		else {
			answer = test->english();
		}

		
		//����� ����
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
		player->UpgradeScore("����");
	}
	else {
		player->UpgradeScore("����");
	}

}

int Menu()
{

	int input_type_number = 0;

	while (1)
	{

		cout << "���� �޴�" << endl;

		switch (input_type_number)
		{
		case 0: cout << "��1. �׽�Ʈ\n2. �п�\n3. ����" << endl; break;
		case 1: cout << "1. �׽�Ʈ\n��2. �п�\n3. ����" << endl; break;
		case 2: cout << "1. �׽�Ʈ\n2. �п�\n��3. ����" << endl; break;
		}

		//����� ����
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

		//�׽�Ʈ
		if (menu_number == 0)
		{
			Test_1(player1);
		}
		else if (menu_number == 1) //�п�
		{
			cram_school(player1);
		}
		else if (menu_number == 2) //����
		{
			store_1(player1);
		}

		if (player1->isGotoSeoulUniversity())
		{
			system("cls");
			cout << "����� �հ�!" << endl;
			break;
		}
		
	}



	if (player1->getStamina() <= 0)
	{
		system("cls");
		cout << "GAME OVER" << endl;
	}


}

