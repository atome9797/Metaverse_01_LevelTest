#pragma once
#include <string>
#include <iostream>

using namespace std;

class Player
{
public:

	void UpgradeScore(string subject)
	{
		if (subject == "수학")
		{
			math_score--;
		}
		else if (subject == "영어")
		{
			english_score--;
		}
		else if (subject == "과학")
		{
			science_score--;
		}
		else if (subject == "국어")
		{
			korean_score--;
		}
	}

	void UserInformation()
	{
		cout << "----------------------------------------\n";

		cout << "사용자 이름 : " << _user_name << endl;
		cout << "과목별 등급 " << endl;
		cout << "수학 : " << math_score << "등급" << endl;
		cout << "영어 : " << english_score << "등급" << endl;
		cout << "과학 : " << science_score << "등급" << endl;
		cout << "국어 : " << korean_score << "등급" << endl;
		cout << "자본금 : " << coin << endl;
		cout << "체력 : " << stamina << endl;
		cout << "집중력 : " << concentration << endl;
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

	void setStamina(int stamina)
	{
		this->stamina = stamina;
	}

	int getCoin()
	{
		return coin;
	}

	void setCoin(int coin)
	{
		this->coin = coin;
	}

	bool isGotoSeoulUniversity()
	{
		if (math_score != 0 || english_score != 0 || science_score != 0 || korean_score != 0)
		{
			return false;
		}

		return true;
	}


	void setConcentration(int concentration)
	{
		this->concentration = concentration;
	}

	int getConcentration()
	{
		return concentration;
	}

private:
	string _user_name = "";
	int math_score = 9;
	int english_score = 9;
	int science_score = 9;
	int korean_score = 9;
	int coin = 10;
	int stamina = 10;
	int concentration = 10;
};
