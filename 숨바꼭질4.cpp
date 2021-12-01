#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, t, pos;
	queue<pair<int, int>> q;
	vector<int> visited(100001), ans;
	vector<pair<int, int>> back(100001, { -1, 100001 });
	cin >> n >> k;
	q.push(make_pair(n, 0));
	while (!q.empty())
	{
		pos = q.front().first;
		t = q.front().second;
		q.pop();

		if (visited[pos])
			continue;

		visited[pos] = 1;

		if (pos == k)
		{
			cout << t << '\n';
			while (1)
			{
				ans.push_back(pos);
				if (pos == n)
					break;
				pos = back[pos].first;
			}
		}

		if (pos + 1 <= 100000)
		{
			q.push(make_pair(pos + 1, t + 1));
			if (back[pos + 1].second > t)
			{
				back[pos + 1].first = pos;
				back[pos + 1].second = t;
			}
		}
		if (pos - 1 >= 0)
		{
			q.push(make_pair(pos - 1, t + 1));
			if (back[pos - 1].second > t)
			{
				back[pos - 1].first = pos;
				back[pos - 1].second = t;
			}
		}
		if (pos * 2 <= 100000)
		{
			q.push(make_pair(pos * 2, t + 1));
			if (back[pos * 2].second > t)
			{
				back[pos * 2].first = pos;
				back[pos * 2].second = t;
			}
		}
	}
	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i] << ' ';
	return 0;
}