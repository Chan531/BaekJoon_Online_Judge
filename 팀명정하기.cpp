#include <iostream>
#include <algorithm>

using namespace std;

int year[3];
pair<int, string> info[3];

void input()
{
	for (int i = 0; i < 3; i++)
		cin >> info[i].first >> year[i] >> info[i].second;
}

void solution()
{
	sort(year, year + 3);
	sort(info, info + 3, greater<pair<int, string>>());

	for (int i = 0; i < 3; i++)
		cout << year[i] % 100;

	cout << '\n';

	for (int i = 0; i < 3; i++)
		cout << info[i].second[0];
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