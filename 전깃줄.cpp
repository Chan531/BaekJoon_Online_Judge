#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, a, b;
vector<pair<int, int>> wire;
vector<int> lis(101, 1);

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		wire.push_back({ a,b });
	}
}

void solution()
{
	sort(wire.begin(), wire.end());
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (wire[i].second > wire[j].second)
				lis[i] = max(lis[i], lis[j] + 1);
		}
	}
	cout << n - *max_element(lis.begin(), lis.end());
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