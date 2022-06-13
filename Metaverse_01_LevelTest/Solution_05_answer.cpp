#include <iostream>

using namespace std;

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
	int* lotto = new int[digitCount];
	
	//�ζ� ��ȣ ���ϱ�
	//1. [1 - maxValue]������ ������ �������� �̴´�. ���� ���� N�̶� �Ѵ�.
	//2. �ߺ����� Ȯ���Ѵ�.
	//2-1,. �ߺ��̸�? 1���� �ٽ� �����Ѵ�.
	//2-2. �ߺ��� �ƴϸ� �����͸� �����Ѵ�.
	//3. 1������ digitCount��ŭ �ݺ��Ѵ�.

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



	//��� : �ζ� ��ȣ ���
	for (int i = 0; i < digitCount; i++)
	{
		cout << lotto[i] << " ";
	}


	delete[] lotto;

	return 0;
}