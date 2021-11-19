#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n, k, d, x, y, w;
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		vector<int> build(n + 1), cnt(n + 1), mintime(n + 1);
		vector<vector<int>> seq(n + 1);
		queue<int> q;
		for (int i = 1; i <= n; i++)
		{
			cin >> d;
			build[i] = d;
		}
		while (k--)
		{
			cin >> x >> y;
			seq[x].push_back(y);
			cnt[y]++;
		}
		for (int i = 1; i <= n; i++)
		{
			if (!cnt[i])
			{
				mintime[i] = build[i];
				q.push(i);
			}
		}
		cin >> w;
		while (!q.empty())
		{
			int pos = q.front();
			q.pop();

			for (int i = 0; i < seq[pos].size(); i++)
			{
				int npos = seq[pos][i];
				mintime[npos] = max(mintime[npos], mintime[pos] + build[npos]);

				if (--cnt[npos] == 0)
					q.push(npos);	
			}
		}
		cout << mintime[w] << '\n';
	}
	return 0;
}