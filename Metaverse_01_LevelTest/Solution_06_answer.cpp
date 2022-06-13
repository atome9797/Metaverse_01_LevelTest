#include <iostream>
#include <sstream>
using namespace std;

//0 ~ 12 :�����̵�
//13 ~ 25 :Ŭ�ι�
//26 ~ 38 :��Ʈ
//39 ~ 51 :���̾�
//52 : ��Ŀ
static bool isUsedCard[53] = { false };


/// <summary>
/// ī�� 7���� �̴´�.
/// </summary>
/// <returns></returns>
int* PickCard()
{
	int* deck = new int[7];

	srand(time(NULL));

	for (int i = 0; i < 7; i++)
	{

		int randomCard = rand() % 53;

		/*
		for (int j = 0; j < i; j++)
		{
			if (true == isUsedCard[randomCard])
			{
				j = - 1;
				randomCard = rand() % 53;
			}
		}*/

		do
		{
			randomCard = rand() % 53;
		} while (true == isUsedCard[randomCard]);

		deck[i] = randomCard;
		isUsedCard[randomCard] = true;
	}

	return deck;

}

/// <summary>
/// ī�� 7���� �̴´�.
/// </summary>
/// <param name="deck">�÷��̾��� ��</param>
void PickCard(int* deck)//deck is out parameter //pointer to int
{
	//�ߺ����� �ʰ� ī�带 �̾ƾ� ��
	//ī��� ������ [0 , 52]
	//deck�� ũ��� 7

	srand(time(NULL));
	
	for (int i = 0; i < 7; i++)
	{
		
		int randomCard = rand() % 53;

		/*
		for (int j = 0; j < i; j++)
		{
			if (true == isUsedCard[randomCard])
			{
				j = - 1;
				randomCard = rand() % 53;
			}
		}*/

		do
		{
			randomCard = rand() % 53;
		} while (true == isUsedCard[randomCard]);

		deck[i] = randomCard;
		isUsedCard[randomCard] = true;
		
	}


}


/// <summary>
/// cardIndex�� �����Ǵ� card ���ڿ��� �ٲ۴�.
/// 0 ~ 12 :�����̵�
//13 ~ 25 :Ŭ�ι�
//26 ~ 38 :��Ʈ
//39 ~ 51 :���̾�
//52 : ��Ŀ
	//12�� ������ ��12
/// </summary>
/// <param name="cardIndex"></param>
/// <returns></returns>

std::string ConvertToCardString(int cardIndex)
{
	
	std::stringstream ss;

	int cardType = cardIndex / 13;
	int cardNUmber = cardIndex % 13;

	static const string CARD_TYPE[] = {"��","��","��","��"};
	static const string CARD_NUMBER[] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K" };
	
	if (cardType == 4)
	{
		return "Joker";
	}
	else {
		return CARD_TYPE[cardType] + CARD_NUMBER[cardNUmber];
	}

}


int main() {

	//�� 53 ���� ī�尡 ���� -> 14���� �̾ƾ� ��
	//�� ���� �÷��̾�� ���� 7���� ���
	int player1Deck[7] = {0};
	PickCard(player1Deck);

	int* player2Deck = PickCard();

	for (int i = 0; i < 7; i++)
	{
		cout << ConvertToCardString(player1Deck[i]) << " ";
	}

	cout << endl;

	for (int i = 0; i < 7; i++)
	{
		cout << ConvertToCardString(player2Deck[i]) << " ";
	}



	return 0;
}