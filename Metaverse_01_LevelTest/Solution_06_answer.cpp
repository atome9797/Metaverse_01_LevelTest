#include <iostream>
#include <sstream>
using namespace std;

//0 ~ 12 :스페이드
//13 ~ 25 :클로버
//26 ~ 38 :하트
//39 ~ 51 :다이아
//52 : 조커
static bool isUsedCard[53] = { false };



//Deck 타입
// 1. 모든 덱은 카드가 중복되지 않아야 한다.
//Make() 
//	: 카드를 7장 뽑아서 덱을 구성한다.
//	  모든 덱은 카드가 중복되지 않아야 한다. 
// 단 카드가 충분하지 않은 경우 만들어지지 않을수 있다.
//	Deck decks[7]; decks.Make();
//	Deck deck; deck.Make() =>  실패 
//ToString() 
//		:
//		현재 덱의 카드를 표현하는 문자열을 만든다.
//		카드가 없는 경우 "the deck is empty"로 반환한다.

class Deck
{
	
public:


	Deck() = default;
	Deck(const Deck& other) = delete;
	Deck& operator=(const Deck& other) = delete;

	/// <summary>
	/// 카드 7장을 뽑아서 덱을 구성한다.
	/// 모든 덱은 카드가 중복되지 않아야 한다.
	/// </summary>
	/// <returns>덱이 성공적으로 구성되었을 경우 true 아니면 false</returns>
	bool Make()
	{
		
		srand(time(NULL));

		//만약 isUsedCard 배열이 꽉차면 무한 루프에 빠진다.
		//그러므로 배열개수를 측정하고 true false를 출력한다.
		int card_count = 0;
		
		for (int i = 0; i < 53; i++)
		{
			if (isUsedCard[i] == false) {
				card_count++;
			}
		}

		if (card_count < 7) {
			return false;
		}

		for (int i = 0; i < 7; i++)
		{
			int random = 0;

			do
			{ 
				random = rand() % 53;
			} while (isUsedCard[random] == true);

			isUsedCard[random] = true;
			deck[i] = random;
		}
			
		return true;
	}

	string  ToString()
	{
		static const string CARD_TYPE[] = { "♠","♣","♥","◆" };
		static const string CARD_NUMBER[] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };

		stringstream ss;

		for (int i = 0; i < 7; i++)
		{
			int cardType = deck[i] / 13;
			int cardNUmber = deck[i] % 13;

			if (cardType == 4)
			{
				ss << "Joker";
			}
			else {
				ss << CARD_TYPE[cardType] + CARD_NUMBER[cardNUmber] << "  ";
			}

		}

		//덱의 출력값이 null이면 the deck is empty 반환
		if (ss.str() == "")
		{
			return "the deck is empty";
		}

		return ss.str();
		
	}
private:
	int deck[7] = {0};
};




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
	//int player1Deck[7] = {0};
	//PickCard(player1Deck);

	//int* player2Deck = PickCard();

	//for (int i = 0; i < 7; i++)
	//{
	//	cout << ConvertToCardString(player1Deck[i]) << " ";
	//}

	//cout << endl;

	//for (int i = 0; i < 7; i++)
	//{
	//	cout << ConvertToCardString(player2Deck[i]) << " ";
	//}
	
	Deck deck;
	deck.Make();
	deck.ToString();

	return 0;
}