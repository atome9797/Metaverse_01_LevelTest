#include <iostream>

using namespace std;

void Sort(int* arr, int size)
{
	//버블 소트는 여러 페이즈로 이뤄지며,
	//각 페이즈가 끝날시 맨끝 원소부터 정렬된다.

	//0 - 1- 2 -3 -4
	for (int phase = 0; phase < size - 1; phase++)
	{
		//각 페이즈마다 해줘야 하는 일
		// 마지막으로 비교하는 위치 : 3 - 2 - 1 - 0
		//첫 번째 원소부터 비교해 나간다.
		for (int i = 0; i < size - 1 - phase; i++)
		{
			//정렬조건 : 현재 원소가 다음 원소보다 클때 (오름차순)
			if(arr[i] > arr[i + 1])
			{
				//서로 바꾼다.
				std::swap(arr[i], arr[i + 1]);
			}

		}
	}
}

int main() {


	int arr[5] = { 5, 2, 4, 1, 3 };

	Sort(arr, 5);
	// arr : [ 1, 2, 3, 4, 5 ]

	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}