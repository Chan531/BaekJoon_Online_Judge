#include <iostream>

using namespace std;

int n, ans2;
string ans1;

void input()
{
	cin >> n;
}

void solution()
{
	// 1
	n *= 3;

	// 2
	if (n % 2)
	{
		n++;
		ans1 = "odd";
	}

	else
		ans1 = "even";

	n /= 2;

	// 3
	n *= 3;

	// 4
	ans2 = n / 9;
}

void solve()
{
	for (int i = 1; ; i++)
	{
		input();
		if (!n) break;
		solution();
		cout << i << ". " << ans1 << ' ' << ans2 << '\n';
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}