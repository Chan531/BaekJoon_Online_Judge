#include <iostream>
#include <cmath>

using namespace std;

int n;
string ans;

void input()
{
	cin >> n;
}

void solution()
{
	int temp = n;
	int idx = 1;

	while (temp > pow(2, idx))
		temp -= pow(2, idx++);

	while (n != 0)
	{
		int temp = n - pow(2, idx) + 2;
		int tar = pow(2, idx - 1);

		if (temp <= tar)
		{
			ans += "4";
			n -= pow(2, idx - 1);
		}

		else
		{
			ans += "7";
			n -= pow(2, idx);
		}

		idx--;
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