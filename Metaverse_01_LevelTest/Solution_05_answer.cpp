#include <iostream>

using namespace std;

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
	int* lotto = new int[digitCount];
	
	//로또 번호 정하기
	//1. [1 - maxValue]사이의 값으로 무작위로 뽑는다. 뽑은 값을 N이라 한다.
	//2. 중복인지 확인한다.
	//2-1,. 중복이면? 1번을 다시 수행한다.
	//2-2. 중복이 아니면 데이터를 저장한다.
	//3. 1번부터 digitCount만큼 반복한다.

	srand(time(NULL));

	for (int i = 0; i < digitCount; i++)
	{
		int N = rand() % maxValue + 1;
		
		for (int j = 0; j <= i; j++)
		{	
			if (N == lotto[j]) {
				N = rand() % maxValue + 1;
				j = -1;
			}
		}

		lotto[i] = N;
	}



	//출력 : 로또 번호 출력
	for (int i = 0; i < digitCount; i++)
	{
		cout << lotto[i] << " ";
	}


	delete[] lotto;

	return 0;
}