#include <iostream>

using namespace std;

string s;
int n, ans;

void input()
{
	for (int i = 0; i < 4; i++)
	{
		cin >> s >> n;

		if (s == "Es")
			ans += n * 21;

		else
			ans += n * 17;
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

	solve();
	return 0;
}