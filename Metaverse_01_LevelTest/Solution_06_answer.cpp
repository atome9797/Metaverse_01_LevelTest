#include <iostream>
#include <sstream>
using namespace std;

//0 ~ 12 :스페이드
//13 ~ 25 :클로버
//26 ~ 38 :하트
//39 ~ 51 :다이아
//52 : 조커
static bool isUsedCard[53] = { false };


/// <summary>
/// 카드 7장을 뽑는다.
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
/// 카드 7장을 뽑는다.
/// </summary>
/// <param name="deck">플레이어의 덱</param>
void PickCard(int* deck)//deck is out parameter //pointer to int
{
	//중복되지 않게 카드를 뽑아야 함
	//카드는 정수값 [0 , 52]
	//deck의 크기는 7

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
/// cardIndex에 대응되는 card 문자열로 바꾼다.
/// 0 ~ 12 :스페이드
//13 ~ 25 :클로버
//26 ~ 38 :하트
//39 ~ 51 :다이아
//52 : 조커
	//12가 들어오면 ♠12
/// </summary>
/// <param name="cardIndex"></param>
/// <returns></returns>

std::string ConvertToCardString(int cardIndex)
{
	
	std::stringstream ss;

	int cardType = cardIndex / 13;
	int cardNUmber = cardIndex % 13;

	static const string CARD_TYPE[] = {"♠","♣","♥","◆"};
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

	//총 53 장의 카드가 있음 -> 14개를 뽑아야 함
	//두 명의 플레이어에게 각각 7장을 배부
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