#include <iostream>
int main()
{

	for (int i = 0; i < 10; i++)
	{
		for (int j = 10; j > 0; j--)
		{
			if (i < j) {
				printf(" ");
			}
			else {
				printf("*");
			}
		}

		for (int j = 0; j < 10; j++)
		{
			if (i < j) {
				printf(" ");
			}
			else {
				printf("*");
			}
		}

		printf("\n");

		
	}



	return 0;
}