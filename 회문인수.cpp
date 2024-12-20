#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int ans, n;

void input()
{
	cin >> n;
}

bool cal(int m, int n)
{
	int k = 0;

	while (m >= pow(n, k)) k++;

	vector<int> v;

	for (int i = k - 1; i >= 0; i--)
	{
		int t = pow(n, i);

		if (t > m)
		{
			v.push_back(0);
			continue;
		}

		v.push_back(m / t);
		m -= (m / t) * t;
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] != v.back()) return 0;
		v.pop_back();
	}

	return 1;
}

void solution()
{
	while (n--)
	{
		int m;
		cin >> m;
		ans = 0;

		for (int i = 2; i <= 64; i++)
		{
			if (cal(m, i))
			{
				ans = 1;
				break;
			}
		}

		cout << ans << '\n';
	}
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