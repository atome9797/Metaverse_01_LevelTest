#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

//Lotto Ÿ�� 
//Make() : �ζ� ��ȣ�� �����Ѵ�. �̹� ������ ��ȣ�� �ִٸ� ����� ���� �����.
//Print() : �ε� ��ȣ�� ����Ѵ�. ���࿡ ������ ��ȣ�� ���ٸ� �ƹ��͵� ������� �ʴ´�.
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
	/// �����͸� �����.
	/// </summary>
	void Clear()
	{
		delete[] _lotto;
		_lotto = nullptr;
		_digitCount = 0;
	}

	void Make(int maxValue, int digitCount) {
		
		//1. �̹� ������ ��ȣ�� �����ش�.
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

//���� �Ҵ��� ������. ��, �޸𸮸� �������� �����Ҷ��� ������
//1. �Ҵ��� �ߴµ� ������ ���ߴ�. => �޸� ����(memmory leak)
//2. �̹� ������ �޸𸮿� ���ؼ� �� ��ü �Ѵ�. -> �������� (double Free)
//	- �̹� ������ �޸𸮸� ����Ű�� ������ => ��۸� ������ (Dangling Pointer)
//3. �ʹ� ���� �����ߴ�. => ���� ����(premature free) 


//Lotto Ÿ�� 
//Make() : �ζ� ��ȣ�� �����Ѵ�. �̹� ������ ��ȣ�� �ִٸ� ����� ���� �����.
//Print() : �ε� ��ȣ�� ����Ѵ�. ���࿡ ������ ��ȣ�� ���ٸ� �ƹ��͵� ������� �ʴ´�.


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
	/// �����͸� �����.
	/// </summary>
	void Clear()
	{
		_digitCount = 0;
	}

	void Make(int maxValue, int digitCount) {

		//digitCount : [1, 100] ���� ���� ó��
		//c++ 20���� std::clamp �Լ��� ó�� ����

		//1. digitCount�� �ּڰ� ���� ������
		//2. digitCount�� �ִ� ���� Ŭ��
		//3. digitCount�� �ּڰ��� �ִ� ���̿� ������

		//max�Լ��� �� ���� ���� �ִ��� ��ȯ
		//min�Լ��� �� ���� ���� �ּڰ��� ��ȯ
		digitCount = std::max(1, std::min(digitCount, (int)MAX_DIGIT_COUNT));
		//������ 1 ~  MAX_DIGIT_COUNT ���̷� ����
		//digitCount�� �����ϰ�� 1�� ó���ϱ� ���� max�� �����


		//1. �̹� ������ ��ȣ�� �����ش�.
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
/// �ζ� ��ȣ�� �����.
/// </summary>
/// <param name="maxValue">�ִ� ��ȣ��</param>
/// <param name="digitCount">�������� ����</param>
/// <returns>�ζ� ��ȣ��</returns>
int* lottoFunc(int maxValue, int digitCount)
{
	// 1 ~ maxValue ������ ���� �ߺ����� �ʰ� digitCount��ŭ ����
	int* lotto_t = new int[digitCount];

	srand(time(NULL));


	//�ζ� ��ȣ ���ϱ�
	//1. [1 - maxValue]������ ������ �������� �̴´�. ���� ���� N�̶� �Ѵ�.
	//2. �ߺ����� Ȯ���Ѵ�.
	//2-1,. �ߺ��̸�? 1���� �ٽ� �����Ѵ�.
	//2-2. �ߺ��� �ƴϸ� �����͸� �����Ѵ�.
	//3. 1������ digitCount��ŭ �ݺ��Ѵ�.
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

	//�Է� : �ִ� ��ȣ���� ���� ���� ������ �Է� �޴´�.
	cout << "�ִ� ��ȣ ���� �Է��ϼ��� : ";
	int maxValue;
	cin >> maxValue;
	
	cout << "������ ������ ������ �Է��ϼ���. : ";
	int digitCount;
	cin >> digitCount;

	//ó�� : �ζ� ����
	// 1 ~ maxValue ������ ���� �ߺ����� �ʰ� digitCount��ŭ ����
	//int* lotto = lottoFunc(maxValue, digitCount);


	////��� : �ζ� ��ȣ ���
	//for (int i = 0; i < digitCount; i++)
	//{
	//	cout << lotto[i] << " ";
	//}

	//delete[] lotto;


	//ó�� 2
	/*Lotto lotto;
	lotto.Make(maxValue, digitCount);
	lotto.Print();*/

	LimitiedLotto<24> lotto2;
	lotto2.Make(maxValue, digitCount);
	lotto2.Print();


	return 0;
}