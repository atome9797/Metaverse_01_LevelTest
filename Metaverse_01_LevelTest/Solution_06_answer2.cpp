#include <iostream>

bool isCard[53] = { false };

using namespace std;

void playerCard(int* num)
{
	srand(time(NULL));
	
	for (int i = 0; i < 7; i++)
	{
		int random = 0;
		do
		{
			random = rand() % 53;
		} while (isCard[random] == true);

		isCard[random] = true;
		num[i] = random;
	}

}

std::string card(int index) 
{

	static const string card_number[] = { "A", "2","3","4","5","6","7","8","9","10","Q","K","J" };
	static const string card_img[] = { "¢¼","¢À","¢¾","¡ß"};

	int card_number_type = index % 13;
	int card_img_type = index / 13;

	if (card_img_type == 4)
	{
		return "Joker";
	}

	return card_img[card_img_type] + card_number[card_number_type];
}


int main()
{
	int player1[7] = {0};
	playerCard(player1);

	for (int i = 0; i < 7; i++)
	{
		cout << card(player1[i]) << "   ";
	}
	


	return 0;
}