#pragma once
#include <iostream>

using namespace std;

class Snail
{
	static const int NOT_VISITED = 0;
	enum Direction { DIR_RIGHT, DIR_DOWN, DIR_LEFT, DIR_UP, DIR_MAX };
public:


	void Make(int * ground , int size)
	{

		//2중 포인터로 받으면 메모리 단편화가 일어나 메모리 공간낭비가 발생할수 있다. => 그렇기에 1차원 배열만 사용한다.
		//int** arr = new int* [size];

		r = 0;
		c = 0;
		footstep = 1;
		direction = DIR_RIGHT;

		//2. 달팽이 배열 세팅

		for (int i = 0; i < size * size; i++)
		{

			//2-2. 발자국을 남긴다.
			ground[r * size + c] = footstep;
			footstep++;

			//2-3. 이동할 위치를 계산한다. 
			static const int dr[] = { 0 , 1 , 0  ,-1 }; //일일히 벽 탈때 +- 변화 주던 것을 한번에 받아표시함
			static const int dc[] = { 1 , 0 , -1 , 0 };

			int nr = r + dr[(int)direction]; //r에 대한 변화량 (좌표가됨)
			int nc = c + dc[(int)direction]; //c에 대한 변화량 (좌표가됨)


			//2-4. 이동이 가능한지 판별한다. 

			//2-4-1. 벽에 닿았을때 => r,c의 위치가 [0,size)							쓰레기값 들어있음
			if (nr < 0 || nr >= size || nc < 0 || nc >= size || ground[nr * size + nc] != NOT_VISITED)
			{
				//2-5. 이동이 불가능하므로 방향 전환을 한다.
				direction = (Direction)((direction + 1) % DIR_MAX);

				//2-6. 위치값을 다시 계산한다. => 이전 dr은 쓰레기 값이 들어갔지만 r + dr을 다시 해줌으로써 값을 출력할수 있음
				nr = r + dr[(int)direction];
				nc = c + dc[(int)direction];
			}

			//2-7. 이동한다.
			r = nr; //nr과 nc는 +- 연산된 좌표값을 가진다.
			c = nc;

		}

	}

private:
	int r = 0;
	int c = 0;
	int footstep = 1;
	Direction direction = DIR_RIGHT;
};
