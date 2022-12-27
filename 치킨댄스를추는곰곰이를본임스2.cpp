#include <iostream>
#include <string>

using namespace std;

int n;

void input()
{
	cin >> n;
}

void solution()
{
	int ans = 0;

	while (n--)
	{
		string day;
		cin >> day;

		int m = stoi(day.substr(2, day.length() - 2));

		if (m <= 90)
			ans++;
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