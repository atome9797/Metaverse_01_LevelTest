#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
void loto(int max, int count)
{
	srand(time(NULL));

	int lotoNum[10000];

	//10개 출력함
	for (int i = 0; i < count; i++)
	{
		int randNum = rand() % max + 1;

		
		int search = 0;
		while (1) 
		{
			int search = 0;
			for (int j = 0; j < i; j++)
			{
				if (lotoNum[j] == randNum)
				{
					search = 1;
					randNum = rand() % max + 1;
				}
			}

			if (search == 0) {
				break;
			}
		}


		lotoNum[i] = randNum;
	}


	for (int k = 0; k < count; k++)
	{
		printf("%d ", lotoNum[k]);
	}

}

int main()
{

	int max = 0;
	int count = 0;

	scanf("%d %d", &max, &count);

	loto(max, count);

	return 0;
}