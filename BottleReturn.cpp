#include <iostream>

using namespace std;

int num, ans;

void input()
{
	for (int i = 0; i < 6; i++)
	{
		cin >> num;
		ans += num * 5;
	}
}

void solution()
{
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