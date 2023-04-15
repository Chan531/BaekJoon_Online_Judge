#include <iostream>
#include <vector>
#include <algorithm>
#define N 901

using namespace std;

int n, k, f;
vector<int> mate[N], mem;
bool rel[N][N], check[N];

void input()
{
	cin >> k >> n >> f;

	while (f--)
	{
		int a, b;
		cin >> a >> b;

		mate[a].push_back(b);
		mate[b].push_back(a);
		rel[a][b] = 1;
		rel[b][a] = 1;
	}
}

bool all_friend(int node)
{
	for (auto i : mem)
		if (!rel[i][node])
			return false;

	return true;
}

void backtrack(int idx, int cnt)
{
	if (cnt == k)
	{
		for (auto i : mem)
			cout << i << '\n';

		exit(0);
	}

	for (int i = idx; i < mate[mem[0]].size(); i++)
	{
		int next = mate[mem[0]][i];

		if (!all_friend(next) || check[next] || mate[next].size() < (k - 1))
			continue;

		check[next] = 1;
		mem.push_back(next);
		backtrack(i + 1, cnt + 1);
		mem.pop_back();
		check[next] = 0;
	}
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		if (mate[i].size() < (k - 1))
			continue;

		sort(mate[i].begin(), mate[i].end());
		check[i] = 1;
		mem.push_back(i);
		backtrack(0, 1);
		mem.pop_back();
	}

	cout << -1;
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