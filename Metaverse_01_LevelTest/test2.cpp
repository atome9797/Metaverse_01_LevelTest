#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool BinarySearch(int *arr, int size, int value)
{
	int s = 0, e = size;

	while (s < e)
	{
		int m = (s + e) / 2;

		if (arr[m] == value)
		{
			return true;
		}
		else if (arr[m] < value)
		{
			s = m + 1;
		}
		else 
		{
			e = m;
		}
	}
	return false;
}

int main()
{

	int arr[] = { 3,4,5,6,7,8,9,10,11,12 };

	if (BinarySearch(arr, 10, 11) == true) {
		cout << "Ž���� ����" << endl;
	}
	else {
		cout << "Ž���� �������� ����" << endl;
	}

	//�Ϲ� �迭���� �˰��� Ȱ��
	//binary_search�� �迭�� �ּҰ��� ����
	if (binary_search(arr, arr+ 10, 11) == true) {
		cout << "Ž���� ����" << endl;
	}
	else {
		cout << "Ž���� �������� ����" << endl;
	}
	
	//���� �����̳ʿ��� �˰��� Ȱ��
	vector <int> vec = { 4,5,6,7,8,9,10,11 };
	//
	if (binary_search(vec.begin(), vec.end(), 10)) //10�� ã���� true�� ������ش�.
	{
		cout << "���� Ž���� ����" << endl;
	}
	else {
		cout << "���� Ž���� �������� ����" << endl;
	}



	return 0;
}