#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
string num[10000];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> num[i];
}

void solution()
{
	string answer = "YES\n";
	sort(num, num + n);

	for (int i = 1; i < n; i++)
	{
		int a = num[i - 1].length();

		if (num[i - 1] == num[i].substr(0, a))
		{
			answer = "NO\n";
			break;
		}
	}

	cout << answer;
}

void solve()
{
	int testcase;
	cin >> testcase;

	while (testcase--)
	{
		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}