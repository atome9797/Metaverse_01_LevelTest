#include <iostream>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
int main()
{

	int a = 10;
	int b = 20;

	swap(&a, &b); //������
	printf("%d %d\n", a, b);
	swap(a, b); //���۷���
	printf("%d %d\n", a, b);


	return 0;
}