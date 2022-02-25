#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, num, ans = 0;
vector<int> armor;

void input()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		armor.push_back(num);
	}
}

void solution()
{
	sort(armor.begin(), armor.end());
	int start = 0, end = n - 1;
	while (start < end)
	{
		if (armor[start] + armor[end] == m)
		{
			ans++;
			start++;
			end--;
		}

		else if (armor[start] + armor[end] < m)
			start++;

		else
			end--;
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