#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, cnt[50001];
vector<int> snum;
// Á¦°ö¼ö ¸ðÀ½

void input()
{
	cin >> n;
}

void solution()
{
	for (int i = 1; i <= n; i++)
		cnt[i] = 1e9;

	for (int i = 1; ; i++)
	{
		if (i * i > 50000)
			break;

		snum.push_back(i * i);
		cnt[i * i] = 1;
	}

	int idx = -1;

	for (int i = 1; i <= n; i++)
	{
		if (cnt[i] == 1)
			idx++;

		for (int j = 0; j <= idx; j++)
			cnt[i] = min(cnt[i], cnt[snum[j]] + cnt[i - snum[j]]);
	}

	cout << cnt[n];
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