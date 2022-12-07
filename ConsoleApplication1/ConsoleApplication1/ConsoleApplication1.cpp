// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <math.h>
#include <climits>
#define collection cin.tie(NULL);ios_base::sync_with_stdio(false);
using namespace std;
long long X[200000], N, length = 1;
bool CheckABS(long long a, long long b)
{
	if (abs(a) < abs(b))
	{
		return true;
	}
	else if (abs(a) == abs(b))
	{
		if (a < b)
		{
			return true;
		}
	}
	return false;
}
void SortHeap(int index)
{
	if (CheckABS(X[index * 2 + 1], X[index * 2]))
	{
		if (CheckABS(X[index * 2 + 1],X[index]) )
		{
			long long tmp = X[index];
			X[index] = X[index * 2 + 1];
			X[index * 2 + 1] = tmp;
			SortHeap(index * 2 + 1);
		}
	}
	else
	{
		if (CheckABS(X[index * 2], X[index]))
		{
			long long tmp = X[index];
			X[index] = X[index * 2];
			X[index * 2] = tmp;
			SortHeap(index * 2);
		}
	}
}
void InsertHeap(int value)
{
	X[length] = value;
	int index = length;
	while (index > 1 && CheckABS(X[index], X[index / 2]))
	{
		long long tmp = X[index];
		X[index] = X[index / 2];
		X[index / 2] = tmp;
		index /= 2;
	}
	length++;

}
int main()
{
	collection;
	cin >> N;
	for (int i = 0; i < 200000; i++)
	{
		X[i] = UINT_MAX;
	}
	for (int i = 0; i < N; i++)
	{
		int command;
		cin >> command;
		if (command != 0)
		{
			InsertHeap(command);
		}
		else
		{
			if (length == 1)
			{
				cout << "0" << '\n';
			}
			else
			{
				cout << X[1] << '\n';
				X[1] = X[length - 1];
				X[length] = UINT_MAX;
				length--;
				SortHeap(1);
			}
		}
	}
}

