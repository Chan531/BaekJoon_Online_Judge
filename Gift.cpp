#include <iostream>
#include <vector>

using namespace std;

int n, k, ans = 0;
vector<int> cost(101);

void input()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> cost[i];
}

void solution()
{
	for (int i = 1; i < n; i++)
	{
		if (cost[i - 1] - cost[i] >= k)
			ans++;
	}
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
	cout.tie(NULL);

	solve();
	return 0;
}