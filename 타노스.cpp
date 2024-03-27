#include <iostream>
#define N 505

using namespace std;

int o, z;
string s;
bool check[N];

void input()
{
	cin >> s;
}

void solution()
{
	for (int i = 0; i < s.length(); i++)
		s[i] == '0' ? z++ : o++;

	z /= 2;
	o /= 2;

	for (int i = 0; i < s.length(); i++)
	{
		if (!o)
			break;

		if (s[i] == '1')
		{
			check[i] = 1;
			o--;
		}
	}

	for (int i = s.length() - 1; i >= 0; i--)
	{
		if (!z)
			break;

		if (s[i] == '0')
		{
			check[i] = 1;
			z--;
		}
	}

	for (int i = 0; i < s.length(); i++)
		if (!check[i])
			cout << s[i];
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