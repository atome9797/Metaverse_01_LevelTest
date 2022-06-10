#include <iostream>
int main()
{
	int num = 3;
	int count = 0;
	
	printf("1\n");

	while (1) {
		
		printf("%d\n",num);

		num = num * 3;

		if (num > 1000) {
			break;
		}


	}

	return 0;
}