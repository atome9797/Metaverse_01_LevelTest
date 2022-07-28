#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

//Lotto 타입 
//Make() : 로또 번호를 생성한다. 이미 생성된 번호가 있다면 지우고 새로 만든다.
//Print() : 로도 번호를 출력한다. 만약에 생성된 번호가 없다면 아무것도 출력하지 않는다.
class Lotto
{
public:

	Lotto() = default;
	Lotto(const Lotto& other) = delete;
	Lotto& operator=(const Lotto& other) = delete;
	~Lotto()
	{
		Clear();
	}

	/// <summary>
	/// 데이터를 지운다.
	/// </summary>
	void Clear()
	{
		delete[] _lotto;
		_lotto = nullptr;
		_digitCount = 0;
	}

	void Make(int maxValue, int digitCount) {
		
		//1. 이미 생성된 번호를 지워준다.
		Clear();

		_digitCount = digitCount;

		srand(time(NULL));

		_lotto = new int[digitCount];
		
		for (int curPos = 0; curPos < digitCount; curPos++)
		{
			int random = 0;
			bool isUsed = false;
			do
			{
				isUsed = false;

				random = rand() % maxValue + 1;

				for (int j = 0; j < curPos; j++)
				{
					if (random == _lotto[j])
					{
						isUsed = true;
						break;
					}
				}
			} while (isUsed);

			_lotto[curPos] = random;
		}
		
	}

	void Print() {
		for (int i = 0; i < _digitCount; i++)
		{
			cout << _lotto[i] << " ";
		}
	}
private:
	int* _lotto = nullptr;
	int _digitCount = 0;
};

//동적 할당의 문제점. 즉, 메모리를 수동으로 관리할때의 문제점
//1. 할당은 했는데 해제를 안했다. => 메모리 누수(memmory leak)
//2. 이미 해제한 메모리에 대해서 또 해체 한다. -> 이중해제 (double Free)
//	- 이미 해제한 메모리를 가리키는 포인터 => 댕글링 포인터 (Dangling Pointer)
//3. 너무 빨리 해제했다. => 조기 해제(premature free) 


//Lotto 타입 
//Make() : 로또 번호를 생성한다. 이미 생성된 번호가 있다면 지우고 새로 만든다.
//Print() : 로도 번호를 출력한다. 만약에 생성된 번호가 없다면 아무것도 출력하지 않는다.


template <size_t MAX_DIGIT_COUNT>
class LimitiedLotto
{

public:

	LimitiedLotto() = default;
	LimitiedLotto(const LimitiedLotto& other) = delete;
	LimitiedLotto& operator=(const LimitiedLotto& other) = delete;
	~LimitiedLotto()
	{
		Clear();
	}

	/// <summary>
	/// 데이터를 지운다.
	/// </summary>
	void Clear()
	{
		_digitCount = 0;
	}

	void Make(int maxValue, int digitCount) {

		//digitCount : [1, 100] 범위 제한 처리
		//c++ 20부터 std::clamp 함수로 처리 가능

		//1. digitCount가 최솟값 보다 작을때
		//2. digitCount가 최댓값 보다 클때
		//3. digitCount가 최솟값과 최댓값 사이에 있을때

		//max함수는 두 수를 비교후 최댓값을 반환
		//min함수는 두 수를 비교후 최솟값을 반환
		digitCount = std::max(1, std::min(digitCount, (int)MAX_DIGIT_COUNT));
		//범위를 1 ~  MAX_DIGIT_COUNT 사이로 지정
		//digitCount가 음수일경우 1로 처리하기 위해 max를 사용함


		//1. 이미 생성된 번호를 지워준다.
		Clear();

		
		_digitCount = digitCount;

		srand(time(NULL));


		for (int curPos = 0; curPos < digitCount; curPos++)
		{
			int random = 0;
			bool isUsed = false;
			do
			{
				isUsed = false;

				random = rand() % maxValue + 1;

				for (int j = 0; j < curPos; j++)
				{
					if (random == _lotto[j])
					{
						isUsed = true;
						break;
					}
				}
			} while (isUsed);

			_lotto[curPos] = random;
		}

	}


	void Print() {
		for (int i = 0; i < _digitCount; i++)
		{
			cout << _lotto[i] << " ";
		}
	}

private:
	int _lotto[MAX_DIGIT_COUNT] = {0};
	int _digitCount = 0;
};


/// <summary>
/// 로또 번호를 만든다.
/// </summary>
/// <param name="maxValue">최대 번호값</param>
/// <param name="digitCount">생성숫자 개수</param>
/// <returns>로또 번호들</returns>
int* lottoFunc(int maxValue, int digitCount)
{
	// 1 ~ maxValue 사이의 값중 중복되지 않게 digitCount만큼 뽑음
	int* lotto_t = new int[digitCount];

	srand(time(NULL));


	//로또 번호 정하기
	//1. [1 - maxValue]사이의 값으로 무작위로 뽑는다. 뽑은 값을 N이라 한다.
	//2. 중복인지 확인한다.
	//2-1,. 중복이면? 1번을 다시 수행한다.
	//2-2. 중복이 아니면 데이터를 저장한다.
	//3. 1번부터 digitCount만큼 반복한다.
	for (int i = 0; i < digitCount; i++)
	{
		int N = 0;
		bool isExist = false;

		do
		{
			isExist = false;

			N = rand() % maxValue + 1;

			for (int j = 0; j < i; j++)
			{
				if (N == lotto_t[j]) {
					isExist = true;
					break;
				}
			}

		} while (isExist);


		lotto_t[i] = N;
	}



	return lotto_t;
}


int main() {

	//입력 : 최대 번호값과 생성 숫자 개수를 입력 받는다.
	cout << "최대 번호 값을 입력하세요 : ";
	int maxValue;
	cin >> maxValue;
	
	cout << "생성할 숫자의 개수를 입력하세요. : ";
	int digitCount;
	cin >> digitCount;

	//처리 : 로또 생성
	// 1 ~ maxValue 사이의 값중 중복되지 않게 digitCount만큼 뽑음
	//int* lotto = lottoFunc(maxValue, digitCount);


	////출력 : 로또 번호 출력
	//for (int i = 0; i < digitCount; i++)
	//{
	//	cout << lotto[i] << " ";
	//}

	//delete[] lotto;


	//처리 2
	/*Lotto lotto;
	lotto.Make(maxValue, digitCount);
	lotto.Print();*/

	LimitiedLotto<24> lotto2;
	lotto2.Make(maxValue, digitCount);
	lotto2.Print();


	return 0;
}