#include <iostream>
#include <vector>

using namespace std;

void dfs(int n, vector<int> &v, vector<int> &w, vector<int>& visited)
{
	if (visited[n])
	{
		int m = n;
		n = v[n];
		w[m] = 1;
		while (m != n)
		{
			w[n] = 1;
			n = v[n];
		}
		return;
	}

	if (w[n] || w[n] == -1)
		return;

	visited[n] = 1;
	w[n] = -1;

	dfs(v[n], v, w, visited);
	visited[n] = 0;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n, m, cnt;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cnt = 0;
		cin >> n;
		vector<int> visited(n + 1), v(n + 1), w(n + 1);
		for (int j = 1; j <= n; j++)
		{
			cin >> m;
			v[j] = m;
			if (j == m)
				w[j] = 1;
		}
		for (int j = 1; j <= n; j++)
		{
			if (w[j] == 0)
			{
				dfs(j, v, w, visited);
			}
		}
		for (int j = 1; j <= n; j++)
		{
			if (w[j] == -1)
				cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}