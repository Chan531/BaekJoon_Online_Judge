#include <iostream>
#include <vector>

using namespace std;

int n, dis, cost, ans = 0;
vector<pair<int, int>> resort;

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> dis >> cost;
		resort.push_back({ dis, cost });
	}
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		dis = resort[i].first;
		cost = resort[i].second;
		for (int j = 0; j < n; j++)
		{			
			if ((dis > resort[j].first && cost >= resort[j].second) || (cost > resort[j].second && dis >= resort[j].first))
				break;

			if (j == n - 1)
				ans++;
		}
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