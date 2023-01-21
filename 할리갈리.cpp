#include <iostream>

using namespace std;

int n, arr[4];

void input()
{
	cin >> n;
}

int check(string s)
{
	if (s == "STRAWBERRY")
		return 0;

	if (s == "BANANA")
		return 1;

	if (s == "LIME")
		return 2;

	return 3;
}

void solution()
{
	while (n--)
	{
		string s;
		int x;

		cin >> s >> x;

		arr[check(s)] += x;
	}

	for (int i = 0; i < 4; i++)
	{
		if (arr[i] == 5)
		{
			cout << "YES";
			return;
		}
	}

	cout << "NO";
	return;
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