#include <iostream>
#include <vector>
#include <algorithm>
#define p pair<int, int>
#define M 101
#define N 10101

using namespace std;

int m, n, ans, arr[M][N];
vector<int> v[M];

void input()
{
	cin >> m >> n;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
}

void solution()
{
	for (int i = 0; i < m; i++)
	{
		vector<int> w;
		vector<p> temp;

		for (int j = 0; j < n; j++)
		{
			w.push_back(arr[i][j]);
			temp.push_back({ arr[i][j], j });
		}

		sort(w.begin(), w.end());
		w.erase(unique(w.begin(), w.end()), w.end());
		sort(temp.begin(), temp.end());
		int idx = 0;
		v[i].resize(n);

		for (int j = 0; j < n; j++)
		{
			int val = temp[j].first;
			int valIdx = temp[j].second;
			if (val != w[idx]) idx++;
			v[i][valIdx] = idx;
		}
	}

	for (int i = 0; i < m; i++)
		for (int j = i + 1; j < m; j++)
			if (v[i] == v[j])
				ans++;

	cout << ans;
}

void solve()
{
	input();
	solution();
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}