#include <iostream>
int main()
{

	char card_num[13] = {'A','2' ,'3' ,'4' ,'5' ,'6' ,'7' ,'8','9','10','J','Q','K'};
	char card_img[4] = { '♠','♣','♥','◆' };
	
	

	srand(time(NULL));

	//유저에게 카드를 번호를 나눠줌
	int player[14] = {0};
	
	int card_rand = rand() % 53;

	
	//플레이어 랜덤값
	for (int i = 0; i < 14; i++)
	{
		while (1)
		{
			int search = 0;

			for (int j = 0; j < i; j++)
			{
				if (player[j] == card_rand)
				{
					search = 1;
					card_rand = rand() % 53;
				}
			}

			if (search == 0) {
				break;
			}
		}
		player[i] = card_rand;
	}


	for (int i = 0; i < 14; i++)
	{
		if (i == 0) {
			std::cout << "Player 1 : ";
		}
		else if(i == 7) {
			std::cout << std::endl;
			std::cout << "Player 2 : ";
		}



		if (i < 7) {
			int x = player[i] / 13; //0 ~ 12 은 0, 13 ~ 25은 1, ...
			int y = player[i] % 13; //0 ~ 12나옴

			switch (x)
			{
			case 0: std::cout << "♠";  break;
			case 1: std::cout << "♣";  break;
			case 2: std::cout << "♥";  break;
			case 3: std::cout << "◆";  break;
			}


			if (y == 9) {
				std::cout << "10" << ",";
			}
			else if (x == 4 && y == 0) {
				std::cout << "◆";
				std::cout << card_num[y] << ",";
			}
			else if(x == 4 && y == 0) {
				std::cout << "Joker" << ",";

			}
			else {
				std::cout << card_num[y] << ",";
			}

		}
		else
		{
			int x = player[i] / 13; //0 ~ 12 은 0, 13 ~ 25은 1, ...
			int y = player[i] % 13; //0 ~ 12나옴

			switch (x)
			{
			case 0: std::cout << "♠";  break;
			case 1: std::cout << "♣";  break;
			case 2: std::cout << "♥";  break;
			case 3: std::cout << "◆";  break;
			}

			if (y == 9) {
				std::cout << "10" << ",";
			}else if (x == 4 && y == 0) {
				std::cout << "◆";
				std::cout << card_num[y] << ",";
			}
			else if (x == 4 && y == 0) {
				std::cout << "Joker" << ",";

			}
			else {
				std::cout << card_num[y] << ",";
			}

		}

		
	}
	std::cout << std::endl;
		for (int i = 0; i < 14; i++)
		{
			std::cout << player[i] << std::endl;
		}


	return 0;
}