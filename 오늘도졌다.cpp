#include <iostream>

using namespace std;

int a[9], b[9], ascore, bscore;
string ans = "Yes";

void input()
{
	for (int i = 0; i < 9; i++)
		cin >> a[i];

	for (int i = 0; i < 9; i++)
		cin >> b[i];
}

void solution()
{
	for (int i = 0; i < 9; i++)
	{
		ascore += a[i];

		if (ascore > bscore)
			break;

		bscore += b[i];

		if (i == 8)
			ans = "No";
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