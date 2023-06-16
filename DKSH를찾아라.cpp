#include <iostream>

using namespace std;

int n;
long long d, k, s, h;
string str;

void input()
{
	cin >> n >> str;
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		if (str[i] == 'D')
			d++;

		else if (str[i] == 'K')
			k += d;

		else if (str[i] == 'S')
			s += k;

		else if (str[i] == 'H')
			h += s;
	}

	cout << h;
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