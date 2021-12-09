#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	int n, m;
	vector<int> buildtime(501), ans(501), fbuild(501);
	vector<vector<int>> nbuild(501);
	queue<pair<int, int>> q;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; ; j++)
		{
			cin >> m;
			if (m == -1)
				break;
			if (j == 0)
				buildtime[i] = m;
			else
			{
				fbuild[i]++;
				nbuild[m].push_back(i);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (fbuild[i] == 0)
			q.push(make_pair(i, buildtime[i]));
	}
	while (!q.empty())
	{
		int pos = q.front().first;
		int btime = q.front().second;
		q.pop();

		ans[pos] = max(ans[pos], btime);

		for (int i = 0; i < nbuild[pos].size(); i++)
		{
			int npos = nbuild[pos][i];
			fbuild[npos]--;
			ans[npos] = max(ans[npos], btime);

			if (fbuild[npos] == 0)
				q.push(make_pair(npos, ans[npos] + buildtime[npos]));
		}
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << '\n';
	return 0;
}