#include <iostream>
#include <string>

using namespace std;

string a, b;
char alpha[26];

void input()
{
	getline(cin, a);
	getline(cin, b);
}

void solution()
{
	for (int i = 0; i < b.length(); i++)
		alpha[i] = b[i];

	for (int i = 0; i < a.length(); i++)
	{
		if (isalpha(a[i]))
			cout << alpha[a[i] - 'A'];

		else
			cout << ' ';
	}

	cout << '\n';
}

void solve()
{
	int testcase;
	cin >> testcase;

	cin.ignore();

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