#include <iostream>
#include <vector>
#define p pair<int, int>

using namespace std;

int n, ans;
vector<p> v;

void input()
{
	cin >> n;
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		int a, b, c;
		cin >> a;

		if (a)
		{
			cin >> b >> c;
			v.push_back({ b, c });
		}

		if (!v.empty())
		{
			v.back().second--;

			if (!v.back().second)
			{
				ans += v.back().first;
				v.pop_back();
			}
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

	solve();
	return 0;
}