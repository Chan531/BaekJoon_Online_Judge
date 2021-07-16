#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main(void)
{
	int x, nx;
	deque<pair <int, int>> q;
	vector<int> v(100001);
	int time = 100000;
	int answer = 0;
	cin >> x >> nx;
	q.push_back(make_pair(x, 0));
	while (!q.empty())
	{
		pair <int, int> p = q.front();
		q.pop_front();
		if (p.first > 100000 || p.first < 0)
		{

		}
		else if (v[p.first] == 1)
		{

		}
		else if (p.first == nx)
		{
			v[p.first]++;
			if (time < p.second)
				cout << time;
			else
				cout << p.second;
			answer++;
			break;
		}
		else if (p.first > nx)
		{
			v[p.first]++;
			while (p.first != nx)
			{
				p.first--;
				p.second++;
			}
			if (time > p.second)
				time = p.second;
		}
		else
		{
			v[p.first]++;
			q.push_back(make_pair(p.first + 1, p.second + 1));
			q.push_back(make_pair(p.first - 1, p.second + 1));
			q.push_back(make_pair(p.first * 2, p.second + 1));
		}
	}
	if (answer == 0)
	{
		cout << time;
	}
	return 0;
}