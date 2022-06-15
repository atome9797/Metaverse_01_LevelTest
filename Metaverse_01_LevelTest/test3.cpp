#include <iostream>

using namespace std;
/*

	제어문 
		- 반복문 
		- 조건문
*/
/*
# FizzBuzz
1 . 1에서 100까지 출력한다.
2. 3의 배수는 숫자 대신 Fizz를 출력한다.
3. 5의 배수는 숫자 대신 Buzz를 출력한다.
4. 3과 5의 공배수는 FizzBuzz를 출력한다.
*/
int main()
{

	for (int i = 1; i <= 100; i++)
	{
		if (i % 3 == 0 && i % 5 == 0) {
			cout << "FizzBuzz" << " ";
		}
		else if (i % 3 == 0)
		{
			cout << "Fizz" << " ";
		}
		else if (i % 5 == 0) {
			cout << "Buzz" << " ";
		}
		else
		{
			cout << i << " ";
		}
	}

	//배열
	/*
		10명의 학생들 점수를 받아서 그 반의 평균을 계산하는 프로그램을 작성해보시오.
	*/
	cout << endl;
	int scount = 0;
	cout << "학생수 :";
	cin >> scount;

	int student_score[10] = {0};
	int sum = 0;
	for (int i = 0; i < scount; i++)
	{
		cin >> student_score[i];
		sum += student_score[i];
	}

	cout << "반 평균 : " << sum / scount << endl;

	
	/*
		탈출게임
		1. 플레이어는 p로 표현한다.
		2. 맵은 10x10으로 표현한다.
		3. 플레이어의 초기 위치는 (0,0)이다.
		4. 탈출지점은 E로 표현한다.
		5. 탈출지점의 위치는 (8,8)이다.
		6. 키 입력은 w /a /s /d이다


		###########
		###########
		###########
		###########
		###########
		###########
		###########
		###########
		###########
		###########

		이동할 방향키를 입력해 주세요.
	*/


	return 0;
}