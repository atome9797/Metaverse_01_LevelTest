#pragma once
#include <iostream>
using namespace std;

class Test
{
public:
	int math()
	{
		cout << "���� ����" << endl;

		cout << "1 + 1 = ? " << endl;

		cout << "�Է� : " << endl;
		cout << "1�� 1\t2�� 4\t3�� 2\t4�� 10" << endl;

		math_answer = 3;
		//���� ����
		return math_answer;
	}
	int english()
	{
		cout << "���� ����" << endl;

		cout << "�����ڴ� �����? " << endl;
		cout << "1�� student\t2�� craw\t3�� banana\t4�� scientist" << endl;

		science_answer = 4;
		//���� ����
		return science_answer;
	}
	int science()
	{
		cout << "���� ����" << endl;
		math_answer = 0;

		//���� ����
		return 0;

	}
	int korean()
	{
		cout << "���� ����" << endl;

		math_answer = 0;
		//���� ����
		return 0;
	}




private:
	int math_answer = 0;
	int english_answer = 0;
	int science_answer = 0;
	int korean_answer = 0;
};
