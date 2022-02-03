#include <iostream>
#include <vector>

using namespace std;

int n, k, s, y, ans = 0;
vector<int> male(7), female(7);

void input()
{
	cin >> n >> k;
	while (n--)
	{
		cin >> s >> y;
		if (s)
			male[y]++;
		else
			female[y]++;
	}
}

void solution()
{
	for (int i = 1; i <= 6; i++)
	{
		if (male[i])
		{
			if (male[i] % k)
				ans += male[i] / k + 1;
			else
				ans += male[i] / k;
		}
		if (female[i])
		{
			if (female[i] % k)
				ans += female[i] / k + 1;
			else
				ans += female[i] / k;
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