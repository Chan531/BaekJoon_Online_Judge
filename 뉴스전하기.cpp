#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> sub[50];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;

		if (i == 0)
			continue;

		sub[m].push_back(i);
	}
}

int dfs(int idx)
{
	if (!sub[idx].size())
		return 0;

	vector<int> cnt;

	for (int i = 0; i < sub[idx].size(); i++)
		cnt.push_back(dfs(sub[idx][i]));

	sort(cnt.begin(), cnt.end(), greater<>());

	int ans = 0;

	for (int i = 0; i < cnt.size(); i++)
		ans = max(ans, cnt[i] + i);

	return ans + 1;
}

void solution()
{
	cout << dfs(0);
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
	cout.tie(NULL);

	solve();
	return 0;
}