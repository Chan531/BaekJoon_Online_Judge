#include <iostream>
#include <queue>
#include <list>

using namespace std;

int main()
{
	int n, count = 0;
	int num = 0;
	list<int> l;
	list<int>::iterator lt;
	queue<int> q;
	cin >> n >> count;
	for (int i = 1; i <= n; i++)
	{
		l.push_back(i);
	}
	for (int i = 0; i < count; i++)
	{
		cin >> num;
		q.push(num);
	}
	count = 0;
	while (!q.empty())
	{
		int move = 0;
		lt = l.begin();
		while (*lt != q.front())
		{
			lt++;
			move++;
		}
		if (move == 0)
		{
			l.pop_front();
		}
		else if (move <= n - move)
		{
			while (move != 0)
			{
				int a = l.front();
				l.pop_front();
				l.push_back(a);
				count++;
				move--;
			}
			l.pop_front();
		}
		else
		{
			while (move != n)
			{
				int a = l.back();
				l.pop_back();
				l.push_front(a);
				count++;
				move++;
			}
			l.pop_front();
		}
		q.pop();
		n--;
	}
	cout << count;
}