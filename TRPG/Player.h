#pragma once
#include <string>
#include <iostream>

using namespace std;

class Player
{
public:

	void UpgradeScore(string subject)
	{
		if (subject == "����")
		{
			math_score--;
		}
		else if (subject == "����")
		{
			english_score--;
		}
		else if (subject == "����")
		{
			science_score--;
		}
		else if (subject == "����")
		{
			korean_score--;
		}
	}

	void UserInformation()
	{
		cout << "----------------------------------------\n";

		cout << "����� �̸� : " << _user_name << endl;
		cout << "���� ��� " << endl;
		cout << "���� : " << math_score << "���" << endl;
		cout << "���� : " << english_score << "���" << endl;
		cout << "���� : " << science_score << "���" << endl;
		cout << "���� : " << korean_score << "���" << endl;
		cout << "�ں��� : " << coin << endl;
		cout << "ü�� : " << stamina << endl;
		cout << "----------------------------------------\n";
	}

	void InputName(string user_name)
	{
		_user_name = user_name;
	}

	int plusStamina()
	{
		stamina++;
		return stamina;
	}

	int minorsStamina()
	{
		stamina--;
		return stamina;
	}

	int getStamina()
	{
		return stamina;
	}

	int getCoin()
	{
		return coin;
	}

	void setCoin(int coin)
	{
		this->coin = coin;
	}

private:
	string _user_name = "";
	int math_score = 9;
	int english_score = 9;
	int science_score = 9;
	int korean_score = 9;
	int coin = 10;
	int stamina = 10;
};
