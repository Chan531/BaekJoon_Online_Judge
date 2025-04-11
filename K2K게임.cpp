#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> ans;

void input()
{
	cin >> n >> k;
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		if (i % 10 == k % 10 || i % 10 == k * 2 % 10) continue;
		ans.push_back(i);
	}

	cout << ans.size() << '\n';
	for (auto i : ans) cout << i << ' ';
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