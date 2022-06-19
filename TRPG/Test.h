#pragma once
#include <iostream>
using namespace std;

class Test
{
public:
	int math()
	{
		cout << "수학 문제" << endl;

		cout << "1 + 1 = ? " << endl;

		cout << "입력 : " << endl;
		cout << "1번 1\t2번 4\t3번 2\t4번 10" << endl;

		math_answer = 3;
		//정답 리턴
		return math_answer;
	}
	int english()
	{
		cout << "영어 문제" << endl;
		math_answer = 0;
		//정답 리턴
		return 0;
	}
	int science()
	{
		cout << "과학 문제" << endl;
		math_answer = 0;

		//정답 리턴
		return 0;

	}
	int korean()
	{
		cout << "국어 문제" << endl;

		math_answer = 0;
		//정답 리턴
		return 0;
	}




private:
	int math_answer = 0;
	int english_answer = 0;
	int science_answer = 0;
	int korean_answer = 0;
};
