#include <iostream>

void sortArray(int* arr, int n)
{
	
	//거품정렬 => 생활코딩거기서 풀어봄
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[j - 1] > arr[j])
			{
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
	}
}

int main()
{
	int arr[5] = { 5,2,4,1,3 };

	sortArray(arr, 5);

	for (int i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}