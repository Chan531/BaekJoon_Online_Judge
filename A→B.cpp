#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	long long a, b, n;
	int count;
	cin >> a >> b;
	queue<pair<long long, int>> q;
	q.push(make_pair(a, 1));
	while (!q.empty())
	{
		n = q.front().first;
		count = q.front().second;
		q.pop();
		if (n > b)
		{

		}
		else if (n == b)
		{
			cout << count;
			return 0;
		}
		else
		{
			q.push(make_pair(n * 2, count + 1));
			q.push(make_pair(n * 10 + 1, count + 1));
		}
	}
	cout << -1;
	return 0;
}