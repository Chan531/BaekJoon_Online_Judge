#include <iostream>

using namespace std;

string ans = "JAH";

void input()
{

}

void solution()
{
	for (int i = 1; i <= 3; i++)
	{
		int a;
		cin >> a;

		if (i == 1 && (a == 1 || a == 3)) continue;
		else if (i == 2 && (a == 6 || a == 8)) continue;
		else if (i == 3 && (a == 2 || a == 5)) continue;
		ans = "EI";
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