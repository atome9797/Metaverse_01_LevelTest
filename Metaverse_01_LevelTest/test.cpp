#include <iostream>

using namespace std;

int main() 
{
	char ch[] = "asdasd";
	char* ptr = ch;
	char* ptr2 = ptr; 
	//�ּ��� ���۰��� �����Ƿ� ptr�� ���ϴ��� ptr2�� �����ּҴ� ������ ����

	//char & ptr3 = ch; �迭�� ���۷��� �ȵ�
	int a = 10;
	int& ptr3 = a;
	int& ptr4 = ptr3;

	//�̷��Դ� ��밡��
	int ccc[3] = {1,2,3};
	int	(&ptr10)[3] = ccc;


	ptr4 = 20;

	cout << "���۷��� 4" << ptr4 << endl;
	cout << "���۷��� 3" << ptr3 << endl;


	*ptr2 = '9';
	while (*ptr != '\0')
	{
		cout << *ptr << endl;
		ptr++;
	}

	cout << "��ȭ ���� " << *ptr2 << endl;
	ptr--;
	cout << "��ȭ ���� " << *ptr << endl;


	return 0;
}