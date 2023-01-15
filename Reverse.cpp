#include <iostream>

using namespace std;

string s;
int a, b;

void input()
{
	cin >> s >> a >> b;
}

void solution()
{
	for (int i = 0; i < s.length(); i++)
	{
		if (i >= a && i < b)
			continue;

		cout << s[i];
	}

	cout << '\n';	
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