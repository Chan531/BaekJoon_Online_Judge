#include <iostream>

using namespace std;

int n, dif = 5;
string ans;

void input()
{
	cin >> n;
}

void solution()
{
	while (n--)
	{
		string p;
		int d;

		cin >> p >> d;

		if (d < dif)
		{
			ans = p;
			dif = d;
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