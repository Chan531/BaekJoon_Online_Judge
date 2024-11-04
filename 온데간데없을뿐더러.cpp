#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n;
string a, b;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		a += s;
	}

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		b += s;
	}
}

void solution()
{
	if (a.length() < b.length())
		cout << a;

	else if (a.length() > b.length())
		cout << b;

	else
	{
		for (int i = 0; i < a.length(); i++)
		{
			if (a[i] < b[i])
			{
				cout << a;
				break;
			}

			else if (a[i] > b[i])
			{
				cout << b;
				break;
			}

			if (i == a.length() - 1) cout << a;
		}
	}
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