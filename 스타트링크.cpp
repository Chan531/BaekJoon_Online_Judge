#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void)
{
	int f, s, g, u, d, cp, cb;
	queue<pair<int, int>> q;
	cin >> f >> s >> g >> u >> d;
	vector<int> visited(f + 1);
	visited[s] = 1;
	q.push(make_pair(s, 0));
	while (!q.empty())
	{
		cp = q.front().first;
		cb = q.front().second;
		q.pop();

		if (cp > f || cp < 0)
			continue;

		if (cp == g)
		{
			cout << cb;
			return 0;
		}

		if (cp + u <= f && !visited[cp + u])
		{
			q.push(make_pair(cp + u, cb + 1));
			visited[cp + u] = 1;
		}

		if (cp - d > 0 && !visited[cp - d])
		{
			q.push(make_pair(cp - d, cb + 1));
			visited[cp - d] = 1;
		}
	}
	cout << "use the stairs";
	return 0;
}