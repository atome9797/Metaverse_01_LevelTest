#include <iostream>
#include <sstream>
using namespace std;



//Deck Ÿ��
// 1. ��� ���� ī�尡 �ߺ����� �ʾƾ� �Ѵ�.
//Make() 
//	: ī�带 7�� �̾Ƽ� ���� �����Ѵ�.
//	  ��� ���� ī�尡 �ߺ����� �ʾƾ� �Ѵ�. 
// �� ī�尡 ������� ���� ��� ��������� ������ �ִ�.
//	Deck decks[7]; decks.Make();
//	Deck deck; deck.Make() =>  ���� 
//ToString() 
//		:
//		���� ���� ī�带 ǥ���ϴ� ���ڿ��� �����.
//		ī�尡 ���� ��� "the deck is empty"�� ��ȯ�Ѵ�.

class Deck
{

//0 ~ 12 :�����̵�
//13 ~ 25 :Ŭ�ι�
//26 ~ 38 :��Ʈ
//39 ~ 51 :���̾�
//52 : ��Ŀ
static bool isUsedCard[53]; 
//private�� �����߾ static�� ���� �����̹Ƿ� ��𿡼��� �����ִ� ������ �ȴ�.
static int remainCard;
static const string CARD_TYPE[4];
static const string CARD_NUMBER[13];

public:


	Deck() = default;
	Deck(const Deck& other) = delete;
	Deck& operator=(const Deck& other) = delete;
	~Deck() = default;
	
	/// <summary>
	/// ī�� 7���� �̾Ƽ� ���� �����Ѵ�.
	/// ��� ���� ī�尡 �ߺ����� �ʾƾ� �Ѵ�.
	/// </summary>
	/// <returns>���� ���������� �����Ǿ��� ��� true �ƴϸ� false</returns>
	bool Make()
	{
		
		srand(time(NULL));

		//���� isUsedCard �迭�� ������ ���� ������ ������.
		//�׷��Ƿ� �迭������ �����ϰ� true false�� ����Ѵ�.
		
		if (remainCard < 7) {
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
		//���� ���� : ���� �ϼ��Ǿ���.
		remainCard -=7;
			
		return true;
	}

	/// <summary>
	/// ���� ���� ī�带 ǥ���ϴ� ���ڿ��� �����.
	/// ī�尡 ���� ��� "the deck is empty"�� ��ȯ�Ѵ�.
	/// </summary>
	/// <returns></returns>
	/// 
	/// �Է�
	/// ó��
	/// 1. ���� ī�尡 ���� 0�̸� the deck is empty" �� ��ȯ�ϰ� �Ѵ�.
	/// ���
	string  ToString()
	{
		
		stringstream ss;

		int card_count = 0;

		for (int i = 0; i < 7; i++)
		{
			if (deck[i] == 0) {
				card_count++;
			}
		}

		//���� ��°��� null�̸� the deck is empty ��ȯ
		if (card_count == 7) {
			return "the deck is empty";
		}


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

	

		return ss.str();
		
	}
private:
	int deck[7] = {0};
};


const string Deck::CARD_TYPE[4] = { "��","��","��","��" };
const string Deck::CARD_NUMBER[13] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
bool Deck::isUsedCard[53] = { false };
int Deck::remainCard = 53;



/// <summary>
/// ī�� 7���� �̴´�.
/// </summary>
/// <returns></returns>
//int* PickCard()
//{
//	int* deck = new int[7];
//
//	srand(time(NULL));
//
//	for (int i = 0; i < 7; i++)
//	{
//
//		int randomCard = rand() % 53;
//
//		/*
//		for (int j = 0; j < i; j++)
//		{
//			if (true == isUsedCard[randomCard])
//			{
//				j = - 1;
//				randomCard = rand() % 53;
//			}
//		}*/
//
//		do
//		{
//			randomCard = rand() % 53;
//		} while (true == isUsedCard[randomCard]);
//
//		deck[i] = randomCard;
//		isUsedCard[randomCard] = true;
//	}
//
//	return deck;
//
//}

/// <summary>
/// ī�� 7���� �̴´�.
/// </summary>
/// <param name="deck">�÷��̾��� ��</param>
//void PickCard(int* deck)//deck is out parameter //pointer to int
//{
//	//�ߺ����� �ʰ� ī�带 �̾ƾ� ��
//	//ī��� ������ [0 , 52]
//	//deck�� ũ��� 7
//
//	srand(time(NULL));
//	
//	for (int i = 0; i < 7; i++)
//	{
//		
//		int randomCard = rand() % 53;
//
//		/*
//		for (int j = 0; j < i; j++)
//		{
//			if (true == isUsedCard[randomCard])
//			{
//				j = - 1;
//				randomCard = rand() % 53;
//			}
//		}*/
//
//		do
//		{
//			randomCard = rand() % 53;
//		} while (true == isUsedCard[randomCard]);
//
//		deck[i] = randomCard;
//		isUsedCard[randomCard] = true;
//		
//	}
//
//
//}


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
	
	Deck decks[7];
	for (int i = 0; i < 7; i++)
	{
		decks[i].Make();
		cout << decks[i].ToString() << endl;
	}

	Deck deck;
	if (deck.Make() == false) {
		cout << "����" << endl;
	}

	cout << deck.ToString() << endl;


	return 0;
}