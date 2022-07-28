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

		//2�� �����ͷ� ������ �޸� ����ȭ�� �Ͼ �޸� �������� �߻��Ҽ� �ִ�. => �׷��⿡ 1���� �迭�� ����Ѵ�.
		//int** arr = new int* [size];

		r = 0;
		c = 0;
		footstep = 1;
		direction = DIR_RIGHT;

		//2. ������ �迭 ����

		for (int i = 0; i < size * size; i++)
		{

			//2-2. ���ڱ��� �����.
			ground[r * size + c] = footstep;
			footstep++;

			//2-3. �̵��� ��ġ�� ����Ѵ�. 
			static const int dr[] = { 0 , 1 , 0  ,-1 }; //������ �� Ż�� +- ��ȭ �ִ� ���� �ѹ��� �޾�ǥ����
			static const int dc[] = { 1 , 0 , -1 , 0 };

			int nr = r + dr[(int)direction]; //r�� ���� ��ȭ�� (��ǥ����)
			int nc = c + dc[(int)direction]; //c�� ���� ��ȭ�� (��ǥ����)


			//2-4. �̵��� �������� �Ǻ��Ѵ�. 

			//2-4-1. ���� ������� => r,c�� ��ġ�� [0,size)							�����Ⱚ �������
			if (nr < 0 || nr >= size || nc < 0 || nc >= size || ground[nr * size + nc] != NOT_VISITED)
			{
				//2-5. �̵��� �Ұ����ϹǷ� ���� ��ȯ�� �Ѵ�.
				direction = (Direction)((direction + 1) % DIR_MAX);

				//2-6. ��ġ���� �ٽ� ����Ѵ�. => ���� dr�� ������ ���� ������ r + dr�� �ٽ� �������ν� ���� ����Ҽ� ����
				nr = r + dr[(int)direction];
				nc = c + dc[(int)direction];
			}

			//2-7. �̵��Ѵ�.
			r = nr; //nr�� nc�� +- ����� ��ǥ���� ������.
			c = nc;

		}

	}

private:
	int r = 0;
	int c = 0;
	int footstep = 1;
	Direction direction = DIR_RIGHT;
};
