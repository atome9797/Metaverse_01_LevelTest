#include <iostream>
#include "Solution_08_answer.h"

int main() {

	//1. �迭 �����
	cout << "�迭�� ũ�⸦ �Է��ϼ���. : ";
	int size;
	cin >> size;

	int*  arr = new int[size * size];
	memset(arr, 0, sizeof(int) * size * size);


	Snail snailrow;
	snailrow.Make(arr, size);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << arr[i * size + j] << "\t";
		}
		cout << "\n";
	}

	delete[]arr;

	return 0;
}