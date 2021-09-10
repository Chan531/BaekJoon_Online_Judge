#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	int n, k, mt = 100001;
	queue<pair<int, int>> q;
	vector<int> visited(100001, 100001);
	cin >> n >> k;
	q.push(make_pair(n, 0));
	while (!q.empty())
	{
		int cp = q.front().first;
		int ct = q.front().second;
		q.pop();

		if (cp < 0 || cp > 100000 || visited[cp] <= ct)
			continue;

		visited[cp] = ct;

		if (cp == k)
		{
			if (mt > ct)
				mt = ct;
		}

		else if (cp > k)
		{
			if (mt > ct + cp - k)
				mt = ct + cp - k;
		}

		else
		{
			q.push(make_pair(cp - 1, ct + 1));
			if (cp < k)
			{
				q.push(make_pair(cp * 2, ct));
				q.push(make_pair(cp + 1, ct + 1));
			}
		}
	}
	cout << mt;
	return 0;
}