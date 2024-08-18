#include <iostream>

using namespace std;

int t, n;

void input()
{
	cin >> t >> n;
}

void solution()
{
	while (n--)
	{
		int a;
		cin >> a;
		t -= a;
	}

	if (t <= 0)
		cout << "Padaeng_i Happy";
	else
		cout << "Padaeng_i Cry";
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