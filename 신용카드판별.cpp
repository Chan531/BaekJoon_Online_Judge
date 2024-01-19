#include <iostream>
#define ll long long

using namespace std;

string n, m;
int k;

void input()
{
	cin >> n;
}

void solution()
{
	for (int i = 0; i < 16; i++)
	{
		if (i % 2)
		{
			m += n[i];
			continue;
		}

		k = (n[i] - '0') * 2;

		if (k >= 10)
			k -= 9;

		m += (k + '0');
	}

	k = 0;

	for (int i = 0; i < 16; i++)
		k += (m[i] - '0');

	k % 10 ? cout << "F\n" : cout << "T\n";
	k = 0;
	m = "";
}

void solve()
{
	int tc;
	cin >> tc;

	while (tc--)
	{
		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}