#pragma once
class store
{
public:

	void storeStatus()
	{

		cout << "���� �Ͻ� ǰ���� ������ �ּ���." << endl;
		cout << "-----------------------------\n";
		cout << "1.�� (���׹��� 5 ȸ��)" << endl;
		cout << "2.���� (���׹��� 3 ȸ��)" << endl;
		cout << "3.��Ʈ (���߷� 3 ȸ��)" << endl;
		cout << "4.���� (���߷� 5 ȸ��)" << endl;
		cout << "5.������" << endl;
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
