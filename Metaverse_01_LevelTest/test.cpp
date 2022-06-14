#include <iostream>

using namespace std;

int main() 
{
	char ch[] = "asdasd";
	char* ptr = ch;
	char* ptr2 = ptr; 
	//주소의 시작값을 가지므로 ptr이 변하더라도 ptr2의 시작주소는 변하지 않음

	//char & ptr3 = ch; 배열은 레퍼런스 안됨
	int a = 10;
	int& ptr3 = a;
	int& ptr4 = ptr3;

	//이렇게는 사용가능
	int ccc[3] = {1,2,3};
	int	(&ptr10)[3] = ccc;


	ptr4 = 20;

	cout << "레퍼런스 4" << ptr4 << endl;
	cout << "레퍼런스 3" << ptr3 << endl;


	*ptr2 = '9';
	while (*ptr != '\0')
	{
		cout << *ptr << endl;
		ptr++;
	}

	cout << "변화 측정 " << *ptr2 << endl;
	ptr--;
	cout << "변화 측정 " << *ptr << endl;


	return 0;
}