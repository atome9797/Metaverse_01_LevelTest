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
		cout << "탐색값 존재" << endl;
	}
	else {
		cout << "탐색값 존재하지 않음" << endl;
	}

	//일반 배열에서 알고리즘 활용
	//binary_search는 배열의 주소값을 받음
	if (binary_search(arr, arr+ 10, 11) == true) {
		cout << "탐색값 존재" << endl;
	}
	else {
		cout << "탐색값 존재하지 않음" << endl;
	}
	
	//벡터 컨테이너에서 알고리즘 활용
	vector <int> vec = { 4,5,6,7,8,9,10,11 };
	//
	if (binary_search(vec.begin(), vec.end(), 10)) //10을 찾으면 true를 출력해준다.
	{
		cout << "벡터 탐색값 존재" << endl;
	}
	else {
		cout << "벡터 탐색값 존재하지 않음" << endl;
	}



	return 0;
}