#pragma once
class store
{
public:

	void storeStatus()
	{

		cout << "구매 하실 품목을 선택해 주세요." << endl;
		cout << "-----------------------------\n";
		cout << "1.빵 (스테미터 5 회복)" << endl;
		cout << "2.우유 (스테미터 3 회복)" << endl;
		cout << "3.노트 (집중력 3 회복)" << endl;
		cout << "4.연필 (집중력 5 회복)" << endl;
		cout << "5.나가기" << endl;
		cout << "-----------------------------\n";
	}

	bool Buy(Player* player, int num)
	{
		int playerCoin = player->getCoin();

		if (num == 1 && playerCoin >= 5)
		{
			playerCoin -= 5;
			player->setCoin(playerCoin);

			for (int i = 0; i < 5; i++)
			{
				player->plusStamina();
			}
		}
		else if (num == 2 && playerCoin >= 3)
		{
			playerCoin -= 3;
			player->setCoin(playerCoin);
			for (int i = 0; i < 3; i++)
			{
				player->plusStamina();
			}
		}

		return true;
	}

private:
	int bread = 5;
	int milk = 3;
	int note = 3;
	int pencil = 5;
};
