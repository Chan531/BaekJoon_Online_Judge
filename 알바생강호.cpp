#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
long long tip, ans = 0;
vector<long long> cost;

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tip;
		cost.push_back(tip);
	}
}

void solution()
{
	sort(cost.begin(), cost.end(), greater<long long>());

	for (int i = 0; i < n; i++)
	{
		if (cost[i] - i <= 0)
			break;

		ans += cost[i] - i;
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